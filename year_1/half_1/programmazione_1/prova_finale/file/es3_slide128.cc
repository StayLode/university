#include <iostream>
#include <fstream>

using namespace std ;

int main()
{    
    int N;
    ifstream f("dati.txt");
    cin>>N;
    char *p = new char [N];
    char *c = new char [N];
    int cont=0;
    f.get(p, sizeof(char)*N, '*');
    for(int i=0;i<N;i++){
        if ((p[i]>='a'&& p[i]<='z')||(p[i]>='A'&&p[i]<='Z')){
            c[cont]=p[i];
            cont++;
        }

    }
    for(int i=0;i<cont;i++)
        cout<<c[i]<<" ";
    cout<<endl;
}
