#include <iostream>
using namespace std;
#include <cstring>

#include "carta.h"
/**
 * @brief
 * funzione per comparare il nome e cognome delle varie carte
 * 
 * @param s1
 * prima carta
 * @param s2
 * seconda carta
 * @return
 * int ritorna l'esito del confronto
 */
int compare(tipo_inf s1,tipo_inf s2){
	return strcmp(s1.dati,s2.dati);
}

/**
 * @brief
 * utilizzata per copiare nel campo dati la stringa passata da riga di comando quando si vuole generare una nuova carta
 * 
 * @param dest
 * carta su cui copiare la stringa
 * @param source
 * struttura da cui copiare la stringa
 */
void copy(tipo_inf& dest, tipo_inf source){
	dest.dati=new char[strlen(source.dati)];
	strcpy(dest.dati,source.dati);
    dest.punti = source.punti;
}

/**
 * @brief
 * funzione per stampare il valore informativo di un nodo
 * 
 * @param inf 
 * struttura che contiene i valori informativi del nodo
 */
void print(tipo_inf inf){
	cout << inf.dati;
	cout<<"  ";
    cout << inf.punti;
}