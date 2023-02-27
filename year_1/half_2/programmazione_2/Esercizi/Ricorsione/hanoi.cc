#include <iostream>

using namespace std;

int counter = 0;

//piolo S - sorgente pioloD - dest pioloA - appoggio

void hanoi(int n, char pioloS, char pioloD, char pioloA){
    if(n==1)
        cout<<++counter<<" - Disco da "<<pioloS<<" a "<<pioloD<<endl;
    else{
        hanoi(n-1, pioloS, pioloA, pioloD);
        cout<<++counter<<" - Disco da "<<pioloS<<" a "<<pioloD<<endl;
        hanoi(n-1,pioloA, pioloD, pioloS);
    }
}

int main(){
    int n;
    cout<<"Inserire il numero di dischi: ";
    cin>>n;
    hanoi(n, 'S', 'D', 'A');

}