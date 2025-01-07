#include "linked_list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_create_empty_list(void) {
  Node *head = NULL;
  assert(head == NULL);
  printf("✓ Empty list creation test passed\n");
}

void test_append_single_int(void) {
  Node *head = NULL;
  int value = 42;
  append_node(&head, &value, sizeof(int));

  assert(head != NULL);
  assert(*(int *)head->data == 42);
  assert(head->next == NULL);

  free_list(head);
  printf("✓ Single int append test passed\n");
}

void test_append_multiple_ints(void) {
  Node *head = NULL;
  int values[] = {1, 2, 3};

  for (int i = 0; i < 3; i++) {
    append_node(&head, &values[i], sizeof(int));
  }

  Node *current = head;
  for (int i = 0; i < 3; i++) {
    assert(current != NULL);
    assert(*(int *)current->data == values[i]);
    current = current->next;
  }
  assert(current == NULL);

  free_list(head);
  printf("✓ Multiple int append test passed\n");
}

void test_reverse_list(void) {
  Node *head = NULL;
  int values[] = {1, 2, 3};
  int reversed[] = {3, 2, 1};

  for (int i = 0; i < 3; i++) {
    append_node(&head, &values[i], sizeof(int));
  }

  reverse_list(&head);

  Node *current = head;
  for (int i = 0; i < 3; i++) {
    assert(current != NULL);
    assert(*(int *)current->data == reversed[i]);
    current = current->next;
  }

  free_list(head);
  printf("✓ List reverse test passed\n");
}

int main(void) {
  printf("Running tests...\n");
  test_create_empty_list();
  test_append_single_int();
  test_append_multiple_ints();
  test_reverse_list();
  printf("All tests passed!\n");
  return 0;
}
