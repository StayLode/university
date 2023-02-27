/*
 * btree.h
 *
 *  
 */

struct bnode {
   tipo_inf inf;
   bnode* parent; 
	bnode* left;
	  bnode* right;
};

typedef bnode* btree;

bnode* new_node(tipo_inf);
void insert_left(btree, btree);
void insert_right(btree, btree);
bnode* get_parent(bnode*);
bnode* get_left(bnode*);
bnode* get_right(bnode*);
tipo_inf get_info(bnode*);






