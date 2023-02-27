#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

#include "coda.h"
#include "grafi.h"
#include "node.h"

void stampa(graph G, node* vett){
    adj_list tmp;
    for (int i=1; i<=get_dim(G); i++) {
        tmp = get_adjlist(G,i);
        cout << i;
        while(tmp){
            cout << " --> " << get_adjnode(tmp);
            tmp = get_nextadj(tmp);
        }
        cout << endl;
    }
    cout << endl;

    for (int i=1; i<=get_dim(G); i++) {
        tmp = get_adjlist(G,i);
        while(tmp){
            cout << vett[i-1].cont << " ";
            if(vett[i-1].tipo == 'U' && vett[get_adjnode(tmp)-1].tipo == 'U')
                cout << "FOLLOW ";
            else if(vett[i-1].tipo == 'T' && vett[get_adjnode(tmp)-1].tipo == 'U')
                cout << "OWNER ";
            else if(vett[i-1].tipo == 'U' && vett[get_adjnode(tmp)-1].tipo == 'T')
                cout << "LIKE ";
            cout << vett[get_adjnode(tmp)-1].cont;
            tmp = get_nextadj(tmp);
            cout << endl;
        }
        cout << endl;
    }

}

int* totalLike(graph g, node* vett){
    int* V = new int[get_dim(g)];
    int* owner = new int[get_dim(g)];
    adj_list tmp;

    for(int i=0; i<get_dim(g); i++)
        V[i] = 0;

    for(int i=1; i<=get_dim(g); i++){
        if(vett[i-1].tipo == 'U')
            owner[i-1] = -1;
        else{
            for (int y=1; y<=get_dim(g); y++){
                tmp = get_adjlist(g,i);
                while(tmp){
                    if(vett[y-1].tipo == 'T' && vett[get_adjnode(tmp)-1].tipo == 'U' && !strcmp(vett[i-1].cont, vett[y-1].cont))
                        owner[i-1] = get_adjnode(tmp)-1;
                    tmp = get_nextadj(tmp);
                }
            }
        }
    }

    for (int i=1; i<=get_dim(g); i++) {
        if(owner[i-1] == -1){
            tmp = get_adjlist(g,i);
            while(tmp){
                if(vett[get_adjnode(tmp)-1].tipo == 'T')
                    V[owner[get_adjnode(tmp)-1]]++;
                tmp = get_nextadj(tmp);
            }
        }
    }
    return V;
}

void follow(graph g, node* vett, int v){
	bool* raggiunto = new bool[get_dim(g)];
	int i;
    bool flag = true;

	for(int i=0; i<get_dim(g); i++)
		raggiunto[i] = false;
  
	coda C = newQueue();
	raggiunto[v-1]=true;
	C = enqueue(C,v);
	while(!isEmpty(C)){
		int w = dequeue(C);
        if(flag)
            cout << endl << "L'utente " << vett[w-1].cont << " segue:" <<endl;
        else
            cout << vett[w-1].cont << endl;
        flag = false;
		for(adj_node* n = get_adjlist(g,w); n != NULL; n = get_nextadj(n)){
			i = get_adjnode(n);
			if(!raggiunto[i-1] && vett[i-1].tipo == 'U'){
				raggiunto[i-1]=true;
				C = enqueue(C,i);
            }
		}
	}
}


int main(){
    int nodi;
    int n1, n2;
    char frase[81];
    graph g;


    //! punto 1
    ifstream f("graph");
    f >> nodi;
    g = new_graph(nodi);
    node* vett = new node[get_dim(g)];

    while(f >> n1 && f >> n2){
        add_arc(g, n1, n2, 0);
    }
    f.close();
    stampa(g, vett);


    //! punto 2
    ifstream f2("node");
    for(int i=0; i < get_dim(g); i++){
        f2.getline(vett[i].cont, sizeof(vett[i].cont), '\n');
        f2 >> vett[i].tipo;
        f2.ignore(1024, '\n');
    }
    f2.close();
    for(int i=0; i<8; i++){
        cout << vett[i].cont << "\t" << vett[i].tipo << endl;
    }
    stampa(g, vett);


    //! punto 3.a
    int *V;
    int max=0, max_tmp;
    V = totalLike(g, vett);
    for(int i=0; i<get_dim(g); i++){
        max_tmp = V[i];
        if(max_tmp >= max)
            max = max_tmp;
    }
    for(int i=1; i<=get_dim(g); i++){
        if(V[i-1] == max)
            cout << vett[i-1].cont << endl;
    }

    //! punto 3.b
    follow(g, vett, 8);

}