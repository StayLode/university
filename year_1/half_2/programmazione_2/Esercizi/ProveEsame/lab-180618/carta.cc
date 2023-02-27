#include <iostream>
#include <cstring>

using namespace std ;

#include "carta.h"

int compare(tipo_inf card1,tipo_inf card2){
    return card1.points-card2.points;
}

void copy(tipo_inf& card1,tipo_inf card2){
    card1.name_surname =new char[strlen(card2.name_surname)];
	strcpy(card1.name_surname,card2.name_surname);
    card1.points = card2.points;
}

void print(tipo_inf card){
    cout<<card.name_surname<<endl<<card.points<<endl;
}
