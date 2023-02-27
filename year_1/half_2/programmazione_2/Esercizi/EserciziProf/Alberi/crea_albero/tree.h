/*
 * tree.h
 *
 *  Created on: 14 mag 2018
 *      Author: federica
 */

struct node {
   tipo_inf inf;
   node* parent; //opzionale
	  node* firstChild;
	  node* nextSibling;
};

typedef node* tree;

node* new_node(tipo_inf);
void insert_child(tree, tree);
void insert_sibling(node*, tree);





