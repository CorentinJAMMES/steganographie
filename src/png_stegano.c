#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/stb_image.h"
#include "../include/utilitaire.h"

int cacher_texte_png(const char* input_path, const char* output_path,
                     const char* secret) {
  int width;     // largeur
  int height;    // longueur
  int channels;  // cannaux

  unsigned char* pixels = stbi_load(input_path, &width, &height, &channels,
                                    0);  // ouverture d'un fichier png

  if (pixels == NULL) {
    printf(
        "Erreur lors du chargement du fichier veuiller réessayer et verifier "
        "le type de fichier.");
    return 1;
  }

  int i = 0;             // i eme pixel
  int count_letter = 0;  // n ieme lettre de la chaine secret
  int bit = 0;           // x ieme bit de la lettre n
  int dernier_bit = 0;   // le nouveau dernier bit (x)
  do {
    while (bit != 8) {
      pixels[i] = pixels[i] & 0xFE;  // on retire le dernier bit
      dernier_bit = (secret[count_letter] >> bit) &
                    1;  // on récupere le nouveau dernier bit
      pixels[i] = pixels[i] | dernier_bit;  // on remplace le dernier bit
      bit++;
      i++;
    }
    count_letter++;
    bit = 0;
  } while (secret[count_letter - 1] != '\0');  // jusqu'à \0 inclus

  stbi_write_png(output_path, width, height, channels, pixels,
                 width * channels);  // on écrit dans le nouveau fichier

  stbi_image_free(pixels);  // on libere la memoire pour fermer le fichier
  return 0;
}

int extraire_texte_png(const char* input_path) {
  int width;
  int height;
  int channels;

  unsigned char* pixels = stbi_load(input_path, &width, &height, &channels, 0);

  if (pixels == NULL) {
    printf(
        "Erreur lors du chargement du fichier veuiller réessayer et verifier "
        "le type de fichier.");
    return 1;
  }
  int i = 0;
  char letter = 'a';  // La lettre avec une valeur par défault
  int octet[8];       // Tableau de bit pour récupérer la lettre
  memset(octet, 0, sizeof(octet));
  int count = 0;        // Permet de savoir a quel bit nous en sommes
  int dernier_bit = 0;  // le dernier bit du pixel sur le quel nous travaillons

  while (letter != '\0') {
    while (count != 8) {
      dernier_bit = pixels[i] & 0x01;  // On ne veux que le dernier bit
      octet[count] = dernier_bit;      // Remplissage du tableau
      count++;
      i++;
    }
    letter = octet_to_letter(octet);
    printf("%c", letter);  // On affiche le message pour l'utilisateur
    count = 0;
    memset(octet, 0, sizeof(octet));
  }
  printf("\n");
  stbi_image_free(pixels);
  return 0;
}