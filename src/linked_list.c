#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *create_node(void *data, size_t data_size) {
  Node *new_node = malloc(sizeof(Node));
  if (new_node == NULL) {
    return NULL;
  }

  new_node->data = malloc(data_size);
  if (new_node->data == NULL) {
    free(new_node);
    return NULL;
  }

  memcpy(new_node->data, data, data_size);
  new_node->data_size = data_size;
  new_node->next = NULL;

  return new_node;
}

void append_node(Node **head, void *data, size_t data_size) {
  Node *new_node = create_node(data, data_size);
  if (new_node == NULL) {
    printf("Memory allocation failed!\n");
    exit(1);
  }

  if (*head == NULL) {
    *head = new_node;
    return;
  }

  Node *current = *head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
}

void free_list(Node *head) {
  while (head != NULL) {
    Node *temp = head;
    head = head->next;
    free(temp->data);
    free(temp);
  }
}

void reverse_list(Node **head) {
  Node *prev = NULL, *current = *head, *next = NULL;

  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  *head = prev;
}
