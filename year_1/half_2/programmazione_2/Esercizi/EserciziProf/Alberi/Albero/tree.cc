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

