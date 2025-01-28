

// When to use function pointers?
//  The basic idea is whenever you want to pass behavior as a
//    parameter to another function, but when is that?
//  Sorting is common. You can define a sorting funciton with specified
//    behavior and pass that to a sort function and have it operate
//    on a collection.
//
#include <stdio.h>  // contains printf
#include <stdlib.h> // contains qsort

int double_value(int x) { return x * 2; }
int square_value(int x) { return x * x; }
// optional function peram to operate on the array
// before printing its contents
void print_nums(int arr[], int size, void (*operation)(int[], int)) {
  if (operation) {
    operation(arr, size);
  }
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// an int sort comparator
// cast a to an integer pointer then derefrence
// same for b
// yeilds a positive or negative, which is the info
//  required to know which is greater or lesser.
int compare_int(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}
// can write a sort wrapper to make function params match
// other operation definitions
void sort_wrapper_int(int arr[], int size) {
  qsort(arr, size, sizeof(int), compare_int);
}

void reverse(int arr[], int size) {
  // pointer to start of array
  int *left = arr;
  // pointer to end of array
  int *right = arr + size - 1;
  // swap, w increment and decrament of pointers
  while (left < right) {
    // temp points to what right is pointing to
    int temp = *left;
    // the value left points to is now the value right points to
    *left++ = *right;
    // tha value right points to is now the value of temp
    *right++ = temp;
  }
}

int main(void) {
  int arr[] = {4, 2, 8, 1, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  // passing function as params
  print_nums(arr, size, NULL);             // no operation
  print_nums(arr, size, sort_wrapper_int); // sort
  print_nums(arr, size, reverse);
}
