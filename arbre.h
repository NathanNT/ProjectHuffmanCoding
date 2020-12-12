#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED
#include "occurence.h"

void minimum(Node** t, int *position1, int *position2);

Node* tree_select(Node** tree, int position);

void new_node_end(Node** tree, Node* node_right, Node* node_left);

void list_remove(Node** tree,int position);

void read_tree(Node* tree);

void free_tree(Node* tree);

Node* Tree_Huffman(Element_Chain* list, Node* tree);

#endif // ARBRE_H_INCLUDED
