#include <stdio.h>

#include "../include/bmpreader.h"
#include "../include/stegano.h"

int main(int argc, char* argv[]) {
  if (argc == 4) {  // on verifie que l'utilisateur respecte le format imposé
    const char* fichier_source = argv[1];
    const char* fichier_receveur = argv[2];

    int res = cacher_texte_bmp(fichier_source, fichier_receveur, argv[3]);

    if (res == 1) {
      printf(
          "La copie a échoué veuillez réessayer et vérifier bien que l'image "
          "est au bon format.\n");
      return 1;
    }
    printf("L'image a été correctement copier.\n");
    return 0;
  } else if (argc == 2) {
    const char* fichier_source = argv[1];
    int res = extraire_texte_bmp(fichier_source);
    if (res == 1) {
      printf(
          "L'extraction a échoué veuillez réessayer et vérifier bien que "
          "l'image est au bon format.\n");
      return 1;
    }
    printf("Le message a été correctement retranscrit.\n");
    return 0;
  }
  printf(
      "Entrez le bon format de commande: \n ./stegano <source.bmp> "
      "<destination.bmp> ''Votre message'' OU ./stegano <source.bmp>\n");
  return 1;
}