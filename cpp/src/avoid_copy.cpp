#include <iostream>

int main() {
    // array of 5 zeros
    int arr[5] = {0};
    // increments value at each index
    for( int i = 0; i < 5; ++i)
        ++arr[i]; // right is evaluated first

    return 0;
}

int findMax(int* arr, int size) {
    int max = *arr; 
    // does * get you the value or the address
    for(int i = 1; i < size; i++) {
        int curr = *(arr + i);
        if(curr > max) {
            max = curr;
        }
    }
    return max;
}
