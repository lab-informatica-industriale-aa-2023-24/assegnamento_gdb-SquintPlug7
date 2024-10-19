#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 10

// Funzione per estrarre i dati dai parametri in ingresso
void estrai_dati(int ac, char **av, int *vett, int *lung)
{
    *lung = ac - 1;  // Calcola la lunghezza basata sul numero di argomenti

    for (int i = 0; i < *lung; ++i)
        vett[i] = atoi(av[i + 1]);  // Converti l'argomento in intero e salvalo nell'array
}

// Funzione per fare spazio nell'array
void fai_spazio(int posizione, int *vett, int lung)
{
    for (int j = lung; j > posizione; --j)  // Sposta tutti gli elementi a destra
        vett[j] = vett[j - 1];
}

// Funzione per inserire il nuovo dato nella posizione corretta
void inserisci(int nuovo_dato, int num_dati_ord, int *vett)
{
    int i;

    // Cerca la posizione in cui inserire il nuovo dato
    for (i = 0; i < num_dati_ord; ++i) {
        if (nuovo_dato < vett[i]) {
            fai_spazio(i, vett, num_dati_ord);  // Crea spazio per il nuovo dato
            vett[i] = nuovo_dato;
            return;
        }
    }

    // Se il nuovo dato è il più grande, inseriscilo in fondo
    vett[num_dati_ord] = nuovo_dato;
}

// Funzione per ordinare i dati usando l'insertion sort
void ordina_dati(const int *dati_non_ordinati, int num_dati, int *dati_ordinati)
{
    // Inserisci ciascun elemento non ordinato nell'array ordinato
    for (int i = 0; i < num_dati; ++i) {
        inserisci(dati_non_ordinati[i], i, dati_ordinati);
    }
}

// Funzione per stampare il vettore ordinato
void stampa_vettore(const int *vett, int lung)
{
    for (int i = 0; i < lung; ++i)
        printf("%d ", vett[i]);  // Stampa ogni elemento dell'array ordinato
    printf("\n");
}

int main(int argc, char **argv)
{
    // Controlla se il numero di input supera il limite massimo
    if (argc > MAX_INPUT + 1) {
        printf("Numero massimo di input %d\n", MAX_INPUT);
        return -1;
    }

    int dati_input[MAX_INPUT] = {0};  // Array per memorizzare i dati in ingresso
    int dati_ordinati[MAX_INPUT] = {0};  // Array per memorizzare i dati ordinati
    int num_dati = 0;  // Numero di dati inseriti

    estrai_dati(argc, argv, dati_input, &num_dati);  // Estrai i dati dagli argomenti
    ordina_dati(dati_input, num_dati, dati_ordinati);  // Ordina i dati
    stampa_vettore(dati_ordinati, num_dati);  // Stampa il vettore ordinato

    return 0;
}
