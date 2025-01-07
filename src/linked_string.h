/*
 * Header file for LinkedString - a string implementation using linked lists
 * Demonstrates:
 * - Building higher-level data structures on top of linked lists
 * - Separation of interface from implementation
 * - File I/O function declarations
 */

#ifndef LINKED_STRING_H
#define LINKED_STRING_H

#include "linked_list.h"

// LinkedString structure - demonstrates:
// - Composition (using Node* from linked_list.h)
// - Encapsulation of implementation details
typedef struct {
    Node* head;     // Pointer to first character
    size_t length;  // Cached length for O(1) access
} LinkedString;

// Core string operations
// All demonstrate use of opaque pointer type (LinkedString*)

// Creates an empty string - demonstrates dynamic allocation
LinkedString* create_linked_string(void);

// Appends a single character - demonstrates pass by reference
void append_to_string(LinkedString* str, char c);

// Conversion functions - demonstrate:
// - Working with C-style strings
// - Memory allocation for string conversion
LinkedString* from_char_array(const char* str);
char* to_char_array(const LinkedString* str);

// String manipulation
void reverse_string(LinkedString* str);
void free_linked_string(LinkedString* str);

// File I/O operations - demonstrate:
// - File handling function declarations
// - Use of const for input parameters
LinkedString* read_from_file(const char* filename);
void write_to_file(const LinkedString* str, const char* filename);

// String utility operations - demonstrate:
// - Standard string operations
// - Use of const for read-only parameters
void concat_strings(LinkedString* dest, const LinkedString* src);
int compare_strings(const LinkedString* str1, const LinkedString* str2);
size_t string_length(const LinkedString* str);

#endif