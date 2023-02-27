/*
  Scrivere un programma contenente la funzione di creazione di una
  lista semplice (implementata attraverso la primitiva insert_elem) e 
  la funzione di stampa di una lista (implementata attraverso le primitive head e tail). 
  Il programma deve invocare le tre funzioni.
*/
#include <iostream>

using namespace std ;

struct persona{
    char name[30];
    int id;
};

struct elem{
    persona info;
    elem* pun;
};

typedef elem* lista;

lista ord_insert_elem(lista l,elem* e){
    if(l==NULL || compare(e->inf,head(l))<0){
        e->pun = l;
        return e;
    }
    lista l1=l;
    while (tail(l1)!=NULL && compare(e->inf,head(tail(l1)))>0){
        l1=tail(l1);
    e->pun = l1->pun;
    l1->pun = e;
    return l;
    }
}



int main()
{
    int op, n, x, var;
    lista testa = NULL;
    lista pari = NULL;
    elem *p;
    do{
      cout<<"1 - Crea lista \n"
      <<"2 - Inserisci elemento in testa \n"
      <<"3 - Elimina elemento \n"
      <<"4 - Stampa lista \n"
      <<"5 - Elimina lista \n"
      <<"6 - Trova elemento \n"
      <<"7 - Somma elemeneto \n"
      <<"8 - Lista elementi pari \n"
      <<"9 - Termina \n";
      cin>>op;

      switch(op){
        case 1:
          cout << "Inserire il numero di elementi da inserire nella lista" << endl;
          cin >> n;
          testa = crealista(n);
          cout<<endl;
          break;
        case 2:
          p = new elem;
          cout<<"Valore elemento: " ;
          cin>>p->inf ;
          testa = insert_elem(testa, p);
          cout<<endl; 
          break;
        case 3:
          cout<<"Valore elemento: " ;
          cin>>n;
          testa = delete_elem(testa, search(testa, n));
          cout<<endl;
          break;
        case 4:
          cout<<"Lista normale: ";
          stampa_ric(testa);
          cout<<endl<<"Lista inversa: ";
          stampa_inv(testa);
          cout<<endl;
          //cout<<endl;
          
          break;
        case 5:
          eliminalista(testa);
          break;
        case 6:
          cout<<"Valore elemento: ";
          cin>>n;
          x = search_pos(testa, n);
          if(x != -1)
            cout<<n<<" è presente in posizone "<<x;
          else
            cout<<n<<" non è presente";
          cout<<endl;
        case 7:
          cout<<"Posizione elemento: ";
          cin>>var;
          testa = somma_elemento(testa, var);
        case 8:
          cout<<endl<<"Lista iniziale: ";
          stampalista(testa);
          pari = split(testa);
          cout<<endl<<"Lista elementi pari: ";
          stampalista(pari);
          cout<<endl<<"Lista elementi dispari: ";
          stampalista(testa);
        default:
          break;
      }
    }while(op != 9);
    return 0;
}
