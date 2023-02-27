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

void stampa_ric(lista p){
  if(p != NULL){
    cout<<head(p)<<" ";
    stampa_ric(tail(p));
  }
  else
    cout<<endl;
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

lista delete_elem(lista l, elem* e){
  if(e == NULL)
    return l;  
  //? e è la testa della lista
  if (l==e)  
    l=tail(l);
  else{
    //?localizzo l'elemento che punta a e
    lista l1=l;
    while (tail(l1)!=e)
      l1=tail(l1);
    //? aggiorno l'elemento che punta a e
    l1->pun=tail(e);
    }
  delete e;
  return l;
}

void eliminalista(lista& testa)
{
     while (testa != NULL) 
           testa=delete_elem(testa,testa);
}

elem* search(lista l, int v){
  while(l!=NULL)
  if(head(l)==v)
    return l;
  else
    l=tail(l);
  return NULL;
}

int search_pos(lista l, int v){
  int i = 0;
  for(; l != NULL; i++){
    if(head(l)==v)
      return i;
    else
      l=tail(l);
  }
  return -1;
}

lista somma_elemento(lista l, int p){
	int var;
  lista l1 = l;
	for(int i = 0; i < p; i++){
    l1 = tail(l1);
	}

  var = head(l1);
	l1 = l;	

	while(tail(l1) != NULL){
		l1->inf += var;
		l1 = tail(l1);		
	}
  l1->inf += var;
	return l;
}

void stampa_inv(lista l){
  if(l != NULL){
    stampa_inv(tail(l));
    cout<<head(l)<<" ";
  }
}

lista split(lista& l){
    lista l_temp = l;
    lista precedente = NULL;
    lista lista_pari = NULL;
    lista precedente_pari = NULL;

    while(l_temp != NULL){
        if(head(l_temp) < 4){
            if(precedente == NULL)
                l = tail(l);
            else
                precedente->pun = tail(l_temp);
            if(lista_pari == NULL)
                    lista_pari = precedente_pari = l_temp;
             else{
                    precedente_pari->pun = l_temp;
                    precedente_pari = l_temp;
                }
        }
        else
            precedente = l_temp;
        l_temp = tail(l_temp);
    }
    precedente_pari->pun = NULL;
    return lista_pari;
}


void diff(lista l1, lista l2){
	while(l1 != NULL && head(l1) < head(l2)){ //stampo tutti gli elementi minori del primo elemento di l2
		cout<<head(l1)<<" ";
		l1 = tail(l1);
	}
	if(tail(l2) != NULL) //controllo che dopo il primo elemento di l2 ce ne sia un altro
		diff(tail(l1), tail(l2)); //richiamo la funzione a partire dall'elemento successivo al quale ero arrivato in entrmabe le liste
	else{
    l1 = tail(l1);
    while(l1 != NULL){ //se non ho più elementi stampo tutta la lista
			cout<<head(l1)<<" ";
			l1 = tail(l1);
		}
  }

}


void delete_even(lista &l){
  lista l1 = l;
  bool flag = true;
  while(tail(l1) != NULL){
    if(tail(tail(l1)) != NULL){
      l1->pun = tail(tail(l1));
    }
      
    l1 = tail(l1);
  }

}

int main()
{
    int op, n, x, var;
    lista testa = NULL;
    lista testa2 = NULL;
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
      <<"9 - DiffLista \n"
      <<"10 - DeleteEven \n"
      <<"11 - Termina \n";
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
                    break;

        case 7:
          cout<<"Posizione elemento: ";
          cin>>var;
          testa = somma_elemento(testa, var);
          break;
        case 8:
          cout<<endl<<"Lista iniziale: ";
          stampalista(testa);
          pari = split(testa);
          cout<<endl<<"Lista elementi pari: ";
          stampalista(pari);
          cout<<endl<<"Lista elementi dispari: ";
          stampalista(testa);
          break;
         case 9:
          cout << "Inserire il numero di elementi da inserire nella lista" << endl;
          cin >> n;
          testa2 = crealista(n);
          cout<<endl<<"Prima lista: ";
          stampa_ric(testa);
          cout<<endl<<"Seconda lista: ";
          stampa_ric(testa2);
          cout<<endl<<"Output: ";
          diff(testa, testa2);
          cout<<endl;
         break;
        case 10:
          cout<<"Old List: ";
          stampa_ric(testa);
          cout<<endl;
          delete_even(testa);
          cout<<"New list: ";
          stampa_ric(testa);
          cout<<endl;
          break;
        default:
          break;
      }
    }while(op != 11);
    return 0;
}
