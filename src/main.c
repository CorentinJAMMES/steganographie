#include <stdio.h>
#include <string.h>

#include "../include/bmpreader.h"
#include "../include/png_stegano.h"
#include "../include/stegano.h"

int main(int argc, char* argv[]) {
  if (argc == 5) {  // on verifie que l'utilisateur respecte le format imposé
                    // pour l'ecriture du message
    const char* fichier_source = argv[2];
    const char* fichier_receveur = argv[3];
    if (strcmp(argv[1], "bmp") ==
        0) {  // on verifie le format de l'image (bmp ou png)
      int res = cacher_texte_bmp(fichier_source, fichier_receveur, argv[4]);

      if (res == 1) {
        printf(
            "La copie a échoué veuillez réessayer et vérifier bien que l'image "
            "est au bon format.\n");
        return 1;
      }
      printf("L'image a été correctement copier.\n");
      return 0;
    } else if (strcmp(argv[1], "png") == 0) {
      int res = cacher_texte_png(fichier_source, fichier_receveur, argv[4]);
      if (res == 1) {
        printf(
            "La copie a échoué veuillez réessayer et vérifier bien que l'image "
            "est au bon format.\n");
        return 1;
      }
      printf("L'image a été correctement copier.\n");
      return 0;
    }
  } else if (argc == 3) {  // on verifie que l'utilisateur respecte le format
                           // imposé pour l'extraction du message
    const char* fichier_source = argv[2];
    if (strcmp(argv[1], "bmp") == 0) {
      int res = extraire_texte_bmp(fichier_source);
      if (res == 1) {
        printf(
            "L'extraction a échoué veuillez réessayer et vérifier bien que "
            "l'image est au bon format.\n");
        return 1;
      }
      printf("Le message a été correctement retranscrit.\n");
      return 0;
    } else if (strcmp(argv[1], "png") == 0) {
      int res = extraire_texte_png(fichier_source);
      if (res == 1) {
        printf(
            "L'extraction a échoué veuillez réessayer et vérifier bien que "
            "l'image est au bon format.\n");
        return 1;
      }
      printf("Le message a été correctement retranscrit.\n");
      return 0;
    }
  }
  printf(
      "Entrez le bon format de commande: \n ./stegano <type de fichier d'image "
      "(bmp/png)> <source.bmp> <destination.bmp> ''Votre message'' OU "
      "./stegano <type de fichier d'image (bmp/png)> <source.bmp>\n");
  return 1;
}