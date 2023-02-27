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

bool* connected(graph g, int v){
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
				C=enqueue(C,i);
      }
		}
	}
  return raggiunto;
}

void connected_component(graph g) {
  bool* raggiunto_globale = new bool[get_dim(g)];
  for(int i=0; i<get_dim(g); i++)
		raggiunto_globale[i]= false;

  // Prendo il primo nodo non raggiunto a false
  bool nodivisitati = false;
  while (!nodivisitati) {
    int j = -1;
    for(int i=0; i<get_dim(g) && j == -1 ; i++)
      if (raggiunto_globale[i] == false) {
        j = i;
      }

    nodivisitati = true;
    if (j != -1) {
      bool* raggiunto = connected(g,j+1);
      cout << "Connected component: ";
      for(int i=0; i<get_dim(g); i++) {
        if (raggiunto[i]) {
          cout << i+1 << " ";
        }
		    raggiunto_globale[i] |= raggiunto[i];
        nodivisitati &= raggiunto_globale[i];
      }
      cout << endl;
    }
  }
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

  connected_component(G);
  
}
