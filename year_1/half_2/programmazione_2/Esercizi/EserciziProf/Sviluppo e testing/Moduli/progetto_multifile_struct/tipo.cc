/*
  Scrivere un programma per la gestione di liste doppie.
  Il programma presenta un menù all'utente che può
  - creare una lista di n valori (volendo ordinata)
  - cancellare tutti tutti gli elementi contenente un valore dato dalla lista
  - stampare la lista
  - cercare valori nella lista
  Se la lista è ordinata la ricerca deve richiamare ord_search() altrimenti search().
*/

#include <iostream>
#include <cstring>

using namespace std ;

#include "tipo.h"




/*******************************/
/* DEFINIZIONE MODULO "liste-tipo" */
/*******************************/

int compare(tipo_inf s1,tipo_inf s2){
	if(strcmp(s1.sito_web,s2.sito_web)==0 && (s2.accessi==-1||s1.accessi==-1||s1.accessi==s2.accessi))
		return 0;
	return (s2.accessi-s1.accessi);
}

void copy(tipo_inf& dest, tipo_inf source){
	dest=source;
}

void print(tipo_inf inf){
	cout<<"sito web: "<<inf.sito_web<<" numero accessi: "<<inf.accessi;
}
