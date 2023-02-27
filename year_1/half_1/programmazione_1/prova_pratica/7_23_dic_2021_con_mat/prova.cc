#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

const int k=3;
const char NOMEFILE[]="file.txt";
struct aereo_t{
	char codice[11];
	bool atterrato;
};

struct aeroporto_t{
	int M;
	aereo_t (*piste)[k];
};

void inizializza_Aeroporto(aeroporto_t &p, int M){

	if(p.M!=0)
		delete[] p.piste;
	
	p.M=M;
	p.piste = new aereo_t[p.M][k];
	for(int i=0;i<p.M;i++)
		for(int j=0;j<k;j++)
			p.piste[i][j].atterrato=false;
	
}

bool aggiungi_aereo_a_pista(aeroporto_t &p, char id[], int nr){
	for(int i=0;i<k;i++)
		if(p.piste[nr][i].atterrato==false){
			p.piste[nr][i].atterrato=true;
			strcpy(p.piste[nr][i].codice,id);
			return true;
		}
	
	for(int i=0;i<p.M;i++)
		for(int j=0;j<k;j++)
			if(p.piste[i][j].atterrato==false){
				p.piste[i][j].atterrato=true;
				strcpy(p.piste[i][j].codice,id);
				return true;
			}
	
	return false;

}

void salva_stato_piste(aeroporto_t &p, bool file, ostream &stream){
	if (file){
		stream<<p.M<<endl;
	}
	for(int i=0;i<p.M;i++){
		stream<<i<<" - ";
		for(int j=0;j<k;j++)
			if(p.piste[i][j].atterrato==false)
				stream<<". ";
			else	
				stream<<p.piste[i][j].codice<<" ";
		stream<<endl;
	}
	stream<<endl;
}

bool rimuovi_aereo(aeroporto_t &p, char id[]){
	for(int i=0;i<p.M;i++)
		for(int j=0;j<k;j++)
			if(strcmp(p.piste[i][j].codice,id)==0){
				p.piste[i][j].codice[0]='\0';
				p.piste[i][j].atterrato=false;
				return true;
			}
	return false;
}
/*
bool salva_stato(aeroporto_t &p){
	
	
	for(int i=0;i<p.M;i++){;
		for(int j=0;j<k;j++)
			if(p.piste[i][j].atterrato==false)
				f<<". ";
			else	
				f<<p.piste[i][j].codice<<" ";
		f<<endl;
	}
	f.close();
	return true;
}
*/
bool carica_stato(aeroporto_t &p){
	ifstream f(NOMEFILE);
	if(!f)
		return false;
	int M;
	f>>M;
	inizializza_Aeroporto(p,M);
	char trattino, indice;
	char tmp[11];
	
	for(int i=0;i<p.M;i++){
		f>>indice>>trattino;
		for(int j=0;j<k;j++){
			f>>tmp;
			if(strcmp(tmp,".")==0){
				p.piste[i][j].atterrato=false;
				p.piste[i][j].codice[0]='\0';
			}
			else{	
				p.piste[i][j].atterrato=true;
				strcpy(p.piste[i][j].codice, tmp);
			}
		}		
	}
	f.close();
	return true;
}

void compatta_piste(aeroporto_t &p){
	for(int i=0;i<p.M;i++){
		if(p.piste[i][0].atterrato==false && p.piste[i][1].atterrato==true){
			p.piste[i][0].atterrato=true;
			p.piste[i][1].atterrato=false;
			strcpy(p.piste[i][0].codice, p.piste[i][1].codice);
			strcpy(p.piste[i][1].codice,"\0");
		}
		if(p.piste[i][1].atterrato==false && p.piste[i][2].atterrato==true){
			p.piste[i][1].atterrato=true;
			p.piste[i][2].atterrato=false;
			strcpy(p.piste[i][1].codice, p.piste[i][2].codice);
			strcpy(p.piste[i][2].codice,"\0");
		}
		if(p.piste[i][0].atterrato==false && p.piste[i][2].atterrato==true){
			p.piste[i][0].atterrato=true;
			p.piste[i][2].atterrato=false;
			strcpy(p.piste[i][0].codice, p.piste[i][2].codice);
			strcpy(p.piste[i][2].codice,"\0");
		}
	}
}

int main()
{
	aeroporto_t a;
	int M;
	a.M=0;
	//a.piste = new aereo_t[M][k];
	char id[11];
	int nr;
	bool file=false;
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
			inizializza_Aeroporto(a, M);
    		break;
		case 2:
			do{
			cout<<"Inserire id dell'aereo: ";
			cin>>id;
			}while(strlen(id)>10);
			cout<<"Inserire nr di pista: ";
			cin>>nr;
			if(!aggiungi_aereo_a_pista(a, id, nr))
				cout<<"Piste piene!\n\n";
    		break;
		case 3:
			file=false;
			salva_stato_piste(a, file, cout);
    		break;
		case 4:
			do{
			cout<<"Inserire id dell'aereo da rimuovere: ";
			cin>>id;
			}while(strlen(id)>10);
			
			if(!rimuovi_aereo(a, id))
				cout<<"Aereo non trovato!\n\n";
    		break;
		case 5:
		{
			ofstream f(NOMEFILE);
			if(!f)
				return false;
			file=true;
			salva_stato_piste(a, file, f);
		}
    		break;
		case 6:
			carica_stato(a);
    		break;
		case 7:
			compatta_piste(a);
    		break;
		case 8:
			return 0;
		default:
			cout << "Scelta non valida" << endl;
		}
	}

	return 1;
}