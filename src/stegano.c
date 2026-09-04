#include "../include/stegano.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/utilitaire.h"
int cacher_texte_bmp(const char* input_path, const char* output_path,
                     const char* secret) {
  FILE* input_file = NULL;
  FILE* output_file = NULL;

  input_file = fopen(input_path, "rb");
  if (input_file == NULL)
    return 1;  // si l'ouverture du fichier echoue on renvoie une erreur

  output_file = fopen(output_path, "wb");
  if (output_file ==
      NULL) {  // si l'ouverture du fichier echoue on renvoie une erreur
    fclose(input_file);
    return 1;
  }

  unsigned char header[54];

  if (fread(header, 1, 54, input_file) !=
      54) {  // on lit les 54 premiers octets du fichier car ils ne contiennent
             // que des informations importantes sur le fichier donc on ne peux
             // pas les modifiés sous risque de casser la copie
    fclose(input_file);
    fclose(output_file);
    return 1;
  }

  fwrite(header, 1, 54, output_file);

  int count_letter = 0;  // permettra de savoir a quelle lettre nous en serons
                         // au fur et a mesure
  int count_to_octet =
      0;           // idem pour savoir a quel bit de la lettre nous en somme
  int pixel_actu;  // le pixel que nous sommes en train de modifié
  int dernier_bit = 0;  // le dernier bit du pixel sur le quel nous travaillons

  do {
    while (count_to_octet != 8) {
      pixel_actu = fgetc(input_file);  // on recupere les pixels de l'image tant
                                       // que le message n'est pas transmis
      if (pixel_actu == EOF) {
        printf(
            "Erreur l'image est trop petite pour ce message veuiller adapter "
            "la taille du message a celle de l'image\n");
        return 1;
      }
      dernier_bit = (secret[count_letter] >> count_to_octet) &
                    1;  // on récupère uniquement le bit correspondant de la
                        // lettre à la quelle nous en somme
      pixel_actu = pixel_actu & 0xFE;  // on met le dernier bit a zéro en vu de
                                       // le remplacer juste après
      pixel_actu =
          pixel_actu |
          dernier_bit;  // on fait un ou pour que le dernier bit correspond
                        // désormais au bit actuel de la lettre
      fputc(pixel_actu, output_file);
      count_to_octet++;
    }
    count_to_octet = 0;
    count_letter++;
  } while (secret[count_letter - 1] !=
           '\0');  // count_letter-1 car on veux écrire le \0 pour savoir quand
                   // s'arreter sur le décodeur

  int pixel;

  do {
    pixel = fgetc(input_file);
    if (pixel != EOF) fputc(pixel, output_file);
  } while (pixel != EOF);  // on finit l'ensemble des pixels de l'image

  fclose(input_file);
  fclose(output_file);
  return 0;
}

int extraire_texte_bmp(const char* input_path) {
  FILE* input_file = NULL;

  input_file = fopen(input_path, "rb");
  if (input_file == NULL) {
    return 1;
  }

  unsigned char header[54];

  if (fread(header, 1, 54, input_file) !=
      54) {  // On ignore toujours les 54 premiers bits
    fclose(input_file);
    return 1;
  }
  char letter = 'a';  // La lettre avec une valeur par défault
  int octet[8];       // Tableau de bit pour récupérer la lettre
  memset(octet, 0, sizeof(octet));
  int count = 0;        // Permet de savoir a quel bit nous en sommes
  int pixel_actu;       // le pixel que nous sommes en train de modifié
  int dernier_bit = 0;  // le dernier bit du pixel sur le quel nous travaillons

  while (letter != '\0') {
    while (count != 8) {
      pixel_actu = fgetc(input_file);
      dernier_bit = pixel_actu & 0x01;  // On ne veux que le dernier bit
      octet[count] = dernier_bit;       // Remplissage du tableau
      count++;
    }
    letter = octet_to_letter(octet);
    printf("%c", letter); // On affiche le message pour l'utilisateur
    count = 0;
    memset(octet, 0, sizeof(octet));
  }
  printf("\n");
  fclose(input_file);
  return 0;
}
