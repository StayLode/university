#include <iostream>
#include <cstring>
#include "carta.h"
#include "bst.h"
using namespace std;

/**
 * @brief
 * Funzione per calcolare i punti accumulati dalle carte defeltà tra due estremi
 * 
 * @param b
 * Albero binario su cui eseguire funzione
 * @param inf
 * Estremo carta fedeltà inferiore
 * @param sup
 * Estremo carta fedeltà superiore
 * @return int
 *  Return della somma dei vari punti di ogni carta all'interno del range
 */

int totalePunti(bst b, tipo_key inf, tipo_key sup){
    int cont = 0;
    if(b==NULL)
		return 0;

    if(b->key >= inf && b->key <= sup)
        cont = b->inf.punti;

	if(get_left(b) != NULL)
		cont += totalePunti(get_left(b), inf, sup);
        
	if(get_right(b) != NULL)
		cont += totalePunti(get_right(b), inf, sup);

    return cont;
}

/**
 * @brief
 * Funzione per aggiornare il numero di punti acquisto di una certa carta fedeltà
 * 
 * @param b
 * Albero su cui eseguire la funzione
 * @param chiave
 * Numero di carta su cui eseguire l'aggiornamento
 * @param p
 * Numero dei punti da sommare
 */

void aggiorna(bst b, tipo_key chiave, int p){
    bst nodo;
    
    nodo = bst_search(b, chiave);
    if(nodo == NULL)
        cout << "ERRORE, carta non esistente!" << endl;
    else
        nodo->inf.punti += p;
}

int main(){
    /**
     * @brief
     * Definizione variabili
     * 
     */
    int carte;
    bst t = NULL;
	char nome_cognome[41];
    char nome[41];
    char cognome[41];
    char spazio[] = " ";
	bnode* b;
    info informazioni;
    int key, punti, inf, sup;
    int y = -1;

    /**
     * @brief
     * Creazione dell'albero binario
     * 
     */

    cout << "Inserisci il numero di carte: ";
    cin >> carte;
    int* p = new int[carte];

    for(int i=0; i<carte; i++){
        cout << endl << "Inserisci il valore di chiave: ";
        cin >> key;
        p[++y] = key;
        cout << endl << "Inserisci il valore di nome e cognome: ";
        cin >> nome >> cognome;
        cout << endl << "Inserisci il valore dei punti: ";
        cin >> punti;

        strcpy(nome_cognome, strcat(nome, spazio));
        strcat(nome_cognome, cognome);

        informazioni.dati = nome_cognome;
        informazioni.punti = punti;

        b = bst_newNode(key, informazioni);
        bst_insert(t,b);
    }

    /**
     * @brief
     * Stampa dell'albero binario in ordine crescente di chiave (numero di carta)
     * 
     */
    stampa(t);

    /**
     * @brief
     * chiamata della funzione totale punti
     * 
     */
    cout << "Inserisci inf e sup: ";
    cin >> inf >> sup;
    cout << "Totale punti = " << totalePunti(t, inf, sup) << endl;


    /**
     * @brief
     * Definizione variabili, chiamata della funzione aggiorna e stampa dell'alber aggiornato
     * 
     */
    bool flag = true;
    char scelta;
    while(flag){
        cout << "Digitare 'S' se si vuole smettere di registrare gli acquisti: ";
        cin >> scelta;
        
        if(scelta == 'S')
            flag = false;
        else{
            cout << "Inserisci numero di carta e punti accumulati: ";
            cin >> key >> punti;
            aggiorna(t, key, punti);
            for(int i=0 ; i<carte; i++){
                if(p[i] == key)
                    p[i] = -1;
            }
        }
    }
    stampa(t);

    /**
     * @brief
     * Stampa delle carte che non hanno effettuato acquisti in giornata
     * 
     * Sfrutta un array contenente le chiavi dei diversi nodi.
     * Se il nodo è convolto nella funzione aggiorna allora nell'array il suo numero di chiave viene sostituito da un -1.
     * Successivamente tramite la primitiva search cerco nell'albero i nodi con chiave diversa da -1 (cioè quelli che non hanno subito modifiche).
     * Infine li stampo.
     */
    cout << endl << endl << "LISTA DELLE CARTE CHE NON HANNO EFFETTUATO ACQUISTI OGGI" << endl;
    for(int i=0 ; i<carte; i++){
        if(p[i] != -1){
            bst nodo;
            nodo = bst_search(t, p[i]);
            print_key(get_key(nodo));
            cout<<"  ";
            print(get_value(nodo));
            cout<<endl;
        }
    }

    return 0;
}