#include "linked_list.h"
#include <stdio.h>   // For printf
#include <stdlib.h>  // For malloc/free
#include <string.h>  // For memcpy

// Creates a new node with the provided data
// Demonstrates:
// - Dynamic memory allocation with malloc()
// - Error checking for malloc failures
// - Memory copying with memcpy
// - Return of pointer type
Node *create_node(void *data, size_t data_size) {
    // Allocate memory for the node structure
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        return NULL;  // malloc failed
    }

    // Allocate memory for the data
    new_node->data = malloc(data_size);
    if (new_node->data == NULL) {
        free(new_node);  // Clean up previously allocated memory
        return NULL;
    }

    // Copy the data into the newly allocated memory
    memcpy(new_node->data, data, data_size);
    new_node->data_size = data_size;
    new_node->next = NULL;

    return new_node;
}

// Appends a new node to the end of the list
// Demonstrates:
// - Pass by reference (Node** head)
// - Pointer traversal
// - Error handling
void append_node(Node **head, void *data, size_t data_size) {
    Node *new_node = create_node(data, data_size);
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // If list is empty, make new node the head
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    // Traverse to end of list
    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Frees all memory associated with the list
// Demonstrates:
// - Memory deallocation
// - List traversal
// - Proper cleanup order (data first, then node)
void free_list(Node *head) {
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp->data);  // Free the data first
        free(temp);        // Then free the node
    }
}

// Reverses the linked list in place
// Demonstrates:
// - Pass by reference for list modification
// - Complex pointer manipulation
// - In-place algorithm implementation
void reverse_list(Node **head) {
    Node *prev = NULL, *current = *head, *next = NULL;

    while (current != NULL) {
        next = current->next;     // Store next
        current->next = prev;     // Reverse current node's pointer
        prev = current;           // Move prev to current
        current = next;           // Move current to next
    }

    *head = prev;  // Update head to new start
}