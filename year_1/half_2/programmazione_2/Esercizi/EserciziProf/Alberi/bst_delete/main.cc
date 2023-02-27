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
	if(b==NULL)
		return;
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
	int risp;
	int k;
	char i[30];
	bnode* b;

	do {cout<<"MENU:"<<endl;
		cout<<"1: inserimento di un nodo"<<endl;
		cout<<"2: cancellazione di un nodo"<<endl;
		cout<<"3: stampa del BST"<<endl;
		cout<<"4: ricerca di una chiave"<<endl;
		cout<<"5: uscita"<<endl;
		cin>>risp;
		switch(risp){
		case 1:
		cout << "Inserisci valore di chiave (intero): " << endl;
	       cin >> k;
	       cout << "Inserisci valore informativo (stringa): " << endl;
	       cin >> i;
	       b=bst_newNode(k,i);
	       cout<<"Nodo creato:"<<b<<get_key(b)<<get_value(b)<<endl;
	       bst_insert(t,b);
	    break;
		case 3: print_BST(t); break;
		case 4: cout << "Inserisci valore di chiave da cercare: " << endl;
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
	       break;
		case 2: cout << "Inserisci valore di chiave da cancellare: " << endl;
	       cin >> k;
	       if((b=bst_search(t,k))!=NULL){
	    	   bst_delete(t,b);
	    	   cout<<"Nodo cancellato!"<<endl;}
	       else
	    	   cout<<"Valore di chiave non trovato!!"<<endl;
	       break;
	    }
	}while(risp!=5);

}
