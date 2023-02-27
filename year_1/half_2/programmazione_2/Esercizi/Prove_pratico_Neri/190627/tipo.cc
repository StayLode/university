#include "tipo.h"
#include <iostream>
#include <cstring>

using namespace std;
 
int compare(tipo_inf s1,tipo_inf s2){
    return s1.id - s2.id;
}


void copy(tipo_inf& dest, tipo_inf source){
    dest.id = source.id;
    strcpy(dest.nome, source.nome);
    dest.tipo = source.tipo;
}

void print(tipo_inf inf){
    cout << inf.id << "     " << inf.nome << "     " << inf.tipo << endl;
}