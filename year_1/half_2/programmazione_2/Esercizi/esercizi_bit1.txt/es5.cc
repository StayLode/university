/*
Traccia: Scrivere un programma che legga da tastiera due numeri naturali i e j. 
Il programma stampi il valore di un numero naturale 
z che ha la seguente rappresentazione binaria: 
le j cifre meno significative di z (ossia quelle a partire dalla
cifra piu' a destra) coincidono con le j cifre piu' significative 
(ossia quelle a partire dalla cifra piu' a sinistra) della rappresentazione 
binaria di i, mentre le restanti cifre sono a zero.

Esempio. Supponiamo che i abbia la seguente rappresentazione binaria: 
01011001 01001011 01001000 00100010  (supponendo che i numeri naturali
siano rappresentati su 32 bit).
Se j=4, allora il numero calcolato z avra' la seguente rappresentazione
binaria: 00000000 00000000 00000000 00000101.

Un possibile output su schermo e' il seguente:

Immettere il numero i: 6
Immettere il numero j: 31
Risultato: 3

-> ATTENZIONE al fatto che, se si immette j=0 o j > 31,
l'implementazione di questo tipo di programma potrebbe portare ad
effettuare una traslazione di un numero di posizioni maggiore di quelle 
contenute nella rappresentazione di un numero naturale. Come
gia' detto, assumiamo che non siano mai immessi valori che portano a
tale risultato (quindi, in questo caso, supponiamo 0<j<32).
*/

#include <iostream>

using namespace std;

int main(){
    int i, j;
    cout<<"Immettere il numero i: ";
    cin>>i;
    cout<<"Immettere il nuemro j: ";
    cin>>j;

    i = i>>(32-j);
    cout<<"Risultato: "<<i;

}