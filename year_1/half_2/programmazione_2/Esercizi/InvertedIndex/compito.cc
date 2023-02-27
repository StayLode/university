#include "tipo.h"
#include "liste.h"
#include "parola.h"

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

/**
 * @brief 
 *  Carica dal file inverted l’inverted index. Tutte le parole
 * sono memorizzate in un vettore dinamico di tipo parola. La
 * dimensione del vettore dinamico è letta dalla prima riga del
 * file inverted.
 * La funzione restituisce il vettore dinamico e la sua
 * dimensione nel parametro passato per riferimento
 * 
 */
parola* load(int& dim){    
    int tmp;
    ifstream f("inverted");
    f>>dim;
    parola *p = new parola[dim];
    for(int i = 0; i < dim; i++){
        f>>p[i].p;
        f>>p[i].n_doc;
        lista testa = NULL ;
        for(int j = 0; j < p[i].n_doc; j++){
            f>>tmp;
            elem* e = new_elem(tmp);
            testa = insert_elem(testa, e);
        }
        p[i].l = testa;
    }
    f.close();
    return p;
}

/**
 * @brief 
 * Stampa il contenuto dell’inverted index (primo parametro
 * vettore dinamico, secondo parametro dimensione
 *  del vettore).
 */
void stampa(parola *p, int dim){
    for(int i = 0; i < dim; i++){
        cout<<p[i].p<<"\n";
        stampalista(p[i].l);
	    cout<<endl ;
    }
}

//?     Aggiorna l’inverted index caricando il contenuto del
//?     documento contenuto nel file fileName.
//?     Ogni file caricato ha la stessa struttura del file doc. Il codice deve gestire il
//?     caso di aggiunta di una parola, di aggiunta di un id di documento alla
//?     posting list di un parola già presente nell’inverted index. Il parametro n
//?     contiene la nuova dimensione della vettore
//?     Estendere il main affinché aggiorni l’inverted index con il documento
//?     contenuto nel file doc. Il main deve chiedere all’utente il nome del file
//?     da caricare, richiamare la procedura update e richiamare la funzione
//?     stampa per stampare l’inverted index risultante

//bool check_presence(parola*)
int check_presence(parola* II, int& n, char new_word[]){
    for(int i = 0; i < n; i++){
        if(!strcmp(new_word, II[i].p))
            return i;
    }
    return -1;
}

/**
 * @brief 
 * Funzione che aggiorna il contenuto dell'inverted index caricando il contenuto del documento nel filename
 * @param II 
 * Inverted index preso in ingresso
 * @param filename
 * documento con gli aggiornamenti
 * @param n 
 * dimensione dell'II
 */
void update(parola* &II, char* filename, int& n){
    ifstream f(filename);
    int new_id, i;
    f>>new_id;
    char c, word[80];
    do{
        f>>word;
        i = check_presence(II, n, word);
        if(i != -1){
            II[i].n_doc++;
            elem* e = new_elem(new_id);
            II[i].l = insert_elem(II[i].l, e);
        }
        else{
            n+=1;
            parola *II2 = new parola[n];
            for(int i = 0; i < (n-1); i++)
                II2[i] = II[i];
            strcpy(II2[n-1].p, word);
            II2[n-1].n_doc = 1;
            lista testa = NULL ;
            testa = insert_elem(testa, new_elem(new_id));
            II2[n-1].l = testa;
            II = II2;
        }
    
    }while(f.get(c));

}

int main(){
    int dim;
    parola *inverted_index;
    inverted_index = load(dim);
    stampa(inverted_index, dim);
    update(inverted_index, "doc", dim);
    cout<<"Stampa dopo doc"<<endl;
    stampa(inverted_index, dim);
   
    return 0;
}