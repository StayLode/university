#include <iostream>

using namespace std;

struct ss{
    int a=2;
    short z;
};

void fun(ss b);

int main(){
    ss k;
    fun(k);
}

