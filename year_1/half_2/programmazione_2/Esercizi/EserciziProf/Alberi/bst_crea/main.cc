/*
 * main.cc
 *
 *  Created on: 21 mag 2018
 *      Author: federica
 */


#define DEBUG

#include <iostream>
using namespace std;

#include "tipo.h"
#include "bst.h"



int main(){
	bst t=NULL;
	bool risp;
	int k;
	char i[30];

	do {
		cout << "Inserisci valore di chiave (intero): " << endl;
	       cin >> k;
	       cout << "Inserisci valore informativo (stringa): " << endl;
	       cin >> i;
	       bnode* b=bst_newNode(k,i);
	       cout<<"Nodo creato:"<<b<<get_key(b)<<get_value(b)<<endl;
	       bst_insert(t,b);
	       cout<<"Per terminare digitare 0 altrimenti altro valore: ";
	       cin>>risp;
	    }
	while(risp);

}
