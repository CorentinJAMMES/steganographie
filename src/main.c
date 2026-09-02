#include <stdio.h>
#include "../lib/bmpreader.h"
#include "../lib/stegano.h"

int main(int argc, char *argv[]) {
    // 1. Vérifie que l'utilisateur a fourni le bon nombre d'arguments.
    // Le programme s'attend à : ./stegano <source.bmp> <destination.bmp>
    // Si argc est différent de 3, affiche un message expliquant l'utilisation 
    // correcte du programme, puis retourne 1.

    // 2. Récupère les noms de fichiers depuis argv pour plus de clarté
    // Exemple : const char *fichier_source = argv[1];
    
    // 3. Appelle ta fonction 'copy_bmp' en lui passant les deux noms de fichiers.
    // Tu peux stocker son résultat (0 ou 1) dans une variable 'int resultat'.

    // 4. Si la fonction a réussi (retourne 0), affiche un message de succès confirmant 
    // que la copie est terminée.

    return 0;
}