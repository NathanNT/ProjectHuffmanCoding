#ifndef LETTERTOBIT_H_INCLUDED
#define LETTERTOBIT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "initialization.h"

void print_list(Element** list,FILE* file);

void decimal_to_binary(Element** list,int letter,int hex);

int number_character(FILE* file);

void free_list(Element* l);

int letter_to_bit();

#endif // LETTERTOBIT_H_INCLUDED
