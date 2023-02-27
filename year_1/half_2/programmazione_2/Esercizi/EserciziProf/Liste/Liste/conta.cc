/*
  Scrivere un programma contenente la funzione conta che riceve in ingresso come parametri una lista e un valore e 
restituisce il numero di occorrenze di un valore  in una lista.
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

elem* search(lista l, int v){
	while(l!=NULL)
		if(head(l)==v)
			return l;
		else 
			l=tail(l);
	return NULL;}
	
int conta(lista l, int v){
	/* .... */
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
	int v;
    
	cout << "Inserire il numero di elementi da inserire nella lista" << endl;
    cin >> n; 
    lista testa = crealista(n) ;
    stampalista(testa) ;
	
	/* estendere il main affinché chieda un valore da cercare e stampi il numero di occorrenze del valore 
	nella lista "testa" */

}