/*
*  Scrivere un programma che:

*  1) definisca un array di reali di dimensioni definite a tempo di scrittura
*     del programma, e chieda all'utente di inserirne i valori;

*  2) riversi il contenuto dell'array sia in un file binario "dati.dat"
*     mediante output non formattato, che in un file di testo
*     "dati.txt" mediante output formattato;

*  3) chiuda entrambi i file;

*  4) li riapra in lettura;

*  5) ristampi il contenuto di entrmabi i file (in termini di numeri reali).

*  Provare a visualizzare e confrontare il contenuto dei due file con
*  un editor di testo o con comandi quali 
*  cat <nome_file>

  */
#include <iostream>
#include <fstream>

using namespace std ;

int main()
{
    const int dim = 5;
    ofstream f_bin("dati.dat");
    ofstream f_txt("dati.txt");
    if(!f_bin || !f_txt) cerr<<"Errore crezione file!";
    float v[dim];

    for(int i=0;i<dim;i++){
        cout<<"Inserire l'elemento "<<i+1<<" dell'array: ";
        cin>>v[i];
        f_bin.put(v[i]);
        f_txt<<v[i];
    }

    f_bin.close();
    f_txt.close();

    float a;

    ifstream f2_txt("dati.txt");
    ifstream f2_bin("dati.dat");

    if(!f2_bin || !f2_txt) cerr<<"Errore apertura file!";

    cout<<"Contenuto file di testo:"<<endl;
    while(f2_txt>>noskipws>>a)
        cout<<a;
    cout<<endl;

    cout<<"Contenuto file binario: "<<endl;
    while((a = f2_bin.get())!=EOF)
        cout<<a;
    cout<<endl;

}