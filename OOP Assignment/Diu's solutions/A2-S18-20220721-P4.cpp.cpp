// File: A2-S18-20220721-P4.cpp
// Purpose: Finds primes numbers for the given numbers
// Author: Diu Gach Deng
// Section: S18
// ID: 20220721
// TA: Rana
// Date: 29 Oct 2023


#include <iostream>
#include <vector>
using namespace std;

// Prime Number
bool is_prime(int n) {
    if (n <= 1) {
        return false;  // Numbers less than or equal to 1 are not prime.
    }
    if (n <= 3) {
        return true;  // 2 and 3 are prime.
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }

    int i = 5;
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;  // Divisible by 2 or 3 means it's not prime.
        }
        i += 6;
    }

    return true; // If none of the above conditions are met, it's prime.
}

int main() {
    vector<int> my_array = {2, 3, 4, 5, 6, 7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    vector<int> prime_numbers;

    for (int num : my_array) {
        if (is_prime(num)) {
            prime_numbers.push_back(num);
        }
    }

    cout << "Prime numbers in the array: ";
    for (int prime : prime_numbers) {
        cout << prime << " ";
    }
      cout << endl;

    return 0;
}
