/*
 * Test suite for linked list implementation
 * Demonstrates:
 * - Unit testing in C
 * - Assert macro usage
 * - Memory management in tests
 * - Test organization
 */

#include "linked_list.h"
#include <assert.h>  // For assert macro
#include <stdio.h>   // For printf
#include <stdlib.h>  // For memory operations

// Test creation of empty list
// Demonstrates basic assertion
void test_create_empty_list(void) {
    Node *head = NULL;
    assert(head == NULL);
    printf("✓ Empty list creation test passed\n");
}

// Test appending a single integer
// Demonstrates:
// - Memory allocation testing
// - Pointer dereferencing
// - Type casting from void*
void test_append_single_int(void) {
    Node *head = NULL;
    int value = 42;
    append_node(&head, &value, sizeof(int));

    // Test list structure
    assert(head != NULL);
    assert(*(int *)head->data == 42);
    assert(head->next == NULL);

    // Clean up
    free_list(head);
    printf("✓ Single int append test passed\n");
}

// Test appending multiple integers
// Demonstrates:
// - Array usage
// - List traversal
// - Multiple assertions
void test_append_multiple_ints(void) {
    Node *head = NULL;
    int values[] = {1, 2, 3};

    // Build test list
    for (int i = 0; i < 3; i++) {
        append_node(&head, &values[i], sizeof(int));
    }

    // Verify list contents
    Node *current = head;
    for (int i = 0; i < 3; i++) {
        assert(current != NULL);
        assert(*(int *)current->data == values[i]);
        current = current->next;
    }
    assert(current == NULL);  // Verify end of list

    // Clean up
    free_list(head);
    printf("✓ Multiple int append test passed\n");
}

// Test list reversal
// Demonstrates:
// - Complex list operation testing
// - Array comparison
void test_reverse_list(void) {
    Node *head = NULL;
    int values[] = {1, 2, 3};
    int reversed[] = {3, 2, 1};

    // Build test list
    for (int i = 0; i < 3; i++) {
        append_node(&head, &values[i], sizeof(int));
    }

    // Perform reversal
    reverse_list(&head);

    // Verify reversed contents
    Node *current = head;
    for (int i = 0; i < 3; i++) {
        assert(current != NULL);
        assert(*(int *)current->data == reversed[i]);
        current = current->next;
    }

    // Clean up
    free_list(head);
    printf("✓ List reverse test passed\n");
}

// Main test runner
// Demonstrates:
// - Test organization
// - Error reporting
int main(void) {
    printf("Running tests...\n");
    test_create_empty_list();
    test_append_single_int();
    test_append_multiple_ints();
    test_reverse_list();
    printf("All tests passed!\n");
    return 0;
}