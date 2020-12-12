#include <stdio.h>
#include <stdlib.h>
#include "Huffman.h"

void Huffman() {
    FILE* file_read = NULL;
    file_read = fopen("input.txt", "r");

    FILE* file_dictionnary = NULL;
    file_dictionnary = fopen("dictionnary.txt", "r");

    FILE* file_write = NULL;
    file_write = fopen("Huffman.txt", "w+");

    char letter = '\0';

    if ((file_read != NULL) && (file_dictionnary != NULL) && (file_write != NULL)) {
        while (letter != EOF) {
            letter = fgetc(file_read);
            if (letter != EOF) {
                int wrong=0;
                wrong = write_Huff(file_dictionnary, file_write, letter);
                if (wrong == 0) {
                    printf("ca bug");
                    fclose(file_read);
                    fclose(file_dictionnary);
                    fclose(file_write);
                }
            }
        }
    }
    fclose(file_read);
    fclose(file_dictionnary);
    fclose(file_write);
}

int write_Huff(FILE* file_dictionnary, FILE* file_write, char letter) {
    char search_dic='\0';
    while (search_dic!=EOF) {
        search_dic = fgetc(file_dictionnary);
        if (search_dic == letter) {
            fseek(file_dictionnary, 2, SEEK_CUR);
            char bin[25]="";
            fgets(bin, 25, file_dictionnary);
            for (int i=1; bin[i]!='\0';i++) {
                fputc(bin[i-1],file_write);
            }
            rewind(file_dictionnary);
            return 1;
        }
        else{
            while (search_dic!='\n') {
                search_dic=fgetc(file_dictionnary);
            }
        }
    }
    return 0;
}
