/* 
 Scrivere un programma che:
 - Richieda di effettuare un'operazione di addizione, sottrazione, moltiplicazione o divisione tra due interi
 - A seconda dell'operazione scelta, invochi una funzione che fornisca il risultato corretto
 - La selezione della funzione avvenga senza costrutti if, switch, etc.
 */

#include <iostream>

using namespace std;

int somma(int a, int b) {
	cout << "a + b = " << a << " + " << b << " = ";
	return a + b;
}

int sottrai(int a, int b) {
	cout << "a - b = " << a << " - " << b << " = ";
	return a - b;
}

int moltiplica(int a, int b) {
	cout << "a * b = " << a << " * " << b << " = ";
	return a * b;
}

int dividi(int a, int b) {
	cout << "a / b = " << a << " / " << b << " = ";
	return a / b;
}

int main() {
	int a, b, scelta = 0;
	int (*funz[4])(int z, int k) = {somma, sottrai, moltiplica, dividi};

	while (scelta < 1 || scelta > 5) {
		cout << "\t1 Addizione\n";
		cout << "\t2 Sottrazione\n";
		cout << "\t3 Moltiplicazione\n";
		cout << "\t4 Divisione intera\n";
		cout << "\t5 Esci\n";
		cout << "Scelta: ";
		cin >> scelta;
	}

	if (scelta == 5)
		return 0;

	cout << "Inserisci due interi: " << endl;
	cin >> a >> b;
	cout << funz[scelta - 1](a, b) << endl;
	return 0;
}
