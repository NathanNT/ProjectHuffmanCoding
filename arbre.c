#include "arbre.h"
#include "occurence.h"
#include "dictionnaire.h"

void minimum(Node** t, int *position1, int *position2) {
    int minimum1=0;
    int minimum2=0;
    if (*t != NULL) {
        Node* buffer_minimum=NULL;
        buffer_minimum=*t;
        if (buffer_minimum->next != NULL) {
            minimum1=buffer_minimum->weight;
            minimum2=buffer_minimum->next->weight;
            for (int i=1;buffer_minimum != NULL;i++) {
                if ((buffer_minimum->weight < minimum1)&&(*position2 != i)) {
                    minimum1=buffer_minimum->weight;
                    *position1=i;
                }
                else if ((buffer_minimum->weight < minimum2)&&(*position1 != i)) {
                    minimum2=buffer_minimum->weight;
                    *position2=i;
                }
                buffer_minimum = buffer_minimum->next;
            }
        }
    }
    else {
        printf("Pas de minimum: liste vide");
    }
}

Node* tree_select(Node** tree, int position) {
    Node* buffer = NULL;
    buffer = *tree;
    for (int i=1; i != position; i++) {
        buffer = buffer->next;
    }
    return buffer;
}

void new_node_end(Node** tree, Node* node_right, Node* node_left) {
    if (*tree == NULL) {
        Node* new_node;
        new_node = (Node*)malloc(sizeof(Node));
        new_node->weight = node_right->weight + node_left->weight;
        new_node->character = '\0';
        new_node->next = NULL;
        new_node->right = node_right;
        new_node->left = node_left;
        *tree = new_node;
    }
    else{
        new_node_end (&((*tree)->next), node_right, node_left);
    }
}

void list_remove(Node** tree,int position) {
    Node* buffer = NULL;
    buffer = *tree;
    if (position == 1){
        buffer = *tree;
        *tree = (*tree)->next;
        buffer->next = NULL;
    }
    else{
        for (int i=2; i != position; i++) {
            buffer = buffer->next;
        }
        Node* temp = buffer->next->next;
        buffer->next = NULL;
        buffer->next = temp;
    }
}

void read_tree(Node* tree) {
    if (tree != NULL) {
        read_tree(tree->left);
        read_tree(tree->right);
        printf("%c : ",tree->character);
        printf("%d\n",tree->weight);
    }
}

void free_tree(Node* tree) {
    if (tree != NULL) {
        free_tree(tree->next);
        free_tree(tree->right);
        free_tree(tree->left);
        free(tree);
    }
}

Node* Tree_Huffman(Element_Chain* list, Node* tree) {
    tree = create_tree(list);
    if (tree->next != NULL){
        while (tree->next != NULL) {
            int pos1=1;
            int pos2=2;
            minimum(&tree,&pos1,&pos2);
            Node* nodeR = tree_select(&tree, pos1);
            Node* nodeL = tree_select(&tree, pos2);

            new_node_end(&tree, nodeR, nodeL);

            if (pos1 > pos2) {
                list_remove(&tree, pos1);
                list_remove(&tree, pos2);
            }
            else{
                list_remove(&tree, pos2);
                list_remove(&tree, pos1);
            }
            nodeR->next = NULL;
            nodeL->next = NULL;
        }
    }
    dictionary(tree);
    return tree;
}
