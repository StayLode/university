/*******************************/
/* HEADER MODULO "carta" 	   */
/*******************************/

/**
 * @brief Definizione struttura dati per l'informazione contenuta nei nodi del bst
 * dati --> puntatore a stringa (nome e cognome)
 * punti --> intero per memorizzare i punti accumulati dalla carta con i vari acquisti
 */

struct info{
    char* dati;
    int punti;
};

typedef info tipo_inf;

int compare(tipo_inf,tipo_inf);
void copy(tipo_inf&,tipo_inf);
void print(tipo_inf);
