// C++ Code Challenges, LinkedIn Learning

// Challenge #4: Checking for Bitonic Sequences
// Write a function to check if a vector of integers is bitonic or not.
// Bitonic sequences have an ascending segment followed by a descending segment (sort of).
// Circular shifts of these sequences are also bitonic.

// Formally, a bitonic sequence is a sequence with x[0] <= ... <= x[k] >= ... >= x[n-1]
//           for some k between 0 and n-1, or a circular shift of such a sequence.

// Special bitonic cases: Monotonic sequences and sequences where all elements have the same value.

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <assert.h>

// is_bitonic()
// Summary: This function receives an STL vector of integers and returns true if it contains a bitonic sequence, false otherwise.
// Arguments:
//           v: A reference to the vector to analyze.
// Returns: A boolean value: True for bitonic sequences, false otherwise.
bool is_bitonic(const std::vector<int> &v){
    // Write your code here
    int count = v.size();
    if (count < 2) {return true; }
    
    bool rising = false;
    int i=0; // to traverse vector by index

    // ignore starting repeated values
    while ((i < (count-1)) && (v[i] == v[i+1])) {
        i++; 
    }     
    // Reached end, all values are the same, monotonic.
    if (i == (count-1)) {return true;}

    // FIRST SLOPE: ------------------------
    if (v[i] < v[i+1]) { // if rising 
        rising = true;
        
        while ((i < (count-1)) && v[i] <= v[i+1]) { 
            i++; // increment while rising 
        }
    } else {
    // if (v[i] > v[i+1]) { // if descending 
        rising = false;
        
        while ((i < (count-1)) && v[i] >= v[i+1]) {
            i++; // increment while descending 
        }
    }
    // reached end of vector, only one slope. monotopnic
    if (i == (count-1)) {return true;}

    // SECOND SLOPE: ------------------------
    if (v[i] < v[i+1]) { // if rising 
    // if (!rising) { // was descending, now rising 
        rising = true;
        
        while ((i < (count-1)) && v[i] <= v[i+1]) {
            i++;
        }
    } else {
    // if (v[i] > v[i+1]) { // if descending 
    // if (rising) { // was rising, now descending 
        rising = false;
        
        while ((i < (count-1)) && v[i] >= v[i+1]) {
            i++;
        }
    }
    // reached end of vector, two slopes. bitonic
    if (i == (count-1)) {return true;}

    // THIRD SLOPE: ------------------------
    // if (v[i] < v[i+1]) { // if rising 
    if (!rising) { // was descending, now rising 
        rising = true;
        
        while ((i < (count-1)) && v[i] <= v[i+1]) {
            i++;
        }
    } else {
    // if (v[i] > v[i+1]) { // if descending 
    // if (rising) { // was rising, now descending 
        rising = false;
        
        while ((i < (count-1)) && v[i] >= v[i+1]) {
            i++;
        }
    }
    // Did not reach end? 4th slope, not bitonic
    if (i < (count-1)) {return false;}

    // 3 slopes, now check if first and last array belong to same slope
    // v[count-1] or v[i] should be last index of vector
    if (rising && (v[i] <= v[0])) { 
        return true;
    }
    if (!rising && (v[i] >= v[0])) {
        return true;
    }

    // Else, third slope is different from first, -> 4th slope.
    return false;
}

void test_is_bitonic() {
    std::vector<int> myvec = {1, 2, 5, 4, 3};  // Yes
    std::vector<int> myvec1 = {1, 1, 1, 1, 1};  // Yes
    std::vector<int> myvec2 = {3, 4, 5, 2, 2};  // Yes
    std::vector<int> myvec3 = {3, 4, 5, 2, 4};  // No
    std::vector<int> myvec4 = {1, 2, 3, 4, 5};  // Yes
    std::vector<int> myvec5 = {1, 2, 3, 1, 2};  // No
    std::vector<int> myvec6 = {5, 4, 6, 2, 6};  // No
    std::vector<int> myvec7 = {5, 4, 3, 2, 1};  // Yes
    std::vector<int> myvec8 = {5, 4, 3, 2, 6};  // Yes
    std::vector<int> myvec9 = {5, 4, 6, 5, 4};  // No
    std::vector<int> myvec10 = {5, 4, 6, 5, 5};  // Yes

    assert (is_bitonic(myvec) == true); 
    assert (is_bitonic(myvec1) == true); 
    assert (is_bitonic(myvec2) == true); 
    assert (is_bitonic(myvec3) == false); 
    assert (is_bitonic(myvec4) == true); 
    assert (is_bitonic(myvec5) == false); 
    assert (is_bitonic(myvec6) == false); 
    assert (is_bitonic(myvec7) == true); 
    assert (is_bitonic(myvec8) == true); 
    assert (is_bitonic(myvec9) == false); 
    assert (is_bitonic(myvec10) == true); 

    std::cout << "✅ is_bitonic: All tests passed!\n\n" << std::endl; 
}

// Main function
int main(){
    test_is_bitonic();
    // Uncomment one of these lines and make sure you get the result at the right. 
    
    std::vector<int> myvec = {1, 2, 5, 4, 3};  // Yes
    // std::vector<int> myvec1 = {1, 1, 1, 1, 1};  // Yes
    // std::vector<int> myvec2 = {3, 4, 5, 2, 2};  // Yes
    // std::vector<int> myvec3 = {3, 4, 5, 2, 4};  // No
    // std::vector<int> myvec4 = {1, 2, 3, 4, 5};  // Yes
    // std::vector<int> myvec5 = {1, 2, 3, 1, 2};  // No
    // std::vector<int> myvec6 = {5, 4, 6, 2, 6};  // No
    // std::vector<int> myvec7 = {5, 4, 3, 2, 1};  // Yes
    // std::vector<int> myvec8 = {5, 4, 3, 2, 6};  // Yes
    // std::vector<int> myvec9 = {5, 4, 6, 5, 4};  // No
    // std::vector<int> myvec10 = {5, 4, 6, 5, 5};  // Yes

    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic." : "No, it is not bitonic.");
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}
