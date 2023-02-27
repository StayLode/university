/*******************************/
/* HEADER MODULO "codaBFS" */
/*******************************/
struct elemBFS
{
       int inf;
       elemBFS* pun ;
};

typedef elemBFS* lista;

typedef struct{
	lista head;
	elemBFS* tail;} codaBFS;

codaBFS enqueue(codaBFS, int);
int dequeue(codaBFS&);
int first(codaBFS);
bool isEmpty(codaBFS);
codaBFS newQueue();

static elemBFS* new_elem(int);
