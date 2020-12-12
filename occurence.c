#include "occurence.h"
#include "arbre.h"

void list_position(Element_Chain** list, char character) {
    Element_Chain* buffer=NULL;
    buffer= *list;
    if (buffer == NULL) {
        new_element_end(list, character);
    }
    else if (character == buffer->character) {
        (buffer->data)++;
    }
    else {
        list_position(&((*buffer).next), character);
    }
}

void new_element_end(Element_Chain** list,char character) {
    if (*list == NULL) {
        *list = create_element_chain(character);
    }
    else {
        new_element_end(&((*list)->next),character);
    }
}

void read_list(Element_Chain* list) {
    if (list != NULL) {
        printf("%c",list->character);
        printf(" : %d\n",list->data);
        read_list(list->next);
    }
}

void free_list_chain(Element_Chain* list) {
    if (list != NULL) {
        free_list_chain(list->next);
        free(list);
    }
}

Node* occurence(Node* tree) {
    Element_Chain *list = NULL;

    FILE* file_read = NULL;
    file_read = fopen("input.txt", "r");

    int letter=0;
    if (file_read != NULL) {
        while (letter != EOF) {
            letter = fgetc(file_read);
            if (letter != EOF) {
                list_position(&list, letter);
            }
        }
        tree = Tree_Huffman(list, tree);
    }

    //read_list (list);

    fclose(file_read);
    free_list_chain(list);
    return tree;
}

