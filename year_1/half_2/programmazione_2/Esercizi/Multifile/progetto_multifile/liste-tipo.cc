#include <iostream>
#include <cstring>

using namespace std ;

#include "liste-tipo.h"
#include "liste.h"


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
