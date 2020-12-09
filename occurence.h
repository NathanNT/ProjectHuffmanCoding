#ifndef OCCURENCE_H_INCLUDED
#define OCCURENCE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "initialization.h"

Node* occurence(Node* tree);

void list_position(Element_Chain** list, char character);

void new_element_end(Element_Chain** l, char character);

Element_Chain* create_element_chain(char character);

void read_list(Element_Chain* list);

void free_list_chain(Element_Chain* list);

#endif // OCCURENCE_H_INCLUDED
