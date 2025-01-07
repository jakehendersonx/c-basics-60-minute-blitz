#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

typedef struct Node {
    void* data;
    size_t data_size;
    struct Node* next;
} Node;

Node* create_node(void* data, size_t data_size);
void append_node(Node** head, void* data, size_t data_size);
void free_list(Node* head);
void reverse_list(Node** head);

#endif
