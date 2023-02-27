
/*******************************/
/* HEADER MODULO "albero" */
/*******************************/

struct node {
    tipo_inf inf;
    node* parent; //opzionale
    node* firstChild;
    node* nextSibling;
};
    
typedef node* tree; //punta alla radice dell’albero

node* new_node(tipo_inf i);
void insert_child(tree p, tree c);
void insert_sibling(node* n, tree t);
tipo_inf get_info(node* n);
node* get_parent(node* n);
node* get_firstChild(node* n);
node* get_nextSibling(node* n);
void serialize(tree t);
int altezza(tree t);

