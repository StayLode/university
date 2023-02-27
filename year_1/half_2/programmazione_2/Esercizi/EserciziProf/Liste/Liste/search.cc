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

elem* search(lista l, int v){
	while(l!=NULL)
		if(head(l)==v)
			return l;
		else 
			l=tail(l);
	return NULL;}


int main()
{
    int n; 
	int v;
    bool continua;
	cout << "Inserire il numero di elementi da inserire nella lista" << endl;
    cin >> n; 
    lista testa = crealista(n) ;
    stampalista(testa) ;
	do{
		cout << "Valore da cercare"<<endl;
		cin>>v;
		if(search(testa,v)!=NULL)
			cout<< "Valore presente"<<endl;
		else
			cout<<"Valore non presente"<<endl;
		cout << "Altro elemento da cercare (0 per false - 1 per true)?"<<endl;
		cin>>continua;
	}while(continua);
    return 0;
}