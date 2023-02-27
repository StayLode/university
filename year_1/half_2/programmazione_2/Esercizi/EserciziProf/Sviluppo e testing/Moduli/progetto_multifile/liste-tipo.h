/*******************************/
/* HEADER MODULO "liste-tipo" */
/*******************************/

struct elem
{
       char inf[51] ;
       elem* pun ;
       elem* prev;
} ;

typedef elem* lista ;

int compare(char*,char*);

char* head(lista);
elem* new_elem(char*);
elem* search(lista, char*);