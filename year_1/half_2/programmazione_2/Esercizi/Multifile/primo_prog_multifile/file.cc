#include <iostream>

using namespace std;
extern int x;

void fun(){
    extern int x;
    cout<<x<<endl;
}

void fun1(){
    extern int x;
    cout<<x<<endl;
}

void fun2(){
    extern int x;
    cout<<x<<endl;
}