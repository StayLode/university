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
	ifstream file("inverted");
	char word[80];

	file >> n;

	int n_doc = 0;
	parola* inverted_index = new parola[n]; // 3 parole

	for (int i = 0; i < n; i++) {
		file >> word;
		file >> n_doc;
		strcpy(inverted_index[i].p, word);
		inverted_index[i].n_doc = n_doc;
		inverted_index[i].l = NULL;
		for (int j = 0; j < n_doc; j++) {
			int doc = 0;
			file >> doc;
			elem* toIns = new_elem(doc);
			inverted_index[i].l = insert_elem(inverted_index[i].l, toIns);
		}
	}
	file.close();
	return inverted_index;
}

void stampa(parola* p,int n)
{
	for (int i = 0; i < n; i++) {
		cout << p[i].p << endl;
		lista l = p[i].l;
		while (l != NULL) {
			cout << head(l) << endl;
			l = tail(l);
		}
	}

}

/* PUNTO 2 */
void update(parola*& II,char* fileName,int& n)
{
	ifstream file(fileName);
	int id = 0;
	file >> id;

	while (file.good()) {
		char word[80];
		file >> word;
		int i = 0;
		bool trovato = false;
		while (i < n && !trovato) {
			if (strcmp(word, II[i].p) == 0) {
				II[i].l = insert_elem(II[i].l, new_elem(id));
				trovato = true;
			}
			i++;
		}
		if (!trovato) {
			n++;
			parola* temp = new parola[n];
			for (int i = 0; i < n-1; i++) {
				temp[i] = II[i];
			}
			II = new parola[n];
			for (int i = 0; i < n-1; i++) {
				II[i] = temp[i];
			}
			strcpy(II[i].p, word);
			II[i].n_doc = 1;
			II[i].l = NULL;
			II[i].l = insert_elem(II[i].l, new_elem(id));
		}
	}

}

/* PUNTO 3*/
void AND(parola* II,char* W1,char* W2,int n)
{
	lista d1 = NULL;
	lista d2 = NULL;
	for (int i = 0; i < n; i++) {
		if (strcmp(II[i].p, W1) == 0) {
			d1 = II[i].l;
		}
		if (strcmp(II[i].p, W2) == 0) {
			d2 = II[i].l;
		}
	}
	while (d2 != NULL) {
		if (search(d1, head(d2)) != NULL) {
			cout << head(d2);
		}
		d2 = tail(d2);
	}
}

/* MAIN */
int main()
{
  /* INIZIO PUNTO 1 */
  int n;

  parola* p=load(n);
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
