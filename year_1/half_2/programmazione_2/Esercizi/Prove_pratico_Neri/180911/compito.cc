#include <iostream>
#include <cstring>
#include <fstream>
#include "tipo.h"
#include "liste.h"
#include "parola.h"



using namespace std;

parola* load(){
    int parole;
    int num_doc;
    char word[80];
    int documento;

    ifstream f("inverted");
    f >> parole;
    parola* v = new parola[parole];

    for(int i=0; i<parole; i++){
        f >> word;
        f >> num_doc;
        v[i].n_doc = num_doc;
        strcpy(v[i].p, word);
        for(int y=0; y<num_doc; y++){
            f >> documento;
            elem* e;
            e = new_elem(documento);
            v[i].l = insert_elem(v[i].l, e);
        }
    }
    f.close();
    return v;
}

void stampalista(lista p){
	cout << "[";
	while (p != NULL){
		cout << head(p) << " - ";
		p = tail(p);
	}
	cout << "]" << endl;
}

void stampa(parola* v, int n){
    for(int i=0; i<n; i++){
        cout << v[i].p << "\t" << v[i].n_doc << "\t";
        stampalista(v[i].l);
    }
}

void update(parola* &inverted, char* filename, int& dim){
    int file;
    bool flag = false;
    char word[80];
    ifstream f(filename);
    f >> file;
    
    while(f >> word){
        flag = false;
        for(int i=0; i<dim; i++){
            if(!strcmp(word, inverted[i].p)){ //caso in cui c'è già la parola
                inverted[i].n_doc++;
                flag = true;
                elem* e;
                e = new_elem(file);
                inverted[i].l = insert_elem(inverted[i].l, e);
            }
        }
        if(!flag){  //caso in cui devo aggiungere una parola
            dim++;
            parola* v = new parola[dim];
            for(int i=0; i<dim-1; i++){
                strcpy(v[i].p, inverted[i].p);
                v[i].n_doc = inverted[i].n_doc;
                v[i].l = inverted[i].l;
                //delete[] inverted;
            }
            v[dim-1].n_doc = 1;
            strcpy(v[dim-1].p, word);
            elem* e;
            e = new_elem(file);
            v[dim-1].l = insert_elem(v[dim-1].l, e);
            inverted = v;
        }
    }
}

void AND(parola* inverted, char* w1, char* w2, int dim){
    int vett[dim*2];
    int cont=0;
    int tmp=0;
    parola* inverted_tmp = inverted;

    for(int i=0; i<dim; i++){
        if(!strcmp(w1, inverted[i].p)){
            while (inverted_tmp[i].l != NULL){
                vett[cont] = head(inverted_tmp[i].l);
                inverted_tmp[i].l = tail(inverted_tmp[i].l);
                cont++;
	        }
        }
    }

    inverted_tmp = inverted;

    for(int i=0; i<dim; i++){
        if(!strcmp(w2, inverted[i].p)){
            while (inverted_tmp[i].l != NULL){
                vett[cont] = head(inverted_tmp[i].l);
                inverted_tmp[i].l = tail(inverted_tmp[i].l);
                cont++;
	        }
        }
    }
    for(int i=0; i<cont; i++){
        for(int y=0; y<cont; y++){
            if(vett[i] == vett[y])
                tmp++;
        }
        if(tmp > 1)
            cout << vett[i] << "\t";
        tmp = 0;
        vett[i] = -1;
    }
}

int* match(parola* inverted, char** richiesta, int dim){

}

int main(){
    parola* vett;
    int dim;
    char nomefile[80];
    char w1[80];
    char w2[80];

    ifstream f2("inverted");
    f2 >> dim;
    f2.close();

    //! punto 1
    vett = load();
    stampa(vett, dim);

    //! punto 2
    cout << "inserisci nome del file: ";
    cin >> nomefile;
    update(vett, nomefile, dim);
    stampa(vett, dim);

    //! punto 3.a
    cout << "Inserisci le due parole: ";
    cin >> w1 >> w2;
    AND(vett, w1, w2, dim);

    //! punto 3.b

    return 0;
}