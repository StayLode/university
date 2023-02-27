#include <iostream>

using namespace std;

int fibonacci(int n){
    if(n == 0 || n == 1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    int n;
    do{
        cout<<"Inserire n: ";
        cin>>n;
        if(n>0)
            cout<<"Il numero in posizione "<<n<<" della serie di fibonacci e' "<<fibonacci(n)<<endl;
        else
            cout<<"Riprovare con un numero maggiore di 0... "<<endl;
    }while(n<0);
}
