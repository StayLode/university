/*******************************/
/* HEADER MODULO "carta" 	   */
/*******************************/

#define SIZE_NAME 41

struct card{
    char* name_surname;
    int points;
};

typedef card tipo_inf;

int compare(tipo_inf card1,tipo_inf card2);
void copy(tipo_inf&,tipo_inf);
void print(tipo_inf card);