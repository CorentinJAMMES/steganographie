#include "../include/utilitaire.h"

int puissance(int number, int puissance) {
  /* Permet de calculer le resultat de n'importe quel int puissance un autre*/
  int res = 1;
  for (int i = 0; i < puissance; i++) {
    res *= number;
  }
  return res;
}

char octet_to_letter(int tab[8]) {
/* Permet de transformer un tableau de bit (int 0 ou 1) en char*/
  char res = 0;
  for (int i = 0; i < 8; i++) {
    res += tab[i] * (puissance(2, i));
  }
  return res;
}