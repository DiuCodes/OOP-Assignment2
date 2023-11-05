// File: A2-S18-20220721-P4.cpp
// Purpose: Finds primes numbers for the given numbers
// Author: Diu Gach Deng
// Section: S18
// ID: 20220721
// TA: Rana
// Date: 29 Oct 2023

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string input;
    cout << "Enter a string with extra spaces: ";
    getline(std::cin, input); // Read the input as a whole line

    size_t pos;

    while ((pos = input.find("  ")) != string::npos) {
        // Replace double spaces with single space
        input.replace(pos, 2, " ");
    }

    cout << "Normalized sentence: " << input << std::endl;
    return 0;
}

