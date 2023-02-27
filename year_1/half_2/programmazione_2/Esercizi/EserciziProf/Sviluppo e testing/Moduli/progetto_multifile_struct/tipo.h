/*******************************/
/* HEADER MODULO "liste-tipo" */
/*******************************/



typedef struct{
	char sito_web[81];
	int accessi;
}tipo_inf;

int compare(tipo_inf,tipo_inf);
void copy(tipo_inf&,tipo_inf);
void print(tipo_inf);
