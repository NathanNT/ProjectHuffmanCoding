#ifndef DICTIONNAIRE_H_INCLUDED
#define DICTIONNAIRE_H_INCLUDED
#include "arbre.h"

void dictionary(Node* tree);

void read_path_tree(Node* t, char path_translate[], int path_number, FILE* file_dictionnary);

void print_path_tree(char letter, char path_translate[], int path_number, FILE* file_dictionnary);

#endif // DICTIONNAIRE_H_INCLUDED
