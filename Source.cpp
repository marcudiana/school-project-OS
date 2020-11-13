/*	Se considera un vector de N numere reale citite dintr-un fisier. Realizati o aplicatie grafica in care, folosind 2 thread-uri, 
sa se determine elemntul maxim din subvectorul format din termenii de rang impar ai vectorului initial si 
elemntul minim din subvectorul format din termenii de rang par ai vectorului intial, precum si rangurile pe care apar aceste elemente in vector.
	Interfata grafica trebuie sa contina urmatoarele elemente grafice :
	- casete de editare pentru citirea lui N si afisarea vectorului
	- casete de editare pentru afisarea subvectorilor de rang par si impar
	- casete de editare pentru afisarea elementului minim, respectiv pozitia acestuia
	- casete de editare pentru afisarea elementului maxim, respectiv pozitia acestuia
	- un buton pentru calcul.
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <thread>
using namespace std;

void calculeazaMinim(vector<int> nrRangPar) {
	cout << endl;
	int min = 999999;

	for (int i = 0; i < size(nrRangPar); i++) {
		if (nrRangPar[i] < min) {
			min = nrRangPar[i];
		}

	}
	cout << "Minimul este: " << min << endl;

}

void calculeazaMaxim(vector<int> nrRangImpar) {
	cout << endl;
	int max = 0;
	for (int i = 0; i < size(nrRangImpar); i++) {
		if (nrRangImpar[i] > max) {
			max = nrRangImpar[i];
		}

	}
	cout << "Maximul este: " << max << endl;

}

int main() {

	vector<int> x;
	vector<int> nrRangPar;
	vector<int> nrRangImpar;
	int number;

	ifstream file;
	file.open("C:\\Vector.txt");

	while (file >> number) {
		// Output the text from the file
		x.push_back(number);
	}
	file.close();

	for (int i = 0; i < size(x); i++) {
		if (i % 2 != 0) {
			nrRangPar.push_back(x[i]);
		}
	}
	cout << "Subvector_De_Rang_Par = ";
	for (auto i = nrRangPar.begin(); i < nrRangPar.end(); i++)
	{
		cout << *i << " ";
	}

	cout << endl;

	for (int i = 0; i < size(x); i++) {
		if (i % 2 == 0) {
			nrRangImpar.push_back(x[i]);
		}

	}
	cout << "Subvector_De_Rang_Impar = ";
	for (auto i = nrRangImpar.begin(); i < nrRangImpar.end(); i++) // "auto" se foloseste cand nu se cunoaste tipul de variabila 
	{
		cout << *i << " ";
	}

	thread primulThread (calculeazaMinim, nrRangPar);
	thread alDoileaThread (calculeazaMaxim, nrRangImpar);

	primulThread.join();
	alDoileaThread.join();


}

