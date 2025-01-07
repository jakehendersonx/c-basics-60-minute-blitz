#include <stdio.h>   // For file operations
#include <stdlib.h>  // For malloc/free
#include <string.h>  // For string operations
#include "linked_string.h"

// Creates a new empty LinkedString
// Demonstrates:
// - Dynamic memory allocation
// - Initialization of struct members
LinkedString* create_linked_string(void) {
   LinkedString* str = malloc(sizeof(LinkedString));
   if (str == NULL) return NULL;
   str->head = NULL;
   str->length = 0;
   return str;
}

// Appends a single character to the string
// Demonstrates:
// - Pass by reference
// - Use of underlying linked list functions
void append_to_string(LinkedString* str, char c) {
   append_node(&str->head, &c, sizeof(char));
   str->length++;
}

// Creates a LinkedString from a C-style string
// Demonstrates:
// - String traversal
// - Character-by-character processing
// - NULL terminator handling
LinkedString* from_char_array(const char* str) {
   LinkedString* ls = create_linked_string();
   if (ls == NULL) return NULL;
   
   for (size_t i = 0; str[i] != '\0'; i++) {
       append_to_string(ls, str[i]);
   }
   return ls;
}

// Converts LinkedString to C-style string
// Demonstrates:
// - Dynamic memory allocation for strings
// - NULL termination of C strings
// - List traversal
char* to_char_array(const LinkedString* str) {
   char* result = malloc(str->length + 1);  // +1 for NULL terminator
   if (result == NULL) return NULL;
   
   Node* current = str->head;
   size_t i = 0;
   while (current != NULL) {
       result[i++] = *(char*)current->data;
       current = current->next;
   }
   result[i] = '\0';  // NULL terminate
   return result;
}

// Reverses the string using linked list operation
void reverse_string(LinkedString* str) {
   reverse_list(&str->head);
}

// Frees all memory associated with the string
// Demonstrates proper memory cleanup
void free_linked_string(LinkedString* str) {
   if (str == NULL) return;
   free_list(str->head);
   free(str);
}

// File I/O Operations
// Both demonstrate:
// - File handling in C
// - Error checking
// - Character-by-character I/O

// Reads file contents into a new LinkedString
LinkedString* read_from_file(const char* filename) {
   FILE* file = fopen(filename, "r");
   if (file == NULL) return NULL;
   
   LinkedString* str = create_linked_string();
   if (str == NULL) {
       fclose(file);
       return NULL;
   }
   
   char c;
   while ((c = fgetc(file)) != EOF) {
       append_to_string(str, c);
   }
   
   fclose(file);
   return str;
}

// Writes LinkedString contents to file
void write_to_file(const LinkedString* str, const char* filename) {
   FILE* file = fopen(filename, "w");
   if (file == NULL) return;
   
   Node* current = str->head;
   while (current != NULL) {
       fputc(*(char*)current->data, file);
       current = current->next;
   }
   
   fclose(file);
}

// String Operations
// All demonstrate:
// - List traversal
// - String manipulation
// - Use of const for read-only parameters

// Concatenates src string to end of dest
void concat_strings(LinkedString* dest, const LinkedString* src) {
   Node* current = src->head;
   while (current != NULL) {
       append_to_string(dest, *(char*)current->data);
       current = current->next;
   }
}

// Compares two strings lexicographically
// Returns: negative if str1 < str2, 0 if equal, positive if str1 > str2
int compare_strings(const LinkedString* str1, const LinkedString* str2) {
   Node *curr1 = str1->head, *curr2 = str2->head;
   
   while (curr1 != NULL && curr2 != NULL) {
       char c1 = *(char*)curr1->data;
       char c2 = *(char*)curr2->data;
       if (c1 != c2) return c1 - c2;
       curr1 = curr1->next;
       curr2 = curr2->next;
   }
   
   if (curr1 == NULL && curr2 == NULL) return 0;
   return curr1 == NULL ? -1 : 1;
}

// Returns the length of the string - O(1) operation
size_t string_length(const LinkedString* str) {
   return str->length;
}