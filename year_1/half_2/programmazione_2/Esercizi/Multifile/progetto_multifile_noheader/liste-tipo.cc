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
/* DEFINIZIONE MODULO "liste-tipo" */
/*******************************/

int compare(char* s1,char* s2){
	return strcmp(s1,s2);
}

char* head(lista p){return p->inf;}

elem* search(lista l, char* v){
	while(l!=NULL)
		if(strcmp(head(l),v)==0)
			return l;
		else
			l=tail(l);
	return NULL;}
	
elem* new_elem(char* inf){
	    elem* p = new elem ;
	    strcpy(p->inf,inf);
	    p->pun=p->prev=NULL;
		return p;
	
	}
