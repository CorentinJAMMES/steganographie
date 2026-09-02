#include "../lib/bmpreader.h"
#include <stdlib.h>

int copy_bmp(const char *input_path, const char *output_path) {
    // 1. Déclare deux pointeurs de type FILE (un pour la lecture, un pour l'écriture).

    // 2. Ouvre 'input_path' en mode lecture binaire ("rb").
    // Vérifie si l'ouverture a réussi (si le pointeur est égal à NULL).
    // Si c'est NULL, affiche une erreur (perror) et retourne 1.

    // 3. Ouvre 'output_path' en mode écriture binaire ("wb").
    // Vérifie si l'ouverture a réussi. Pense à fermer le fichier d'entrée avant de 
    // retourner 1 si cette étape échoue (pour éviter les fuites de mémoire).

    // 4. Déclare un tableau statique de 54 octets (utilise le type unsigned char) 
    // pour stocker l'en-tête de l'image BMP.

    // 5. Utilise 'fread' pour lire exactement 54 octets depuis ton fichier d'entrée 
    // et les stocker dans ton tableau.
    // Vérifie que 'fread' retourne bien la valeur 54. Sinon, ferme les fichiers et retourne 1.

    // 6. Utilise 'fwrite' pour écrire le contenu de ce tableau directement dans 
    // ton fichier de sortie.

    // 7. Déclare une variable de type 'int' (et non char, car la macro EOF est un entier négatif) 
    // pour stocker temporairement chaque pixel lu.

    // 8. Crée une boucle 'while' qui utilise 'fgetc' pour lire le fichier d'entrée octet par octet.
    // La boucle doit tourner tant que la valeur lue n'est pas égale à EOF.
    // À l'intérieur de la boucle, utilise 'fputc' pour écrire l'octet dans le fichier de sortie.

    // 9. Ferme proprement tes deux pointeurs de fichiers avec 'fclose'.

    return 0; // Tout s'est bien passé
}