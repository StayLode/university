/*
  Scrivere un programma contenente la funzione di creazione di una
  lista semplice (implementata attraverso la primitiva insert_elem) e 
  la funzione di stampa di una lista (implementata attraverso le primitive head e tail). 
  Il programma deve invocare le tre funzioni.
*/
#include <iostream>

using namespace std ;

struct elem
{
       int inf ;
       elem* pun ;
} ;

typedef elem* lista ;

int head(lista p){return p->inf;}

lista tail(lista p){return p->pun;}

lista insert_elem(lista l, elem* e){
	e->pun=l;
	return e;
}

void stampalista(lista p)
{
	while (p != NULL) {
		cout<<head(p)<<" " ; // stampa valore
		p = tail(p);     // spostamento sul
			                  // prossimo elemento
	}
	cout<<endl ;
}


lista crealista(int n)
{
      lista testa = NULL ;
      for (int i = 1 ; i <= n ; i++) {
          elem* p = new elem ;
          cout<<"Valore elemento "<<i<<": " ;
          cin>>p->inf ;
          testa=insert_elem(testa,p);
      }
      return testa ;
}



int main()
{
    int n; 
    cout << "Inserire il numero di elementi da inserire nella lista" << endl;
    cin >> n; 
    lista testa = crealista(n) ;
    stampalista(testa) ;
    return 0;
}
