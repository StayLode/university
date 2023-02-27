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

void serialize(tree t){
	cout<<"(";
	print(get_info(t));
	tree t1 = get_firstChild(t);
	while(t1!=NULL){
		serialize(t1);
		t1 = get_nextSibling(t1);
	}
	cout<<")";
}

int main(){
	tree t=NULL;

	t=new_node("Luca");
	node* n=new_node("Paolo");
	insert_child(t,n);
	n=new_node("Marco");
	insert_sibling(t->firstChild,n);
	n=new_node("Lucia");
	insert_child(t->firstChild->nextSibling,n);
	node* m=new_node("Anna");
	insert_sibling(n->parent,m);
#ifdef DEBUG
	serialize(t);
#endif

}
