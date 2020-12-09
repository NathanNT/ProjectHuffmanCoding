#include <stdio.h>
#include <stdlib.h>
#include "LetterToBit.h"
#include "occurence.h"
#include "arbre.h"
#include "Huffman.h"
#include "ReverseHuffman.h"
#include "initialization.h"

int main () {
    Node* tree = NULL;
    int error = 0;
    error = letter_to_bit();
    if (error == 0){
        tree = occurence(tree);

        Huffman();
        ReverseHuffman(tree);

        free_tree(tree);
    }
    else if (error == 1){
        printf("ERREUR : Le fichier input.txt n'existe pas");
    }
    else{
        printf("ERREUR : Le fichier input.txt est vide");
    }
}
