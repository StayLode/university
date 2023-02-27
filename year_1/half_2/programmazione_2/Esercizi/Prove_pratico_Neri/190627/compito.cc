#include <iostream>
#include <cstring>
#include <fstream>
#include "tipo.h"
#include "liste.h"
#include "grafo.h"

using namespace std;

void stampalista(lista p){
	while (p != NULL){
		print(head(p));
		p = tail(p);
	}
}

int carica(lista& pi){
    int num;
    int cont = 0;

    ifstream f("PI.txt");

    while(f >> num){
        cont ++;
        tipo_inf dati;
        dati.id = num;
        f.ignore(1024, '\n');
        f.getline(dati.nome, sizeof(dati.nome), '\n');
        f >> dati.tipo; 
        pi = ord_insert_elem(pi, new_elem(dati));
    }
    f.close();
    return cont;
}

tipo_inf search_pi(lista pi, int id){
    lista ris;
    tipo_inf ricerca;

    ricerca.id = id;
    ris = ord_search(pi, ricerca);
    return ris->inf;
}

graph mappa(int n){
    ifstream f("G.txt");
    int n1, n2;
    graph map = new_graph(n);

    while(f >> n1 && f >> n2){
        add_arc(map, n1, n2, 0);
        add_arc(map, n2, n1, 0);
    }
    return map;
}

void stampa_mappa(graph mappa, lista pi){
    adj_list tmp;
    tipo_inf luogo;
    for(int i=1; i<=get_dim(mappa); i++) {
      tmp = get_adjlist(mappa, i);
      luogo = search_pi(pi, i);
      cout << luogo.nome << " connesso a: ";
      while(tmp){
        luogo = search_pi(pi, get_adjnode(tmp));
        cout << luogo.nome <<" - ";
        tmp = get_nextadj(tmp);
      }
      cout << endl;
  }
}

void trip(graph map, int node, lista pi){
    
}

lista genera(lista pi, char tipo){
    lista l = NULL;
    while(pi != NULL){
        if(pi->inf.tipo == tipo)
            l = insert_elem(l, new_elem(pi->inf));
        pi = tail(pi);
    }
    return l;
}

int main(){
    lista pi = NULL;
    tipo_inf luogo;
    int num_pi;
    int id;
    graph map;
    char tipo;

    //! punto 1
    num_pi = carica(pi);
    stampalista(pi);
    cout << endl;

    cout << "Inserisci id da ricercare: ";
    cin >> id;
    luogo = search_pi(pi, id);
    print(luogo);
    cout << endl;
    cout << "Inserisci id da ricercare: ";
    cin >> id;
    luogo = search_pi(pi, id);
    print(luogo);
    cout << endl;

    //! punto 2.a
    map = mappa(num_pi);
    stampa_mappa(map, pi);

    //! punto 3.a
    
    cout << "\nInserisci identificativo del nodo: ";
    cin >> id;
    trip(map, id, pi);
    

    //! punto 2.b
    lista l;
    cout << "\nInserisci tipo: ";
    cin >> tipo;
    l = genera(pi, tipo);
    stampalista(l);

    return 0;
}