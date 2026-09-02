#include <stdio.h>
#include "../include/bmpreader.h"
#include "../include/stegano.h"

int main(int argc, char *argv[]) {
    // 1. Vérifie que l'utilisateur a fourni le bon nombre d'arguments.
    // Le programme s'attend à : ./stegano <source.bmp> <destination.bmp>
    // Si argc est différent de 3, affiche un message expliquant l'utilisation 
    // correcte du programme, puis retourne 1.
    if(argc!=3){
        printf("Entrez le bon format de commande: \n ./stegano <source.bmp> <destination.bmp>\n");
        return 1;
    }
    // 2. Récupère les noms de fichiers depuis argv pour plus de clarté
    // Exemple : const char *fichier_source = argv[1];
    const char *fichier_source = argv[1];
    const char *fichier_receveur = argv[2];
    // 3. Appelle ta fonction 'copy_bmp' en lui passant les deux noms de fichiers.
    // Tu peux stocker son résultat (0 ou 1) dans une variable 'int resultat'.
    int res = copy_bmp(fichier_source,fichier_receveur);
    // 4. Si la fonction a réussi (retourne 0), affiche un message de succès confirmant 
    // que la copie est terminée.
    if(res == 1){
        printf("La copie a échoué veuillez réessayer et vérifier bien que l'image est au bon format.\n");
        return 1;
    }
    printf("L'image a été correctement copier.\n");
    return 0;
}