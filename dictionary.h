#ifndef DICTIONARY_H
#define DICTIONARY_H
#define MAX_LENGTH 100

struct Word_Dict {
    char word[MAX_LENGTH];
    char explanation[MAX_LENGTH];
    struct Word_Dict* next;
};

struct Word_Dict* dictionary = NULL;

void lst_Word() {
    struct Word_Dict* new_Word_Dict = malloc(sizeof(struct Word_Dict));
    printf("Entrez un mot : ");
    scanf("%s", new_Word_Dict->word);

    // Check that the input word only contains French letters
    char* allowed_chars = "abcdefghijklmnopqrstuvwxyzàâçéèêëîïôûùüÿñ";
    for (int i = 0; i < strlen(new_Word_Dict->word); i++) {
        if (strchr(allowed_chars, tolower(new_Word_Dict->word[i])) == NULL) {
            printf("Le mot ne contient pas uniquement des lettres françaises.\n");
            return;
        }
    }

    printf("Entrez une définition : ");
    scanf("%s", new_Word_Dict->explanation);

    // Find the position in the linked list where the new Word_Dict should be inserted
    struct Word_Dict* previous_Word_Dict = NULL;
    struct Word_Dict* current_Word_Dict = dictionary;
    while (current_Word_Dict != NULL && strcmp(new_Word_Dict->word, current_Word_Dict->word) > 0) {
        previous_Word_Dict = current_Word_Dict;
        current_Word_Dict = current_Word_Dict->next;
    }

    // Insert the new Word_Dict into the linked list
    if (previous_Word_Dict == NULL) {
        // The new Word_Dict should be inserted at the beginning of the list
        new_Word_Dict->next = dictionary;
        dictionary = new_Word_Dict;
    } else {
        // The new Word_Dict should be inserted between previous_Word_Dict and current_Word_Dict
        new_Word_Dict->next = current_Word_Dict;
        previous_Word_Dict->next = new_Word_Dict;
    }

    printf("Le mot a été ajouté au dictionnaire.\n");
}



void search_Word_Dict() {
    char search_word[MAX_LENGTH];
    printf("Entrez un mot à chercher : ");
    scanf("%s", search_word);

    struct Word_Dict* current_Word_Dict = dictionary;
    while (current_Word_Dict != NULL) {
        if (strcmp(search_word, current_Word_Dict->word) == 0) {
            printf("%s : %s\n", current_Word_Dict->word, current_Word_Dict->explanation);
            return;
        }
        current_Word_Dict = current_Word_Dict->next;
    }

    printf("Le mot n'a pas été trouvé dans le dictionnaire.\n");
}

void display_all() {
    struct Word_Dict* current_Word_Dict = dictionary;
    while (current_Word_Dict != NULL) {
        printf("%s : %s\n", current_Word_Dict->word, current_Word_Dict->explanation);
        current_Word_Dict = current_Word_Dict->next;
    }
}

void free_memory() {
    struct Word_Dict* current_Word_Dict = dictionary;
    while (current_Word_Dict != NULL) {
        struct Word_Dict* next_Word_Dict = current_Word_Dict->next;
        free(current_Word_Dict);
        current_Word_Dict = next_Word_Dict;
    }
}

void delete_Word_Dict() {
    char search_word[MAX_LENGTH];
    printf("Entrez le mot à supprimer : ");
    scanf("%s", search_word);

    struct Word_Dict* previous_Word_Dict = NULL;
    struct Word_Dict* current_Word_Dict = dictionary;

    while (current_Word_Dict != NULL) {
        if (strcmp(search_word, current_Word_Dict->word) == 0) {
            if (previous_Word_Dict == NULL) {
                dictionary = current_Word_Dict->next;
            } else {
                previous_Word_Dict->next = current_Word_Dict->next;
            }
            free(current_Word_Dict);
            printf("Le mot a été supprimé du dictionnaire.\n");
            return;
        }
        previous_Word_Dict = current_Word_Dict;
        current_Word_Dict = current_Word_Dict->next;
    }

    printf("Le mot n'a pas été trouvé dans le dictionnaire.\n");
}