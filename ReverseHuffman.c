#include "ReverseHuffman.h"

void ReverseHuffman(Node* tree) {
    FILE* file_read = NULL;
    file_read = fopen("Huffman.txt", "r");

    FILE* file_write = NULL;
    file_write = fopen("ReverseHuffman.txt", "w+");

    char letter = '\0';
    int sure = 1;

    if ((file_read != NULL) || (file_write != NULL)){
        if (tree->right == NULL && tree->left == NULL){
            one_character (tree, file_write, file_read, letter);
        }
        else{
            while (sure == 1){
                sure = find_character (tree, file_write, file_read, letter);
            //}
            }
        }
    fclose (file_read);
    fclose (file_write);
    }
}

int find_character (Node* tree, FILE* file_write, FILE* file_read, char letter){
    if (tree != NULL) {
        if (letter == EOF){
            return 0;
        }
        if (tree->character != '\0'){
            fputc(tree->character,file_write);
            return 1;
        }
        letter = fgetc(file_read);
        printf ("%c",letter);
        if (letter == '0'){
            return 0 + find_character (tree->left, file_write, file_read, letter);
        }
        else {
            return 0 + find_character (tree->right, file_write, file_read, letter);
        }
    }
    return 0;
}


void one_character (Node* tree, FILE* file_write, FILE* file_read, char letter){
    int i = 0;
    while (letter != EOF){
        letter = fgetc(file_read);
        i++;
    }
    rewind (file_read);
    for (int j=1; j<i;j++){
        letter = fgetc(file_read);
        fputc(tree->character,file_write);
    }
}
