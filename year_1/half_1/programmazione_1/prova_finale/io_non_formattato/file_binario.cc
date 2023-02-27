/* 
*   Scrivere un programma in cui si dichiari un tipo struct studente,
*   costituito da un campo nome, un campo cognome ed un campo numero di
*   matricola. Si definiscano e si inizializzino quindi almeno due
*   oggetti (variabili) di tipo struct studente e si memorizzino in
*   forma binaria in un file. Si chiuda quindi il file, lo si riapra in
*   lettura e se ne stampi il contenuto.

*/

#include <iostream>
#include <fstream>
using namespace std;

struct studente{
    char nome[20];
    char cognome[25];
    int matricola;
};

int main(){
    studente neri ={"riccardo", "neri", 123456};
    studente ricc = {"riccardo", "vaccari", 123456};

    ofstream f("studenti.dat");

    f.write(reinterpret_cast<char *>(&neri), sizeof(studente));
    f.write(reinterpret_cast<char *>(&ricc), sizeof(studente));

    f.close();
    studente neri2, ricc2;
    ifstream f2("studenti.dat");
    f2.read(reinterpret_cast<char *>(&neri2), sizeof(studente));
    f2.read(reinterpret_cast<char *>(&ricc2), sizeof(studente));
    cout<<neri2.nome<<" "<<neri2.cognome<<" "<<neri2.matricola<<endl;
    cout<<ricc2.nome<<" "<<ricc2.cognome<<" "<<ricc2.matricola<<endl;

}