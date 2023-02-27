/*
Rivedere il modulo «main» del progetto sugli alberi nella
directory albero
    1.  Implementando la procedura serializza che stampa a
        video il contenuto dell’albero secondo la funzione di
        serializzazione appena descritta
        La procedura deve implementare una visita DFS in
        preodine
•       La procedura deve usare le primitive di accesso
        all’albero
    2. Sostituire le righe di stampa nel main con una chiamata
    alla funzione
*/

#include <iostream>
//#include <cstring>

using namespace std ;

#include "stringa.h"
#include "albero.h"

int main(){
    tree root = new_node("luca");
    node* M = new_node("marco");
    node* P = new_node("paolo");

    insert_child(root, P); //PAOLO FIGLIO DI LUCA

    insert_child(M, new_node("lucia")); //LUCIA FIGLIA DI MARCO
    

    insert_sibling(P, new_node("anna"));
    insert_sibling(P, M);
    serialize(root);
    cout<<endl;
    cout<<altezza(root);
    cout<<endl;
}