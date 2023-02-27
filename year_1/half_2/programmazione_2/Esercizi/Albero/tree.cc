/*
 * tree.cc
 *
 *  Created on: 14 mag 2018
 *      Author: federica
 */
#include <iostream>
using namespace std;

#include "tipo.h"
#include "tree.h"
#include <string.h>

node* new_node(tipo_inf i){
	node* n=new node;
	copy(n->inf,i);
	n->nextSibling=n->firstChild=n->parent=NULL;
	return n;
}
void insert_child(tree p, tree c){
	c->nextSibling=p->firstChild;
	c->parent=p;
	p->firstChild=c;
}
void insert_sibling(node* n, tree t){
	t->nextSibling=n->nextSibling;
	t->parent=n->parent;
	n->nextSibling=t;
}

tipo_inf get_info(node* n){
	return n->inf;
}

node* get_parent(node* n){
	return n->parent;
}

node* get_firstChild(node* n){
	return n->firstChild;
}

node* get_nextSibling(node* n){
	return n->nextSibling;
}

/*
bool path(node *e, tipo_inf x){	
	bool static flag = false;
	if(compare(get_info(e), x) == 0)
		flag = true;
	if(get_firstChild(e) != NULL)
		path(get_firstChild(e), x);
	if(get_nextSibling(e) != NULL)
		path(get_nextSibling(e), x);
	return flag;	
}
*/

bool path(node* n){
	
	tree t1 = get_firstChild(n);
	
	if (t1==NULL)
		return true;
	
	bool ris = false;
	
	while(t1!=NULL&&!ris){
		if(strcmp(get_info(n),get_info(t1)) == 0)
			ris = path(t1);
		t1 = get_nextSibling(t1);
	}
	return ris;
}
