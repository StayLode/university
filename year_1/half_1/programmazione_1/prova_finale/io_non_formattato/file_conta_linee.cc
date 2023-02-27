/* 
*   Scrivere un programma che, senza effettuare letture formattate:

*   1) crei un file di testo di nome Testo.txt;

*   2) chieda all'utente di inserire il contenuto del file, carattere
*   per carattere (gestire opportunamente la comunicazione della fine
*   dell'immissione dei caratteri da parte dell'utente e ricordarsi che
*   si possono effettuare solo letture non formattate);

*   3) chiuda il file;

*   4) lo riapra in lettura;

*   5) ne stampi il contenuto ed il numero di righe.

  */

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream f("Testo.txt");
    char a;
    int i=0;
    while((cin.get(a))){
        f.put(a);
    }
    f.close();
    ifstream f2("Testo.txt");
    int n_righe=1;
    while((a=f2.get())!=EOF){
        cout<<a;
        if(a=='\n')
            n_righe++;
    }
    cout<<"Numero di righe: "<<n_righe;
}


