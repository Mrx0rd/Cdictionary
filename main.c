#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"
#include <ctype.h>

int main() {
    int choice;

    while (1) {
        printf("||============*OPTIONS*============||\n");
        printf("||=================================||\n");
        printf("||1. Ajouter une entrée            ||\n");  
        printf("||2. Rechercher une entrée         ||\n");
        printf("||3. Afficher toutes les entrées   ||\n");
        printf("||4. Supprimer une entrée          ||\n");
        printf("||5. Quitter le programme          ||\n");
        printf("||=================================||\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                lst_Word();
                break;
            case 2:
                search_Word_Dict();
                break;
            case 3:
                display_all();
                break;
            case 4:
                delete_Word_Dict();
                break;
            case 5:
                free_memory();
        
                
            default:
            
                printf("Choix invalide ! choisir de 1 à 5.\n");
        }
    }
}
