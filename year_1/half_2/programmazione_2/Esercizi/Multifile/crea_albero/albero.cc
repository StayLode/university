/*
Creare	il	modulo	“albero”	che	contiene
• La	struct “node”	e	il	tipo	di	dato	“tree”
• Le	primitive	per	la	creazione	di	alberi
• Creare	un	progetto	per	la	creazione	di	un	albero	di	stringhe
• Il	progetto	si	compone	di	tre	moduli:	il	modulo	“albero”,	il	modulo	
“stringa”	che	implementa	il	tipo	tipo_inf come	stringa	e	il	modulo	
“main”

*/


#include <iostream>
//#include <cstring>



#include "stringa.h"
#include "albero.h"


using namespace std ;

/*******************************/
/* DEFINIZIONE MODULO "albero" */
/*******************************/

node* new_node(tipo_inf i){
    node* new_node = new node;
    new_node->firstChild = NULL;
    new_node->nextSibling = NULL;
    new_node->parent = NULL;
    copy(new_node->inf, i);
    return new_node;
}


//aggiorna p inserendo il sottoalbero radicato in c come primo figlio di p
void insert_child(tree p, tree c){
    c->nextSibling = p->firstChild;
    c->parent = p;
    p->firstChild = c;
}

//Aggiorna n inserendo il sottoalbero radicato in	t come	fratello successivo di	n
void insert_sibling(node* n, tree t){
    t->nextSibling = n->nextSibling;
    t->parent = n->parent;
    n->nextSibling = t;
}

//Restituisce il contenuto informativo del nodo n
tipo_inf get_info(node* n){
    return n->inf;
}

//restituisce il padre del nodo n
node* get_parent(node* n){
    return n->parent;
}

//restituisce il primo figlio del nodo n, se esite
node* get_firstChild(node* n){
    return n->firstChild;
}

//restituisce il fratello successivo del nodo n, se esite
node* get_nextSibling(node* n){
    return n->nextSibling;
}

void serialize(tree t){
    cout<<"(";
    print(get_info(t));
    tree t1 = get_firstChild(t);
    while(t1 != NULL){
        serialize(t1);
        t1 = get_nextSibling(t1);
    }
    cout<<")";
}

int altezza(tree t){
	if(get_firstChild(t)==NULL)
		return 0;
	int max=0,max_loc;
	tree t1 = get_firstChild(t);
	while(t1!=NULL){
		max_loc=altezza(t1);
		if(max_loc>max)
			max=max_loc;
		t1 = get_nextSibling(t1);
	}
	return max+1;
}
