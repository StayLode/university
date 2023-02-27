/*
 * main.cc
 *
 *  Created on: 21 mag 2018
 *      Author: federica
 */


#define DEBUG
#define DFS

#include <iostream>
using namespace std;

#include "tipo.h"
#include "tree.h"
#include "coda-bfs.h"

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
#ifdef DFS
int dimensione(tree t){
		int dim=0,dim1;
		tree t1 = get_firstChild(t);
		while(t1!=NULL){
			dim1=dimensione(t1);
			dim+=dim1;
			t1 = get_nextSibling(t1);
		}
		return dim+1;
}
#else
int dimensione(tree t){
	int count=0;
	codaBFS c = newQueue();
	c=enqueue(c,t);
	while(!isEmpty(c)){
		node* n=dequeue(c);
		count++;
		tree t1 = get_firstChild(n);
		while(t1!=NULL){
				c=enqueue(c,t1);
				t1 = get_nextSibling(t1);
			}
	}
	return count;

}
#endif
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
	cout<<"Altezza dell'albero: "<<altezza(t)<<endl;
	cout<<"Dimensione dell'albero:"<<dimensione(t)<<endl;

}
