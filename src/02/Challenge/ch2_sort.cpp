// C++ Code Challenges, LinkedIn Learning

// Challenge #2: Sorting an Array
// Sort the elements in an array in ascending order.
// Implement the algorithm of your choice.
// Don't use STL vectors.
// Don't use a sorting function from a library.

#include <iostream>

// bubble, merge, quick, sort

// sort_array()
// Summary: This function receives an array of integers and sorts it in ascending order.
// Arguments:
//           arr: A pointer acting as the array to sort.
//           n: The size of the array.
// Returns: A boolean value: True on success, false otherwise.

// Bubble Sort algorithm repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. This process is repeated until the array is sorted.
bool bubble_sort_array(int *arr, int n){
    if (arr == NULL) { return false; }
    if (n < 2) { return true; }

    bool sorted = false;
    int temp;

    while(!sorted) {
        sorted = true; 

        for (int i = 0; i < (n-1); i++) {
            if (arr[i] > arr[i+1]) {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                sorted = false;
            }
        }
    }

    return true;
}

// Merge Sort algorithm divides the array into two halves, recursively sorts each half, and then merges the sorted halves back together. The merging process ensures that the result is sorted.
bool merge_sort_array(int *arr, int n){
    if (arr == NULL) { return false; }
    if (n < 2) { return true; }
    // Write your code here

    return false;
}

// Quick Sort algorithm selects a pivot element from the array and partitions the other elements into two sub-arrays according to whether they are less than or greater than the pivot. It then recursively sorts the sub-arrays.
bool quick_sort_array(int *arr, int n){
    if (arr == NULL) { return false; }
    if (n < 2) { return true; }
    // Write your code here

    return false;
}

void print_array(int *array, int len) {
    std::cout << "[ ";
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
    std::cout << "]" << std::endl << std::endl << std::flush;
}

// Main function
int main(){
    // The following array will be treated as an array of length len. 
    const int len = 7; // Don't exceed the length of the array below!
    int array[] = {2, 9, 4, 3, 5, 1, 6, 8, 0, 7};
    
    int arr2[len];
    int arr3[len];
    std::copy(std::begin(array), std::end(array), arr2);
    std::copy(std::begin(array), std::end(array), arr3);

    // Print the original array
    std::cout << "Original Array: " << std::endl;
    print_array(array, len); 

    // bubble sort the array
    bubble_sort_array(array, len); 
    std::cout << "  Bubble Sorted Array: " << std::endl;
    print_array(array, len); 

    // merge sort the array
    merge_sort_array(arr2, len); 
    std::cout << "  Merge Sorted Array: " << std::endl;
    print_array(arr2, len); 

    // quick sort the array
    quick_sort_array(arr3, len); 
    std::cout << "  Quick Sorted Array: " << std::endl;
    print_array(arr3, len); 

    return 0;
}
