#ifndef INATILIZATION_H_INCLUDED
#define INATILIZATION_H_INCLUDED

typedef struct Element {
    int data;
    struct Element* next;
}Element;

Element* create_el(int data);

Element* create_list(int n);

#endif // INATILIZATION_H_INCLUDED
