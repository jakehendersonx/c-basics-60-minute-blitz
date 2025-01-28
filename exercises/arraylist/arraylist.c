#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10

typedef struct {
    void** array;
    int size;
    int capacity;
    size_t elementSize;
    void (*freeElement)(void*);
} ArrayList;

ArrayList* createArrayList(size_t elementSize, void (*freeElement)(void*)) {
    ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
    list->array = malloc(INITIAL_CAPACITY * sizeof(void*));
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
    list->elementSize = elementSize;
    list->freeElement = freeElement;
    return list;
}

void add(ArrayList* list, void* element) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->array = realloc(list->array, list->capacity * sizeof(void*));
    }
    void* newElement = malloc(list->elementSize);
    memcpy(newElement, element, list->elementSize);
    list->array[list->size++] = newElement;
}

// New get function that uses a comparison function
void* getElement(ArrayList* list, void* target, int (*compare)(const void*, const void*)) {
    for (int i = 0; i < list->size; i++) {
        if (compare(list->array[i], target) == 0) {
            return list->array[i];
        }
    }
    return NULL; // Element not found
}

void removeElement(ArrayList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Index out of bounds\n");
        return;
    }
    if (list->freeElement) {
        list->freeElement(list->array[index]);
    }
    free(list->array[index]);
    for (int i = index; i < list->size - 1; i++) {
        list->array[i] = list->array[i + 1];
    }
    list->size--;
}

void freeArrayList(ArrayList* list) {
    for (int i = 0; i < list->size; i++) {
        if (list->freeElement) {
            list->freeElement(list->array[i]);
        }
        free(list->array[i]);
    }
    free(list->array);
    free(list);
}

// Example usage and test functions

// Comparison function for integers
int compareInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Comparison function for strings
int compareString(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}