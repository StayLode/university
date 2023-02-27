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
	cout<<"Root:"<<get_info(t)<<endl;
	cout<<"Root->first child: "<<get_info(get_firstChild(t))<<endl;
#endif
	n=new_node("Marco");
	insert_sibling(t->firstChild,n);
#ifdef DEBUG
	cout<<"Root->second child: "<<get_info(get_nextSibling(get_firstChild(t)))<<endl;
	cout<<"Marco and Paolo's parent:"<<get_info(get_parent(get_firstChild(t)))<<" "<<get_info(get_parent(get_nextSibling(get_firstChild(t))))<<endl;
#endif
	n=new_node("Lucia");
	insert_child(t->firstChild->nextSibling,n);

	node* m=new_node("Anna");
	insert_sibling(n->parent,m);
#ifdef DEBUG
	cout<<"Lucia's parent: "<<get_info(get_parent(n))<<endl;
	cout<<"Root->third child: "<<get_info(get_nextSibling(get_nextSibling(get_firstChild(t))))<<endl;
#endif

}
