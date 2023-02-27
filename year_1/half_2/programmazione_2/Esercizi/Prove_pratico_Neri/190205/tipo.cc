#include "tipo.h"
#include <iostream>
#include <cstring>

using namespace std;

#include <iostream>
using namespace std;
#include <cstring>
 
int compare(tipo_inf s1,tipo_inf s2){
    if(s1.seme == s2.seme){
        return s1.valore - s2.valore;
    }
    return s1.seme - s2.seme;
}


void copy(tipo_inf& dest, tipo_inf source){
	dest.seme = source.seme;
	dest.valore = source.valore;
}

void print(tipo_inf inf){
	cout << inf.seme;
	cout<< "  ";
    cout << inf.valore;
}