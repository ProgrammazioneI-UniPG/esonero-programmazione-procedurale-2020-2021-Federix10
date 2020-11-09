#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char M[128]; //dichiarazione di un array di caratteri
  int scelta = 0;
  char C[128];
  char K[128];
  int nextchar;
  void cripta(char C[], char M[], char K[]);
  void decripta(char M[], char C[], char K[]);

  time_t t;
  srand( (unsigned) time(&t) );

  printf("Inserisci il testo da cifrare[max 128 caratteri]: ");
  fgets(M, 128, stdin);
  fflush(stdin);
  printf("Il testo da cifrare inserito è: %s\n", M);

  do {
    printf("Digitare il metodo per la creazione della chiave di cifratura.\n");
    printf("[1]Per inserire la chiave manualmente;\n");
    printf("[2]Per generare una chiave casuale.\n");
    printf("Scelta: ");
    scanf("%d", &scelta);

    do {
      nextchar = getchar();
    } while (nextchar != '\n' && nextchar != EOF);

  } while (scelta != 1 && scelta != 2);

  if (scelta == 1) {
    do {
      printf("\nLa chiave deve avere una lunghezza uguale o superiore al testo da cifrare inserito precedentemente.\n");
      printf("Chiave: ");
      fgets(K, 128, stdin);
      fflush(stdin);
    } while (strlen(K)<strlen(M));

    cripta(C, M, K);

    printf("\n");

    decripta(M, C, K);

    printf("\n");

  }

  else if (scelta == 2) {

    for (int i = 0; i < strlen(M) - 1; i++) {
      K[i] = rand() % (128 - 32) + 32;
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

  return 0;
}

void cripta(char C[], char M[], char K[]) {
  for(int i=0; i<strlen(M) - 1; i++) {
    C[i] = (char)(M[i] ^ K[i]);
  }

  printf("\nTesto da cifrare: %s" , M);
  printf("\nChiave per la codifica: ");

  for (int i = 0; i<strlen(M) - 1; i++) {
    printf("%c", K[i]);
  }

  printf("\n\nTesto criptato: ");

  for(int i=0; i<strlen(M) -1; i++) {
    printf("%X ", C[i]);
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
