#include <iostream>
#include <fstream>
using namespace std;
#include "tipo.h"
#include "liste.h"
#include "parola.h"
#include <cstring>

/* PUNTO 1 */
parola* load(int& n)
{

}

void stampa(parola* p,int n)
{

}

/* PUNTO 2 */
void update(parola*& II,char* fileName,int& n)
{

}

/* PUNTO 3*/

void AND(parola* II,char* W1,char* W2,int n)
{

}

/* MAIN */
int main()
{
  /* INIZIO PUNTO 1 */
  parola* p=load();
  ifstream file("inverted");
  int n=0;
  file>>n;
  file.close();
  stampa(p,n);
  /* FINE PUNTO 1 */

  /* INIZIO PUNTO 2 */
  char fileName[256];
  cout<<"Inserisci il nome del file:";
  cin>>fileName;
  update(p,fileName,n);
  cout<<"Post Update:"<<endl;
  stampa(p,n);
  /* FINE PUNTO 2 */

  /* INIZIO PUNTO 3 */
  cout<<"Inserisci il primo elemento:"<<endl;
  char W1[80];
  cin>>W1;
  cout<<"Inserisci il secondo elemento:"<<endl;
  char W2[80];
  cin>>W2;
  AND(p,W1,W2,n);
  /* FINE PUNTO 3* */

  return 0;
}
