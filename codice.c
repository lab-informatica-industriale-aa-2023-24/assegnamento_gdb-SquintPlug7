#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 10

// Funzione per estrarre i dati dai parametri in ingresso
void estrai_dati(int ac, char **av, int *vett, int *lung)
{
	*lung = ac - 1;

	for (int i = 0; i < *lung; ++i)
		vett[i] = atoi(av[i + 1]);
}

// Funzione per fare spazio nell'array
void fai_spazio(int posizione, int *vett, int lung)
{
	for (int j = lung - 1; j > posizione; --j)  // Corretto da j++ a j--
		vett[j] = vett[j - 1];
}

// Funzione per inserire il nuovo dato nella posizione corretta
void inserisci(int nuovo_dato, int num_dati_ord, int *vett)
{
	if (num_dati_ord == 0) {  // Correzione: era '=' ora è '=='
		vett[0] = nuovo_dato;
		return;
	}

	for (int i = 0; i < num_dati_ord; ++i) {
		if (nuovo_dato < vett[i]) {
			fai_spazio(i, vett, num_dati_ord);
			vett[i] = nuovo_dato;
			return;
		}
	}
	vett[num_dati_ord] = nuovo_dato;  // Inserisci in fondo se è il più grande
}

// Funzione per ordinare i dati usando l'insertion sort
void ordina_dati(const int *dati_non_ordinati, int num_dati, int *dati_ordinati)
{
	for (int i = 0; i < num_dati; ++i)
		inserisci(dati_non_ordinati[i], i, dati_ordinati);
}

// Funzione per stampare il vettore ordinato
void stampa_vettore(const int *vett, int lung)
{
	for (int i = 0; i < lung; ++i)
		printf("%d ", vett[i]);
	printf("\n");
}

int main(int argc, char **argv)
{
	if (argc > MAX_INPUT + 1) {  // Messaggio di errore se si superano i 10 input
		printf("Numero massimo di input superato. Massimo consentito: %d\n", MAX_INPUT);
		return -1;
	}

	int dati_input[MAX_INPUT] = {0};
	int dati_ordinati[MAX_INPUT] = {0};
	int num_dati = 0;

	estrai_dati(argc, argv, dati_input, &num_dati);
	ordina_dati(dati_input, num_dati, dati_ordinati);  // Passaggio corretto di num_dati
	stampa_vettore(dati_ordinati, num_dati);

	return 0;
}