#include <iostream>
#include <cstring>
#include <fstream>
#include "tipo.h"
#include "liste.h"
using namespace std;

/**
 * @brief aggiunge un elemento all'agenda e controlla se esiste già al suo interno. In tal caso stampa errore
 * 
 * @param agenda lista doppia che contiene gli appuntamenti
 * @param a struct che contiene le informzioni dell'appuntamento
 */
void agenda(lista& agenda, tipo_inf a){
    
    lista tmp = agenda;

    if(search(tmp, a) == NULL){
        elem* e = new_elem(a);
        agenda = insert_elem(agenda, e);
    }
    else
        cout << "ERRORE" << endl;
}

/**
 * @brief stampa la lista che gli viene passata in ingresso
 * 
 * @param p lista da stampare
 */
void stampa(lista p){
	while (p != NULL){
		print(p->inf);
		p = tail(p);
	}
}

/**
 * @brief versione di "quanti" che si basa sia sulla data che sull'ora di inizio.
 * 
 * @param agenda lista doppia che contiene gli appuntamenti
 * @param a appuntamento di cui si vuole controllare quanti appuntamenti ha prima e dopo
 */
void quanti_versione2(lista agenda, tipo_inf a){      //! variante (in questa dico quanti appuntamenti vengono
                                                      //! prima e dopo quello dato sia basandosi sulla data che l'ora di inizio)
    int cont_prima = 0;
    int cont_dopo = 0;

    while(agenda != NULL){
        if(compare(agenda->inf, a) > 0)
            cont_dopo++;
        else if(compare(agenda->inf, a) < 0)
            cont_prima++;
        
        agenda = tail(agenda);
    }

    cout << "Ho " << cont_prima << " appuntamenti prima\n";

    cout << "Ho " << cont_dopo << " appuntamenti dopo\n";
}

/**
 * @brief versione di "quanti" che si basa solo sulla data.
 * 
 * @param agenda lista doppia che contiene gli appuntamenti
 * @param a appuntamento di cui si vuole controllare quanti appuntamenti ha prima e dopo
 */
void quanti(lista agenda, tipo_inf a){
    int cont_prima = 0;
    int cont_dopo = 0;
    lista app = search(agenda, a);
    lista tmp = app;

    while(prev(tmp) != NULL){
        tmp = prev(tmp);
        if(!strcmp(tmp->inf.data, a.data))
            cont_dopo++;
    }

    tmp = app;

    while(tail(tmp) != NULL){
        tmp = tail(tmp);
        if(!strcmp(tmp->inf.data, a.data))
            cont_prima++;
    }
    cout << "Ho " << cont_prima << " appuntamenti prima\n";
    cout << "Ho " << cont_dopo << " appuntamenti dopo\n";
}

/**
 * @brief funzione per inserire gli appuntamenti in modo ordinato, in base alla data e all'ora di inizio
 * 
 * @param l agenda in cui voglio inserire gli appuntamenti
 * @param e elemento da inserire
 * @return lista --> return della lista aggiornata
 */
lista ord_insert_elem(lista l, elem* e){
	if(l == NULL || compare(e->inf,head(l)) < 0)
		return insert_elem(l,e);
	else{
		lista l1 = l;

		while (tail(l1)!=NULL && compare(head(tail(l1)),e->inf)<0)
			 l1=tail(l1);
		e->pun = l1->pun;

		if(l1->pun != NULL)
			l1->pun->prev=e;
		l1->pun = e;
		e->prev = l1;
		return l;
    }
}

/**
 * @brief genera l'agenda ordinata
 * 
 * @param agenda lista doppia in cui memorizzare gli appuntamenti
 * @param a appuntamento da aggiungere
 */
void agenda_ord(lista& agenda, tipo_inf a){
    lista tmp = agenda;

    if(search(tmp, a) == NULL){
        elem* e = new_elem(a);
        agenda = ord_insert_elem(agenda, e);
    }
    else
        cout << "ERRORE" << endl;
}

/**
 * @brief estrae dall'agenda gli appuntamenti in base alla descrizione passata come parametro
 * 
 * @param agenda lista originale
 * @param descr descrizione dell'appuntamento
 * @return lista --> return della lista che contiene gli elementi rimossi da agenda
 */
lista estrai(lista& agenda, char* descr){
    lista l_temp = agenda;
    lista precedente = NULL;
    lista precedente_descr = NULL;
    lista l2 = NULL;

    while(l_temp != NULL){
        if(!strcmp(l_temp->inf.descr, descr)){
            if(precedente == NULL){
                agenda = tail(agenda);
                agenda->prev = NULL;
            }
            else{
                precedente->pun = tail(l_temp);
                if(tail(l_temp) != NULL)
                    tail(l_temp)->prev = precedente;
            }
            if(l2 == NULL)
                l2 = precedente_descr = l_temp;
            else{
                precedente_descr->pun = l_temp;
                l_temp->prev = precedente_descr;
                precedente_descr = l_temp;
            }
        }
        else
            precedente = l_temp;
        
        l_temp = tail(l_temp);
    }
    precedente_descr->pun = NULL;
    return l2;
}


int main(){
    char data[7];
	char ora_i[5];
	char ora_f[5];
    char desc[51];
    lista age = NULL;
    lista age_ord = NULL;
    tipo_inf a;
    tipo_inf a_ord;


    //!punto 1
    ifstream f("agenda.txt");

    while(f >> data && f >> ora_i && f >> ora_f){
        strcpy(a.data, data);
        strcpy(a.ora_i, ora_i);
        strcpy(a.ora_f, ora_f);

        f.ignore(1024, '\n');
        f.getline(a.descr, sizeof(a.descr), '\n');
        
        agenda(age, a);
    }
    f.close();
    stampa(age);

    //!punto 2.a
    cout << "Inserisci le informazioni di un appuntamento (data, inizio, fine, descrizione): ";
    cin >> a.data >> a.ora_i >> a.ora_f >> a.descr;
    quanti(age, a);

    //! punto 2.b
    ifstream f1("agenda.txt");

    while(f1 >> data && f1 >> ora_i && f1 >> ora_f){
        strcpy(a_ord.data, data);
        strcpy(a_ord.ora_i, ora_i);
        strcpy(a_ord.ora_f, ora_f);

        f1.ignore(1024, '\n');
        f1.getline(a_ord.descr, sizeof(a_ord.descr), '\n');
        
        agenda_ord(age_ord, a_ord);
    }
    f1.close();
    stampa(age_ord);

    //! punto alternativo al punto 0
    lista estratti = NULL;
    cout << "Inserisci una descrizione: ";
    cin >> desc;
    estratti = estrai(age_ord, desc);
    cout << endl << "Lista originale\n";
    stampa(age_ord);
    cout << endl << "Lista estratti\n";
    stampa(estratti);

    return 0;
}