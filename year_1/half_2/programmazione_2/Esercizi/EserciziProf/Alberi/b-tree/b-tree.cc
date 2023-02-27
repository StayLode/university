/*
 * tree.cc
 *
 *  Created on: 14 mag 2018
 *      Author: federica
 */
#include <iostream>
using namespace std;

#include "tipo.h"
#include "btree.h"

bnode* new_node(tipo_inf i){
	bnode* n=new bnode;
	copy(n->inf,i);
	n->left=n->right=n->parent=NULL;
	return n;
}
void insert_left(btree p, btree t){
	p->left=t;
	t->parent=p;
}
void insert_right(btree p, btree t){
	p->right=t;
	t->parent=p;
}

bnode* get_parent(bnode* b){
	return b->parent;
}
bnode* get_left(bnode* b){
	return b->left;
}
bnode* get_right(bnode* b){
	return b->right;
}
tipo_inf get_info(bnode* b){
	return b->inf;
}



