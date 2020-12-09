#include "inatilization.h"

Element* create_el(int data) {
    Element* new_el = NULL;
    new_el = (Element*)malloc(sizeof(Element));
    new_el->data = data;
    new_el->next = NULL;
    return new_el;
}
