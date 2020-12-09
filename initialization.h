#ifndef INITIALIZATION_H_INCLUDED
#define INITIALIZATION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int data;
    struct Element* next;
}Element;

typedef struct Element_Chain {
    char character;
    int data;
    struct Element_Chain* next;
}Element_Chain;

typedef struct Node{
    int weight;
    char character;
    struct Node* next;
    struct Node* right;
    struct Node* left;
}Node;

Element* create_element(int data);

Element* create_list(int n);

Element_Chain* create_element_chain(char car);

Node* create_node(Element_Chain* list);

Node* create_tree(Element_Chain* list);

#endif // INITIALIZATION_H_INCLUDED
