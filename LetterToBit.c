#include "LetterToBit.h"

void print_list(Element** list,FILE* file) {
    Element* temp;
    temp = *list;
    if (file != NULL) {
        while (temp != NULL) {
            fprintf(file, "%d", temp->data);
            temp = temp->next;
        }
    }
}

void decimal_to_binary(Element** list, int letter, int hexadecimal) {
    Element* temp;
    temp = *list;
    if (temp != NULL) {
        if (letter%hexadecimal != letter) {
            temp->data = 1;
            letter = letter-hexadecimal;
        }
        else {
            temp->data = 0;
        }
        decimal_to_binary(&((*temp).next), letter, hexadecimal/2);
    }
}

int number_character(FILE* file) {
    int i = -1;
    int actual_character = 0;
    rewind(file);
    while (actual_character != EOF) {
        actual_character = fgetc(file);
        i++;
    }
    return i;
}

void free_list(Element* list) {
    if (list != NULL) {
        free_list(list->next);
    }
    free(list);
}

int letter_to_bit () {
    Element *list = NULL;

    FILE* file_read = NULL;
    file_read = fopen("input.txt", "r");

    FILE* file_write = NULL;
    file_write = fopen("binary.txt", "w+");

    list = create_list(8);
    int letter=0;

    if ((file_read != NULL) && (file_write != NULL)) {
        while (letter != EOF) {
            letter = fgetc(file_read);
            if (letter != EOF) {
                decimal_to_binary(&list, letter, 128);
                print_list(&list, file_write);
            }
        }
        int character_read = number_character(file_read);
        if (character_read == 0){
                fclose(file_read);
                fclose(file_write);
                free_list(list);
            return 2;
        }
        printf("il y a %d charactere dans le fichier input.txt\n",character_read);
        int character_write = number_character(file_write);
        printf("il y a %d charactere dans le fichier binary.txt\n",character_write);
    }
    else {
        fclose(file_read);
        fclose(file_write);
        free_list(list);
        return 1;
    }
    fclose(file_read);
    fclose(file_write);
    free_list(list);
    return 0;
}
