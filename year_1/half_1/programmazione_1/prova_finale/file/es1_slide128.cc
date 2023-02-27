#include <iostream>
#include <fstream>

using namespace std ;

int main()
{    
    int N;
    ifstream f("dati.txt");
    cin>>N;
    int *p = new int [N];
    int a;
    int i=0;
    while(f>>a && a!=0){
        if(a<0){
            p[i]=a;
            cout<<p[i];
            i++;
        }
    }


}