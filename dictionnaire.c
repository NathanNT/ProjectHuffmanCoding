#include "dictionnaire.h"

void read_path_tree(Node* t, char path_translate[], int path_number, FILE* file_dictionary) {
    if (t->right == NULL && t->left == NULL) {
        print_path_tree(t->character, path_translate, path_number, file_dictionary);
    }
    else {
        path_translate[path_number]='0';
        path_number++;
        read_path_tree(t->left, path_translate, path_number, file_dictionary);
        path_number--;
        path_translate[path_number]='1';
        path_number++;
        read_path_tree(t->right, path_translate, path_number, file_dictionary);
    }
}

void print_path_tree(char letter, char path_translate[], int path_number, FILE* file_dictionary ){
    fprintf(file_dictionary,"%c :",letter);
    for (int i=0; i != path_number; i++) {
        fprintf(file_dictionary,"%c",path_translate[i]);
    }
    fprintf(file_dictionary,"\n");
}

void dictionary(Node* tree) {
    char path_translate[30];
    int path_number=0;

    FILE* file_dictionary = NULL;
    file_dictionary = fopen("dictionnary.txt", "w+");

    if (file_dictionary != NULL) {
        if (tree->right == NULL && tree->left == NULL){
            fprintf(file_dictionary,"%c :",tree->character);
            fprintf(file_dictionary,"%c",'0');
            fprintf(file_dictionary,"\n");
        }
        else{
            read_path_tree(tree, path_translate, path_number, file_dictionary);
        }
    }
    fclose(file_dictionary);
}
