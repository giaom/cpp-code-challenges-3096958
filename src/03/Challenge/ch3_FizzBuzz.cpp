// C++ Code Challenges, LinkedIn Learning

// Challenge #3: FizzBuzz
// Write an application that plays FizzBuzz.
// Print an integer number sequence starting at 1, replacing multiples of 3 by "Fizz", multiples of 5 by "Buzz", and multiples of 3 and 5 by "FizzBuzz".
// The user enters the last number in the sequence.

#include <iostream>

void fizzbuzz(int n, int f, int b) {
    bool mf, mb; // track multiples of f and b

    for (int i=1; i <= n; i++) {
        mf = ((i % f) == 0);
        mb = ((i % b) == 0);

        if(!mf && !mb) { 
            std::cout << i;
        } else {
            if (mf) { std::cout << "Fizz"; }
            if (mb) { std::cout << "Buzz"; }
        }
        std::cout << std::endl;
    }
}

// FizzBuzz, main()
// Summary: This application runs on the main function.
int main(){
    int n; // How many numbers to include in the sequence.
    
    std::cout << "Enter a positive integer: " << std::flush;
    std::cin >> n;

    // Write your code here
    fizzbuzz(n, 3, 5);
    
    std::cout << std::endl << std::flush;
    return 0;
}
