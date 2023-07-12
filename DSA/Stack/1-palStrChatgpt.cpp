#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

bool isPalindrome(const char* str) {
    int size = strlen(str);
    int mid = size / 2;

    stack<char> stack;

    // Push the first half of the string onto the stack
    for (int i = 0; i < mid; i++) {
        stack.push(str[i]);
    }

    // Skip the middle character for odd-length strings
    int start = (size % 2 == 0) ? mid : mid + 1;

    // Compare the remaining half of the string with the stack
    for (int i = start; i < size; i++) {
        if (stack.empty() || str[i] != stack.top()) {
            return false;
        }
        stack.pop();
    }

    return true;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Please provide a string as an argument.\n";
        return 1;
    }

    const char* str = argv[1];

    if (isPalindrome(str)) {
        cout << "Palindrome\n";
    } else {
        cout << "Not Palindrome\n";
    }

    return 0;
}
