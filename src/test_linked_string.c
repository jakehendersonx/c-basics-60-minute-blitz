/*
 * Test suite for LinkedString implementation
 * Demonstrates:
 * - String manipulation testing
 * - File I/O testing
 * - Memory management in string operations
 * - Test organization for string operations
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "linked_string.h"

// Test empty string creation
// Demonstrates basic structure initialization testing
void test_create_empty_string(void) {
    LinkedString* str = create_linked_string();
    assert(str != NULL);
    assert(str->head == NULL);
    assert(str->length == 0);
    free_linked_string(str);
    printf("✓ Empty string creation test passed\n");
}

// Test string conversion
// Demonstrates:
// - C string to LinkedString conversion
// - Memory management
// - String comparison
void test_from_char_array(void) {
    const char* test_str = "Hello";
    LinkedString* str = from_char_array(test_str);
    assert(str != NULL);
    assert(str->length == strlen(test_str));
    
    char* result = to_char_array(str);
    assert(strcmp(result, test_str) == 0);
    
    free(result);
    free_linked_string(str);
    printf("✓ String conversion test passed\n");
}

// Test string reversal
// Demonstrates string manipulation verification
void test_reverse_string(void) {
    LinkedString* str = from_char_array("Hello");
    reverse_string(str);
    
    char* result = to_char_array(str);
    assert(strcmp(result, "olleH") == 0);
    
    free(result);
    free_linked_string(str);
    printf("✓ String reverse test passed\n");
}

// Test string concatenation
// Demonstrates:
// - Multiple string handling
// - Memory management for multiple strings
void test_concat_strings(void) {
    LinkedString* str1 = from_char_array("Hello ");
    LinkedString* str2 = from_char_array("World");
    
    concat_strings(str1, str2);
    char* result = to_char_array(str1);
    assert(strcmp(result, "Hello World") == 0);
    
    free(result);
    free_linked_string(str1);
    free_linked_string(str2);
    printf("✓ String concatenation test passed\n");
}

// Test file operations
// Demonstrates:
// - File I/O testing
// - Temporary file creation/cleanup
// - Content verification
void test_file_operations(void) {
    // Write test
    LinkedString* str = from_char_array("Test String");
    write_to_file(str, "test.txt");
    free_linked_string(str);
    
    // Read test
    LinkedString* read_str = read_from_file("test.txt");
    char* result = to_char_array(read_str);
    assert(strcmp(result, "Test String") == 0);
    
    // Cleanup
    free(result);
    free_linked_string(read_str);
    remove("test.txt");  // Clean up test file
    printf("✓ File operations test passed\n");
}

// Main test runner
// Demonstrates test organization
int main(void) {
    printf("Running LinkedString tests...\n");
    
    test_create_empty_string();
    test_from_char_array();
    test_reverse_string();
    test_concat_strings();
    test_file_operations();
    
    printf("All tests passed!\n");
    return 0;
}