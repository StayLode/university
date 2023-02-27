#include "tipo.h"
#include <iostream>
#include <cstring>

using namespace std;

/**
 * @brief funzione per confrontare appuntamenti in base alla data e all'ora di inizio
 * 
 * @param s1 primo appuntamento
 * @param s2 secondo appuntamento
 * @return int --> return dell'esito del confronto
 */
int compare(tipo_inf s1,tipo_inf s2){
    if(!strcmp(s1.data, s2.data))
        return strcmp(s1.ora_i, s2.ora_i);
    return strcmp(s1.data, s2.data);
}

/**
 * @brief funzione per copiare le informazioni
 * 
 * @param dest appuntamento in cui copiare i dati
 * @param source appuntamento da cui copiare i dati
 */
void copy(tipo_inf& dest, tipo_inf source){
    strcpy(dest.data, source.data);
    strcpy(dest.ora_i, source.ora_i);
    strcpy(dest.ora_f, source.ora_f);
    strcpy(dest.descr, source.descr);
}

/**
 * @brief funzione per stampare i dati dell'appuntamento
 * 
 * @param inf struct che contiene le informazioni dell'appuntamento
 */
void print(tipo_inf inf){
    cout << inf.data << " | " << inf.ora_i << " | " << inf.ora_f << " | " << inf.descr << endl;
}