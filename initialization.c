#include "initialization.h"

Element* create_element(int data) {
    Element* new_element = NULL;
    new_element = (Element*)malloc(sizeof(Element));
    new_element->data = data;
    new_element->next = NULL;
    return new_element;
}

Element* create_list(int n) {
    if (n <= 0) {
        return NULL;
    }
    else {
        Element* new_element = create_element(0);
        new_element->next = create_list(n-1);
        return new_element;
    }
}

Element_Chain* create_element_chain(char character) {
    Element_Chain* new_elelement;
    new_elelement = (Element_Chain*)malloc(sizeof(Element_Chain));
    new_elelement->data = 1;
    new_elelement->character = character;
    new_elelement->next = NULL;
    return new_elelement;
}

Node* create_tree(Element_Chain* list) {
    if (list != NULL) {
        Node* new_node = create_node(list);
        new_node->next = create_tree(list->next);
        return new_node;
    }
    return NULL;
}

Node* create_node(Element_Chain* list) {
    Node* new_node;
    new_node = (Node*)malloc(sizeof(Node));
    new_node->weight = list->data;
    new_node->character = list->character;
    new_node->next = NULL;
    new_node->right = NULL;
    new_node->left = NULL;
    return new_node;
}
