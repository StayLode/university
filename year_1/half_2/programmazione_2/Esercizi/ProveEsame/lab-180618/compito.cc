#include <iostream>
#include <cstring>
#include "carta.h"
#include "bst.h"

using namespace std;

int main(){
    bst cards = NULL;
    bnode* tmp = NULL;
    tipo_inf cardtmp;
    int operation, nCardTemp;

    do{
        cout<<"1 - Insert new card \n"
        <<"2 - Print Bst \n"
        <<"3 - Esc \n";
        cin>>operation;
        switch(operation){
            case 1:
            cout<<"Insert name and surname: ";
            cardtmp.name_surname = new char[SIZE_NAME];
            cin.getline(cardtmp.name_surname, SIZE_NAME);
            cout<<"Insert points: ";
            cin>>cardtmp.points;
            cout<<"Insert card number: ";
            cin>>nCardTemp;
            tmp = bst_newNode(nCardTemp, cardtmp);
            bst_insert(cards, tmp);
            break;
            case 2:
            stampa_bst(cards);
            break;
            default:
            break;
        }

    }while(operation != 3);

}