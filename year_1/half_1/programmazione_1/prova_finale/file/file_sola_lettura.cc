/*
! Slide 114 sui file
* Crei un file di nome Testo.txt
* Chieda all'utente di inserire il contenuto del file,
* carattere per carattere mediante letture formattate
* (gestire opportunamente la comunicazione della
* fine dell'immissione dei caratteri da parte
* dell'utente, assumendo che l'utente non comunichi
* a priori il numero di caratteri che immetterà)
* Chiuda il file
* Lo riapra in lettura
* Ne stampi il contenuto
*/
#include <iostream>
#include <fstream>

using namespace std ;

int main()
{
    ofstream f("Testo.txt");
    char c;
    if (!f) cerr<<"Errore in creazione del file"<<endl;
    cin>>noskipws;
    while(cin>>c)
        f<<c;
    f.close();


    ifstream f2("Testo.txt");
    if(!f2) cerr<<"Errore di apertura del file"<<endl;
    while(f2>>noskipws>>c)
        cout<<c;


}