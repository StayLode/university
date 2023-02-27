/********************************************************
 *                                                      *                                  
 * Programma che fornisce la rappresentazione di un grafo    
 * mediante liste di adiacenza.                           
 * Il programma riceve in ingresso due parametri: il nome del 
 * file che contiene la definizione del grafo mediante 
 * lista di archi e un flag che indica se gli archi sono pesati 
 * (flag weighted - 0 se non pesati - 1 se pesati).
 * Il file di input � strutturato come segue:
 * Num di nodi
 * Primo arco
 * Secondo arco
 * ...
 *                                                             
 * La funzione graph, che si occupa della costruzione del grafo,
 * restituisce un intero, che indica il numero n     
 * di nodi nel grafo. Per il programma chiamante, un nodo �    
 * quindi semplicemente costituito da un numero fra 1 ed n. 
 *                                                      *                                     
 *******************************************************/

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

#include "grafo.h"
#include "coda-bfs.h"

void add(graph& g, int u, int v, float w, bool d) {
	if (d)
		add_arc(g,u,v,w);
	else
		add_edge(g,u,v,w);
}

/** Funzione che prende in ingresso uno stream da cui leggere il grafo
 * e due valori che indicheranno se interpreterare il grafo orientato e/o pesato.
 * La funzione resituituisce una struttura grafo. 
 */
graph g_build(ifstream &g, bool d, bool w) {
  int n;
  g >> n;
  graph G = new_graph(n);
  int v1,v2;
  if (w) {
    float w;
    while (g >> v1 >> v2 >> w) {
      add(G,v1,v2,w,d);
     }
  } else {
    while (g >> v1 >> v2) {
      add(G,v1,v2,1.0,d);
    }
  }
  return G;
}

/**
 * @brief 
 * Funzionce che verifica la connessione del grafo
 * @param g 
 * Grafo da controllare
 * @param v
 * nodo da cui partire
 * @return true
 * se il grafo è connesso 
 * @return false
 * se il grafo non è connesso 
 */
bool connected(graph g, int v){
	bool* raggiunto = new bool[get_dim(g)];
	int i;

	for(int i=0; i<get_dim(g); i++)
		raggiunto[i]= false;
	codaBFS C=newQueue();
	raggiunto[v-1]=true;
	C=enqueue(C,v);
	while(!isEmpty(C)){
		int w=dequeue(C);
		for(adj_node* n=get_adjlist(g,w);n!=NULL;n=get_nextadj(n)){
			i = get_adjnode(n);
			if(!raggiunto[i-1]){
				raggiunto[i-1]=true;
				C=enqueue(C,i);}
		}
	}
	for(int i=0;i<get_dim(g);i++)
		if(!raggiunto[i])
			return false;
	return true;
}
/**
 * @brief 
 * 
 * @param g 
 * @param v 
 */
void visitaBFSiterativa(graph g, int v){
  int i;
  bool* raggiunto = new bool[get_dim(g)];
  int* padre = new int[get_dim(g)];
  for(int i=0; i<get_dim(g); i++)
    raggiunto[i]= false;
  codaBFS C=newQueue();

  raggiunto[v] = true;
  
  for(int i = 0; i < get_dim(g); i++)
    padre[i] = -1;
  C = enqueue(C, v);

  while(!isEmpty(C)){
    int u = dequeue(C);
    cout<<u<<" ";
    
    for(adj_node* n=get_adjlist(g,u);n!=NULL;n=get_nextadj(n)){
      i = get_adjnode(n);
      if(!raggiunto[i-1]){
        raggiunto[i-1] = true;
        padre[i-1] = u;
        C = enqueue(C, i);
      }
    }
  }
  cout<<endl;
  for(int i = 0; i < get_dim(g); i++)
    cout<<padre[i]<<" ";
  cout<<endl;

}

bool even_path(graph g, int x, int y){
 
  adj_list l = get_adjlist(g, x);
  
  if(l == NULL)
    return false;
  
  do{
    if(get_adjnode(l) == y)
      return true;

    if(get_adjnode(l)%2 == 0){ 
      if(even_path(g, get_adjnode(l), y))
        return true;
    }
    
    l = get_nextadj(l);
    
  } while (l != NULL);
  
  return false;

}

int main(int argc,char *argv[]) {
   /* Se il numero di parametri con cui e' stato chiamato il client e'
     inferiore a tre - si ricordi che il primo parametro c'e' sempre, ed e' il
     nome del file eseguibile - si ricorda all'utente che deve inserire
     anche il nome del file che descrive il grafo e il flag  weighted*/

  if (argc<3) {
    cout << "Usage: " << argv[0] << " filename directed weighted\n";
    exit(0);
  };


  ifstream g;
  g.open(argv[1]);
      cout <<   argv[1] << " " << argv[2] << " " << argv[2]<<endl;
  int directed = atoi(argv[2]);
  int weighted = atoi(argv[3]);

  /*Chiamata a g_build che costruisce un grafo*/

  graph G=g_build(g, directed, weighted);

  cout<<get_dim(G)<<endl;
  
  //Stampa dell'array di liste
  adj_list tmp;
    for (int i=1; i<=get_dim(G); i++) {
       tmp=get_adjlist(G,i);
       cout << i;
       while (tmp) {
	  cout << " --> " << get_adjnode(tmp);
	  tmp=get_nextadj(tmp);
       }
       cout << endl;
  }

//cout<<endl<<"Connesso: "<<connected(G, 1)<<endl;

  if(same_degree(G))
    cout<<"OK";
  else
    cout<<"NO";

  cout<<endl;

  
}
