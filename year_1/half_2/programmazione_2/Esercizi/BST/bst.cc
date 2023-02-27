/*
 * tree.cc
 *
 *  Created on: 14 mag 2018
 *      Author: federica
 */
#include <iostream>
using namespace std;

#include <cstring>

#include "tipo.h"
#include "bst.h"

static tipo_key copy_key(tipo_key& s,tipo_key s1){
	s=s1;
	return s;
}

static tipo_key compare_key(tipo_key s,tipo_key s1){
		return s-s1;
}

void print_key(tipo_key k){
	cout<<k;
}
tipo_key get_key(bnode* n){
	return (n->key);
}

tipo_inf get_value(bnode* n){
	return (n->inf);
}

bst get_left(bst t){
	return (t->left);
}

bst get_right(bst t){
	return (t->right);
}

bnode* get_parent(bnode* n){
	return (n->parent);
}



bnode* bst_newNode(tipo_key k, tipo_inf i){
	bnode* n=new bnode;
	copy(n->inf,i);
	copy_key(n->key,k);
	n->right=n->left=n->parent=NULL;
	return n;
}

void bst_insert(bst& b, bnode* n){
	bnode* x;
	bnode* y=NULL;
	if(b==NULL){
		    	b=n;
		    }
	else{
	    x=b;
	    while (x != NULL) {
	      y=x;
	      if (compare_key(get_key(n),get_key(x))<0) {
		      x = get_left(x);
	      } else {
		      x = get_right(x);
	      }
	    }
	    n->parent = y;
	    if (compare_key(get_key(n), get_key(y))<0) {
	      y->left = n;
	    } else {
	      y->right = n;
	    }
}}

bnode* bst_search(bst b,tipo_key k){

	    while (b != NULL) {
	      if (compare_key(k,get_key(b))==0)
	    	  return b;
	      if (compare_key(k,get_key(b))<0) {
		      b = get_left(b);
	      } else {
		      b = get_right(b);
	      }
	    }
	    return NULL;
}

void print_subtree(bst b, int x, int y){
	bnode* subB = bst_search(b, x);
	
	if(get_key(subB) < y)
		cout<<get_key(subB)<<" ";
	
	if(get_left(subB) != NULL)
		print_subtree(get_left(subB), get_key(get_left(subB)), y);
	if(get_right(subB) != NULL)
		print_subtree(get_right(subB), get_key(get_right(subB)), y);
	
}

void stampa_inv(bst b){
	if(get_right(b)!=NULL)
		stampa_inv(get_right(b));

	print_key(get_key(b));
	cout<<"  ";

	if(get_left(b)!=NULL)
		stampa_inv(get_left(b));
}


bool same(bst b1, bst b2){

if(b1== NULL || b2 == NULL)
		if( b1 == NULL && b2 == NULL)
			return true;
		else 
			return false;
  else {
		bool left = same(b1->left,b2->left);
		bool right = same(b2->right, b2->right);
		return b1->inf == b2 -> inf && left && right;}}

/*
Scrivere la funzione void print_subtree(bst b, int x) che dato un valore intero x presente nel BST b, stampi in ordine decrescente 
tutti i valori nel sottoalbero radicato nel nodo che contiene x (nell’implementazione è possibile scrivere più funzioni):
*/
void print_subtree3(bst b, int x){
	bst subB = bst_search(b, x);
	if(subB != NULL)
		stampa(subB);	
}

void stampa(bst b){
	if(get_right(b) != NULL){ stampa(get_right(b));}
	cout<<get_key(b)<<" ";
	if(get_left(b) != NULL){stampa(get_left(b));}
}

bnode *bst_search(bnode *b, int k){
	
	if(compare_key(get_key(b), k) == 0)
		return b;
	else if(b == NULL)
		return NULL;

	if(compare_key(get_key(b), k) < 0)
		return bst_search(get_right(b), k);
	else
		return bst_search(get_left(b), k);
}