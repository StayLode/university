/*
 * main.cc
 *
 *  Created on: 21 mag 2018
 *      Author: federica
 */


#define DEBUG

#include <iostream>
using namespace std;

#include "tipo.h"
#include "tree.h"


int main(){
	tree t=NULL;

	t=new_node("Luca");
	node* n=new_node("Paolo");
	insert_child(t,n);
#ifdef DEBUG
	cout<<"Root:"<<t->inf<<endl;
	cout<<"Root->first child: "<<t->firstChild->inf<<endl;
#endif
	n=new_node("Marco");
	insert_sibling(t->firstChild,n);
#ifdef DEBUG
	cout<<"Root->second child: "<<t->firstChild->nextSibling->inf<<endl;
	cout<<"Marco and Paolo's parent:"<<t->firstChild->parent->inf<<" "<<t->firstChild->nextSibling->parent->inf<<endl;
#endif
	n=new_node("Lucia");
	insert_child(t->firstChild->nextSibling,n);

	node* m=new_node("Anna");
	insert_sibling(n->parent,m);
#ifdef DEBUG
	cout<<"Lucia's parent: "<<n->parent->inf<<endl;
	cout<<"Root->third child: "<<t->firstChild->nextSibling->nextSibling->inf<<endl;
#endif

}
