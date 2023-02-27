#include <iostream>
#include <fstream>

using namespace std;
#include "codap.h"

#include "navigatore.h"
#include "grafo.h"

/**
 * @brief 
 * Funzione che aggiunge un arco u->v al grafo g 
 * 
 * @param g  * 
 * @param u *
 * @param v 
 * @param w 
 * Valore  che specifica il peso dell'arco
 * @param d 
 * Valore che specifica se il grafo è orientato
 */
void add(graph& g, int u, int v, float w, bool d) {
	if (d)
		add_arc(g,u,v,w);
	else
		add_edge(g,u,v,w);
}


/**
 * @brief 
 * Funzione che prende in ingresso uno stream da cui leggere il grafo
 * e due valori che indicheranno se interpreterare il grafo orientato e/o pesato.
 * La funzione resituituisce una struttura grafo.
 * @param g 
 * @param d 
 * @param w 
 * @return graph 
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
 * Funzione che stampa le liste di adiacenza del grafo passato come parametro
 * @param g 
 */
void stampa(graph g){
    adj_list tmp;
    for (int i=1; i<=get_dim(g); i++) {
       tmp=get_adjlist(g,i);
       cout << i;
       while (tmp) {
	  cout << " --> " << get_adjnode(tmp);
	  tmp=get_nextadj(tmp);
       }
       cout << endl;
  }
}

/**
 * @brief 
 * Funzione ausiliaria per il punto 2.b che verifica la presenza di un nodo nel vettore dei nodi da evitare.
 * 
 * @param v 
 * Vettore dei nodi
 * @param node 
 * Valore del nodo
 * @return true 
 * @return false 
 */
bool check_presence(int *v, int node){
    for(int i = 0; i < sizeof(v); i++){
        if(v[i] == node)
            return true;
    }
    return false;
}

/**
 * @brief 
 * Funzione ausiliaria per il punto 2.b che verifica che esista un arco i->j nel grafo g
 * @param g 
 * @param i 
 * @param j 
 * @return true 
 * @return false 
 */
bool vicini(graph g, int i, int j){
    adj_list tmp = get_adjlist(g, i);
    while(tmp != NULL){
        if(get_adjnode(tmp) == j)
            return true;
        tmp = get_nextadj(tmp);
    }
    return false;
}

/**
 * @brief 
 * Funzione che calcola e restituisce il peso dall'arco  i->j del grafo g
 * @param g 
 * @param i 
 * @param j 
 * @return float 
 */
float calcola_peso(graph g, int i, int j){
    adj_list tmp = get_adjlist(g, i);
    while(tmp != NULL){
        if(get_adjnode(tmp) == j)
            return get_adjweight(tmp);
        tmp = get_nextadj(tmp);
    }
    return 0.0;
    
}
/**
 * @brief 
 * Funzione che dati in input un grafo, un nodo di partenza e uno di arrivo verifica se esiste un percorso 
 * e lo stampa dal nodo di partenza a quello di arrivo evitando i nodi presenti
 * nel vettore v.
 * Se esite stampa il percorso disponibile con costo totale altrimenti segnala "non disponibile"
 * @param g 
 * @param i 
 * @param j 
 * @param v 
 */
void evita(graph g, int i, int j, int* v){
    bool* raggiunto = new bool[get_dim(g)]; 
	int tmp;
    bool flag = true; /** flag utile per fermare il ciclo nel momento in cui si è raggiunta la destinazione*/
    int *path = new int[get_dim(g)]; /** array che terrà traccia del percorso*/
    int counter = 0; /**counter per memorizzare il numero di nodi attraversati*/
    float total_w = 0.0;

    for(int i=0; i<get_dim(g); i++)
		raggiunto[i]= false;

	codap C = NULL;
    C = enqueue(C, i, 1.0);
    while(!isEmpty(C) && flag){
        int w=dequeue(C);
        path[counter] = w;
        counter++;
		for(adj_node* n=get_adjlist(g,w);n!=NULL;n=get_nextadj(n)){
			tmp = get_adjnode(n);
            if(tmp == j){
                path[counter] = tmp;
                flag = false;
            }
			if(!raggiunto[tmp-1] && !check_presence(v, tmp)){
				raggiunto[tmp-1]=true;
				C=enqueue(C,tmp, 1.0);}
		}
    }


    for(int i = (counter-1); i > 0; i--){
        if(!vicini(g,path[i-1], path[i])){
            path[i-1] = path[i];
            counter--;
        }
    }

    for(int i = 0; i < (counter); i++)
        cout<<path[i]<<endl;
    path[counter+1] = j;
    cout<<path[counter+1]<<endl;

    if(!raggiunto[j-1])
        cout<<"Percorso non disponibile";
    
    for(int i = 0; i < (counter+1); i++)
        total_w += calcola_peso(g, path[i], path[i+1]);
    
    cout<<total_w<<endl;
    
    
}


int main(){
    int startNode, endNode;
    int evitaNodi;
    ifstream g;
    g.open("strade.txt");
    
    cout<<"Punto 1 "<<endl;
    graph G = g_build(g, 1, 1);
    stampa(G);
    cout<<"Inserire numero di nodi da evitare>> ";
    cin>>evitaNodi;
    int *v = new int[evitaNodi];
    cout<<"Inserimento nodi... "<<endl;
    for(int i = 0; i < evitaNodi; i++)
        cin>>v[i];
    cout<<"Inserire nodo di partenza>> ";
    cin>>startNode;
    cout<<"Inserire nodo di arrivo>> ";
    cin>>endNode;
    
    // int *v = new int[evitaNodi];
    // v[0] = 5;
    cout<<"Punto 2.b "<<endl;
    evita(G, startNode, endNode, v);

   
}