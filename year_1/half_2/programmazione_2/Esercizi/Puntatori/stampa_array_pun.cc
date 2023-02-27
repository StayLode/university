/*
  Scrivere un programma che stampi il contenuto di un vettore di
  interi definito ed inizializzato a tempo di scrittura del programma
  stesso e che contiene almeno un elemento di valore -1. In
  particolare lo stesso vettore va stampato due volte, utilizzando
  ciascuna volta una funzione diversa. Le due funzioni di stampa
  devono avere un solo parametro formale, non devono utilizzare
  variabili globali, e devono stampare gli elementi del vettore
  fermandosi non appena incontrano l'elemento di valore -1 (senza
  stamparlo).

  La prima funzione non deve utilizzare l'operazione di selezione con
  indice, mentre la seconda non deve utilizzare né l'operazione di
  selezione con indice né alcuna variabile locale.

 */

#include <iostream>

using namespace std;

void fun1(int *p){
    int i = 0;
    while(*(p + i) != -1){
        cout<<*(p + i)<<" ";
        i++;  
    }  
}

void fun2(int *p){
    while(*p != -1)
        cout<<*p++<<" ";
}

int main(){
    int v[] = {1, 2, 3, 123, 42, 4, 4, 1, -1};
    int *p = v;
    cout<<"fun 1"<<endl;
    fun1(p);
    cout<<endl<<"fun 2"<<endl;
    fun2(p);
    cout<<endl;
}


