#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int k=3;
const char NOMEFILE[] = "file.dat";

struct aereo_t{
	char codice[11];
};

struct pista_t{
	aereo_t pista[k];
};

struct aereoporto_t{
	pista_t *porto;
	int M;
};

void inizializza(int M, aereoporto_t &p){
	if(p.M!=0)
		delete[] p.porto;
	p.M=M;
	p.porto=new pista_t[p.M];
	for(int i=0;i<p.M;i++)
		for(int j=0;j<k;j++)
			strcpy(p.porto[i].pista[j].codice,".");	

}

bool aggiungi_aereo(char id[], int nr, aereoporto_t &p){
	if(nr < 0 || nr > p.M)
		return false;
	for(int i=0;i<k;i++)
		if(strcmp(p.porto[nr].pista[i].codice, ".")==0){
			strcpy(p.porto[nr].pista[i].codice, id);
			return true;
		}
	for(int i=0;i<p.M;i++)
		for(int j=0;j<k;j++)
			if(strcmp(p.porto[i].pista[j].codice, ".")==0){
				strcpy(p.porto[i].pista[j].codice, id);
				return true;
			}	

	return false;
}

void stampa_stato(aereoporto_t &p){
	for(int i=0;i<p.M;i++){
		cout<<i<<" - ";
		for(int j=0;j<k;j++)
			cout<<p.porto[i].pista[j].codice<<" ";
		cout<<endl;
	}
	cout<<endl;

}

bool rimuovi_aereo(char id[], aereoporto_t &p){
	for(int i=0;i<p.M;i++)
		for(int j=0;j<k;j++)
			if(strcmp(p.porto[i].pista[j].codice, id)==0){
				strcpy(p.porto[i].pista[j].codice,".");	
				return true;
			}
	return false;
}

bool salva_stato(aereoporto_t &p){
	ofstream f(NOMEFILE);
	if(!f)
		return false;
	int tot=p.M*k;
	f.write(reinterpret_cast<const char *>(&p.M), sizeof(int));
	f.write(reinterpret_cast<const char *>(p.porto), sizeof(aereoporto_t)*tot);
	f.close();
	return true;
}
bool carica_stato(aereoporto_t &p){
	ifstream f(NOMEFILE);
	if(!f)
		return false;

	int M;
	f.read(reinterpret_cast<char *>(&M), sizeof(int));
	inizializza(M, p);
	int tot=p.M*k;

	f.read(reinterpret_cast<char *>(p.porto), sizeof(aereoporto_t)*tot);
	
	f.close();
	return true;
}

int main()
{
	aereoporto_t p;
	p.M=0;
	int M;
	char id[11];
	int nr;
	const char menu[] =
		"1. Inizializza Aeroporto\n"
		"2. Aggiungi un aereo ad una pista\n"
		"3. Stampa lo stato delle piste\n"
		"4. Rimuovi un aereo\n"
		"5. Salva aeroporto\n"
		"6. Carica aeroporto\n"
        "7. Compatta piste\n"
		"8. Esci\n";

	while (true) {
		cout << menu << endl;
		int scelta;
		cin >> scelta;

		cout << endl; // questo accapo e' importante per il tester!

		switch (scelta) {
		case 1:
			cout<<"Inserire numero di piste: ";
			cin>>M;
			inizializza(M, p);
    		break;
		case 2:
			do{
				cout<<"Inserire id dell'aereo: ";
				cin>>id;
			}while(strlen(id)>10);
			cout<<"Inserire nr di pista: ";
			cin>>nr;
			if(!aggiungi_aereo(id, nr, p))
				cout<<"Pista non presente/Piste piene!\n\n";
    		break;
		case 3:
			stampa_stato(p);
    		break;
		case 4:
    		do{
				cout<<"Inserire id dell'aereo da rimuovere: ";
				cin>>id;
			}while(strlen(id)>10);
			
			if(!rimuovi_aereo(id, p))
				cout<<"Aereo non trovato!\n\n";
    		break;
		case 5:
			salva_stato(p);
    		break;
		case 6:
			carica_stato(p);
    		break;
		case 7:
    		break;
		case 8:
			return 0;
		default:
			cout << "Scelta non valida" << endl;
		}
	}

	return 1;
}