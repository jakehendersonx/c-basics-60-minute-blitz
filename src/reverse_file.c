/*
 * Main program that demonstrates:
 * - Command line argument handling
 * - File I/O through LinkedString operations
 * - Basic error handling
 * - Program return values
 */

#include <stdio.h>
#include "linked_string.h"

// Main function demonstrates:
// - Command line argument handling (argc, argv)
// - Return values for program status
int main(int argc, char* argv[]) {
    // Validate command line arguments
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;  // Return non-zero to indicate error
    }
    
    // Read input file into LinkedString
    // Demonstrates error handling for file operations
    LinkedString* str = read_from_file(argv[1]);
    if (str == NULL) {
        printf("Could not read input file\n");
        return 1;
    }
    
    // Process the string (reverse it)
    reverse_string(str);
    
    // Write result to output file
    write_to_file(str, argv[2]);
    
    // Clean up and exit
    free_linked_string(str);
    return 0;  // Return zero to indicate success
}