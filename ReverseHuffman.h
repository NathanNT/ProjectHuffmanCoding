#ifndef REVERSEHUFFMAN_H_INCLUDED
#define REVERSEHUFFMAN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "initialization.h"

void ReverseHuffman (Node* tree);

void one_character (Node* tree, FILE* file_write, FILE* file_read, char letter);

int find_character (Node* tree, FILE* file_write, FILE* file_read, char letter);

#endif // REVERSEHUFFMAN_H_INCLUDED
