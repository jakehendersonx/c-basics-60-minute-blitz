/*
 * Header file defining the generic linked list data structure and operations.
 * Demonstrates:
 * - Struct definition with self-referential pointer
 * - Generic programming using void pointers
 * - Function prototypes with pointer parameters
 */

#ifndef LINKED_LIST_H  // Header guard to prevent multiple inclusion
#define LINKED_LIST_H

#include <stdlib.h>  // Required for size_t definition

// Node struct definition - demonstrates:
// - Self-referential structure (struct Node contains pointer to struct Node)
// - Generic data storage using void pointer
// - Use of size_t for memory-safe size tracking
typedef struct Node {
    void* data;         // Void pointer for generic data storage
    size_t data_size;   // Size of the stored data
    struct Node* next;  // Pointer to next node (self-referential)
} Node;

// Function prototypes

// Creates a new node - demonstrates dynamic memory allocation
Node* create_node(void* data, size_t data_size);

// Appends a node to the list - demonstrates pass by reference (Node**)
void append_node(Node** head, void* data, size_t data_size);

// Frees all memory in the list - demonstrates memory management
void free_list(Node* head);

// Reverses the list - demonstrates pass by reference for list modification
void reverse_list(Node** head);

#endif