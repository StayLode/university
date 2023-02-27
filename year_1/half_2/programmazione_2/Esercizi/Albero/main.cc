/*
 * main.cc
 *
 *  Created on: 21 mag 2018
 *      Author: federica
 */



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
#ifdef DEBUG
	cout<<"Root:"<<get_info(t)<<endl;
	cout<<"Root->first child: "<<get_info(get_firstChild(t))<<endl;
#endif
	n=new_node("Luca");
	insert_sibling(t->firstChild,n);
#ifdef DEBUG
	cout<<"Root->second child: "<<get_info(get_nextSibling(get_firstChild(t)))<<endl;
	cout<<"Luca and Paolo's parent:"<<get_info(get_parent(get_firstChild(t)))<<" "<<get_info(get_parent(get_nextSibling(get_firstChild(t))))<<endl;
#endif
	n=new_node("Ricc");
	insert_child(t->firstChild->nextSibling,n);

	node* m=new_node("Ivan");
	insert_sibling(n->parent,m);
#ifdef DEBUG
	cout<<"Luca's parent: "<<get_info(get_parent(n))<<endl;
	cout<<"Root->third child: "<<get_info(get_nextSibling(get_nextSibling(get_firstChild(t))))<<endl;
#endif

serialize(t);
cout<<endl;
if(path(t))
	cout<<"OK"<<endl;
else
	cout<<"NO"<<endl;


}
