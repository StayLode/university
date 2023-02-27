
/* Torre di Hanoi: Dichiarazione della procedura ricorsiva */
/*pioloS: sorgente pioloD: destinazione pioloA: appoggio */

#include <iostream>

using namespace std ;

void hanoi(int n, char pioloS, char pioloD, char pioloA);


int main()
{
  int n;
  
  do {
    cout<<"Immetti il numero di dischi: ";
    cin>>n ;
  }while(n<=0);
  hanoi(n, 'A', 'C', 'B');
  return 0;
} 

void hanoi(int n, char pioloS, char pioloD, char pioloA)
{
if(n == 1) {
    cout<<"Muovi un disco dal piolo "<< pioloS <<" al piolo "<<pioloD<<endl;
  }
  else {
    hanoi(n-1, pioloS, pioloA, pioloD);
    cout<<"Muovi un disco dal piolo "<< pioloS <<" al piolo "<<pioloD<<endl;
    hanoi(n-1, pioloA, pioloD, pioloS);
  }
}

