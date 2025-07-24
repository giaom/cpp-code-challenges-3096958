// C++ Code Challenges, LinkedIn Learning

// Challenge #1: Checking for Palindromes
// Write a function to check if a string is a palindrome or not.
// Examples: civic, radar, level.

#include <iostream>
#include <algorithm>
#include <assert.h>

// is_palindrome()
// Summary: This function receives a string and returns true if the string is a palindrome, false otherwise.
// Arguments:
//           str: The string to analyze.
// Returns: A boolean value. True for palindromes, false otherwise.
bool is_palindrome(std::string str) {

    // Write your code here
    // transform to lowercase
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);

    // create reversed copy of string
    std::string rev = str;
    std::reverse(rev.begin(), rev.end());

    // check if equal
    return (str == rev);
}

// is_palindrome_alnum()
// Summary: This function receives a string and returns true if the sequence of letters and digits
//          (ignoring case and non-alphanumeric characters) forms a palindrome.
// Arguments:
//           str: The string to analyze.
// Returns: A boolean value. True if the sanitized string is a palindrome, false otherwise.
bool is_palindrome_alnum(std::string str) {
    std::string cleaned;

    // keep only alphanumeric characters, convert to lowercase
    for (char c : str) {
        // if alphanumeric (letter or digit)
        if (std::isalnum(c)) {
            cleaned+= std::tolower(c);
        }
    }

    // make reversed copy
    std::string rev = cleaned;
    std::reverse(rev.begin(), rev.end());

    return (cleaned == rev);
}

// unit tests for is_palindrome and is_palindrome_alnum
void run_tests() {
    // tests for is_palindrome
    assert(is_palindrome("Level") == true);
    assert(is_palindrome("A man, a plan, a canal: Panama") == false);
    assert(is_palindrome("blueberries and mangos") == false);
    std::cout << "\n✅ is_palindrome: All tests passed!\n";

    // tests for is_palindrome_alnum
    assert(is_palindrome_alnum("Level") == true);
    assert(is_palindrome_alnum("A man, a plan, a canal: Panama") == true);
    assert(is_palindrome_alnum("blueberries and mangos") == false);
    std::cout << "✅ is_palindrome_alnum: All tests passed!\n\n";

}

// Main function
int main(){
    run_tests();
    
    std::string s;
    std::cout << "Enter a string: " << std::flush;
    std::getline(std::cin,s);
    std::cout << "\n\"" << s 
            << (is_palindrome(s) ? "\" is" : "\" is not" ) 
            << " a palindrome.\n";
    std::cout << "\"" << s 
            << (is_palindrome_alnum(s) ? "\" is" : "\" is not" ) 
            << " an alphanumeric palindrome.\n\n";
    return 0;
}
