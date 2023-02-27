#include <iostream>

using namespace std;

int quadrato(int x){ return x*x;};
int cubo(int x){ return x*x*x;};

int somma(int n, int(*pfun)(int)){
    int sum = 0;
    for(int i = 1; i <= n; i++)
        sum += pfun(i);
    return sum;
}

int main(){
    int n;
    cout<<"Inserire n ";
    cin>>n;
    cout<<somma(n, cubo)<<endl;
}