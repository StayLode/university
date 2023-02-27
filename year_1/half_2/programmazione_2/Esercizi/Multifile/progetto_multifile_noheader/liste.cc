#include <iostream>
#include <cstring>

using namespace std ;

/*******************************/
/* HEADER MODULO "liste-tipo" */
/*******************************/

struct elem
{
       char inf[51] ;
       elem* pun ;
       elem* prev;
} ;

typedef elem* lista ;

/*******************************/
/* HEADER MODULO "liste-tipo" */
/*******************************/

int compare(char*,char*);
char* head(lista);
elem* new_elem(char*);
elem* search(lista, char*);


/*******************************/
/* HEADER MODULO "liste" */
/*******************************/
	

lista tail(lista);
lista prev(lista);
lista insert_elem(lista, elem*);
lista delete_elem(lista, elem*);



/*******************************/
/* DEFINIZIONE MODULO "liste" */
/*******************************/

lista tail(lista p){return p->pun;}
lista prev(lista p){return p->prev;}

lista insert_elem(lista l, elem* e){
	e->pun=l;
	if(l!=NULL)
		l->prev=e;
	e->prev=NULL;
	return e;
}

lista delete_elem(lista l, elem* e){

		if(l==e)
			l=e->pun; // e è la testa della lista
		else // e non è la testa della lista
			(e->prev)->pun = e->pun;
		if(e->pun!=NULL)
			(e->pun)->prev=e->prev;
		delete e;
		return l;
}

