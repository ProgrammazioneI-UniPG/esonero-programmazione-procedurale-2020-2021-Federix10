#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char M[128]; //dichiarazione di un array di caratteri
  int scelta = 0; //dichiarazione di una variabile di tipo integer con inizializzazione a 0
  char C[128];
  char K[128];
  int nextchar;
  void cripta(char C[], char M[], char K[]); //dichiarazione di una funzione di tipo void
  void decripta(char M[], char C[], char K[]);

  time_t t; //inizializzazione del generatore di numeri casuali con il tempo attuale
  srand( (unsigned) time(&t) );

  printf("Inserisci il testo da cifrare[max 128 caratteri]: ");
  fgets(M, 128, stdin); //la funzione fgets permette di ottenere in input stringhe, in questo caso da tastiera, impostando l'origine dalla quale la funzione deve leggere l'input (stdin = standard input). Inoltre è necessario inserire la variabile alla quale associare la stringa letta e il numero massimo di caratteri che la funzione può leggere
  fflush(stdin); //questa funzione permette di pulire il buffer in input
  printf("Il testo da cifrare inserito è: %s\n", M);

  do { //il ciclo do while permette di ripetere il contenuto nelle parentesi graffe ogni volta che la condizione all'interno del while è verificata
    printf("Digitare il metodo per la creazione della chiave di cifratura.\n");
    printf("[1]Per inserire la chiave manualmente;\n");
    printf("[2]Per generare una chiave casuale;\n");
    printf("[3]Per terminare l'esecuzione del programma.\n");
    printf("Scelta: ");
    scanf("%d", &scelta);

    do { //questo ciclo consente di pulire il buffer in input
      nextchar = getchar();
    } while (nextchar != '\n' && nextchar != EOF);

  } while (scelta != 1 && scelta != 2 && scelta != 3);

  if (scelta == 1) {
    do {
      printf("\nLa chiave deve avere una lunghezza uguale o superiore al testo da cifrare inserito precedentemente.\n");
      printf("Chiave: ");
      fgets(K, 128, stdin);
      fflush(stdin);
    } while (strlen(K)<strlen(M));

    cripta(C, M, K); //in questo modo è possibile richiamare una funzione e passare i valori alla funzione tramite i parametri inseriti nelle parentesi

    printf("\n");

    decripta(M, C, K);

    printf("\n");

  }

  else if (scelta == 2) {

    for (int i = 0; i < strlen(M) - 1; i++) { //il ciclo for permette di ripetere il contenuto all'interno delle parentesi graffe finché la condizione legata alla variabile (in questo caso "i") è verificata
      K[i] = rand() % (128 - 32) + 32; //questa funzione permette di generare numeri casuali nell'intervallo di numeri presenti nelle parentesi tonde
    }

    printf("\nLa chiave generata è: ");

    for (int i = 0; i < strlen(M) - 1; i++) {
      printf("%c", K[i]);
    }

    printf("\n");

    cripta(C, M, K);

    printf("\n");

    decripta(M, C, K);

    printf("\n");
  }

  else if (scelta == 3) {
    printf("\nHai scelto di terminare il programma. Arrivederci!\n");
    return 0;
  }

  return 0;
}

void cripta(char C[], char M[], char K[]) {
  for(int i=0; i<strlen(M) - 1; i++) {
    C[i] = (char)(M[i] ^ K[i]); //il carattere ^ permette di eseguire l'operazione di xor
  }

  printf("\nTesto da cifrare: %s" , M);
  printf("\nChiave per la codifica: ");

  for (int i = 0; i<strlen(M) - 1; i++) {
    printf("%c", K[i]);
  }

  printf("\n\nTesto criptato: ");

  for(int i=0; i<strlen(M) -1; i++) {
    printf("%X ", C[i]); //la stampa di tipo %X permette di visualizzare i caratteri in esadecimale
  }
}

void decripta(char M[], char C[], char K[]) {
  printf("Testo decifrato: ");

  for(int i=0; i<strlen(M) - 1; i++) {
    C[i] = (char)(C[i] ^ K[i]);
  }

  for(int i=0; i<strlen(M) -1; i++) {
    printf("%c", C[i]);
  }
}
