/*
Arrays: homogenous contiguous memory locations.
    - Accessing every element in array: O(1) in space-complecity and O(1) in time complexity.
    - Searching for specific element in array:
        - O(len(n)) for traversing the unsorted array.
        - O(log(len(n))) traversing the sorted array.
    - Insertion/deletion of element:
        - O(1) if element to be inserted/deleted at the end.
        - O(len(m)) for inserting in the array somewhere at mth position and shifting the rest elements likewise.
*/
# include <iostream>

// header file for basic array functions of input and print
# include <01-arrays.h>

int accessAnyArrayElement(int arrSize, int* arrN, int idx) {

    // edge conditions
    if (idx < 0 || idx > arrSize) {
        return -1;
    }

    // index exists in the array. So, element must exist.
    int arrElement;
    for (int i=0; i<arrSize; i++) {
        if (i == idx) {
            return arrN[i];
        };
    };

};



int main() {

    


    return 0;
}
