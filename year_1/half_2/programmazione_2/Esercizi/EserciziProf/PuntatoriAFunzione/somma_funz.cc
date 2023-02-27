/*
 Implementare un programma che implementa una funzione
 generale che calcoli la somma dei primi n valori per
 una data funzione f: f(1) + f(2) + f(3) + .... + f(n)
 */

#include <iostream>

using namespace std;

int quadrato(int k) {
	return k * k;
}

int cubo(int k) {
	return k * k * k;
}

int somma(int n, int (*pf)(int)) {
	int i, sum = 0;
	for (i = 1; i <= n; i++) {
		sum += pf(i);
	}
	return sum;
}

int main() {
	cout << "Somma dei primi 5 quadrati: " << somma(5, quadrato) << endl;
	cout << "Somma dei primi 5 cubi: " << somma(5, cubo) << endl;
}
