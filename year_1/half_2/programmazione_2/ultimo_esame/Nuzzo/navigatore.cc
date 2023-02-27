#include <iostream>
using namespace std;
#include "navigatore.h"


/**
 * @brief 
 * Funzione che calcola la differenza tra due nodi
 *
 * @param p1 
 * Peso arco 1
 * @param p2 
 * Peso arco 2
 * @return int 
 * Ritorna un valore positivo se p1 è maggiore, negativo altrimenti. 
 * Ritorna 0 se hanno stesso peso;
 */
int compare(tipo_inf p1,tipo_inf p2){
    return p1-p2;
}
/**
 * @brief 
 * Copia il valore del nodo
 * @param p1 
 * @param p2 
 */
void copy(tipo_inf& p1, tipo_inf p2){
    p1 = p2;
}
/**
 * @brief 
 * Stampa il valore del nodo
 * 
 * @param p 
 */
void print(tipo_inf p){
    cout<<p;
}
