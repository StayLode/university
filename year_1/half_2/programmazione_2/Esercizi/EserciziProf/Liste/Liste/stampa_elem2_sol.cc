/*
  Scrivere un programma in cui sia definita (a tempo di scrittura 
  del programma stesso) una lista formata da due elementi, 
  contenenti i valori 3 e 7, e si stampi il contenuto della lista 
  mediante la funzione stampalista
*/

#include <iostream>

using namespace std ;


struct elem
{
       int inf;
       elem* pun ;
} ;

typedef elem* lista ;

int head(lista p){return p->inf;}

lista tail(lista p){return (p->pun);}

void stampalista(lista p)
{
	while (p != NULL) {
		cout<<head(p)<<" " ; // stampa valore
		p = tail(p);     // spostamento sul
			                  // prossimo elemento
	}
	cout<<endl ;
}



int main() {
lista testa = new elem;

//testa->inf = 3;
elem * p = new elem; // creo l'elemento
//p->inf = 7;
p->pun = NULL;
testa->pun = p; //aggancio l'elemento  
stampalista(testa);
}
