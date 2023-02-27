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

void print_BST(bst b){
	if(get_left(b)!=NULL)
		print_BST(get_left(b));
	print_key(get_key(b));
	cout<<"  ";
	print(get_value(b));
	cout<<endl;
	if(get_right(b)!=NULL)
	print_BST(get_right(b));

}

int main(){
	bst t=NULL;
	bool risp;
	int k;
	char i[30];
	bnode* b;

	do {
		cout << "Inserisci valore di chiave (intero): " << endl;
	       cin >> k;
	       cout << "Inserisci valore informativo (stringa): " << endl;
	       cin >> i;
	       b=bst_newNode(k,i);
	       cout<<"Nodo creato:"<<b<<get_key(b)<<get_value(b)<<endl;
	       bst_insert(t,b);
	       cout<<"Per terminare digitare 0 altrimenti 1: ";
	       cin>>risp;
	    }
	while(risp);
	print_BST(t);
	do {
			cout << "Inserisci valore di chiave da cercare: " << endl;
		       cin >> k;
		       if((b=bst_search(t,k))!=NULL){
		    	   cout<<"Nodo trovato: ";
		    	   print_key(get_key(b));
		    	   	cout<<"  ";
		    	   	print(get_value(b));
		    	   	cout<<endl;
		       }
		       else
		    	   cout<<"Nodo non trovato!!";
		       cout<<"Per terminare digitare 0 altrimenti 1: ";
		      	       cin>>risp;
		    }
		while(risp);

}
