#include <iostream>
using namespace std;


int main()
{

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
    		break;
		case 2:
    		break;
		case 3:
    		break;
		case 4:
    		break;
		case 5:
    		break;
		case 6:
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