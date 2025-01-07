

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// TODO:
typedef struct Node {
  char data;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
  size_t length;
} String;

// TODO: what are prototypes
