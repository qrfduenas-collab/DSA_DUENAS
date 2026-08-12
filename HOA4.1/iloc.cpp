#include <iostream>
#include <string>
#include "stackList.h"

bool isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

// Algorithm to check if the string has balanced symbols
bool isBalanced(const std::string& expr) {
    // 1. Process character by character
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            push<char>(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            
            if (isEmpty<char>()) {
                return false;
            }
        
            char topChar = pop<char>();
            
            if (!isMatchingPair(topChar, ch)) {
                
                while (!isEmpty<char>()) { pop<char>(); }
                return false;
            }
        }
    
    }
    bool valid = isEmpty<char>();

    while (!isEmpty<char>()) {
        pop<char>();
    }

    return valid;
}

int main() {
    // Test expressions from the activity sheet
    std::string expressions[] = {
        "(A+B)+(C-D)",
        "((A+B)+(C-D)",
        "((A+B)+[C-D])",
        "((A+B)+[C-D]}"
    };

    std::cout << "--- BALANCED SYMBOLS CHECKER ---\n\n";

    for (const std::string& expr : expressions) {
        std::cout << "Expression: " << expr << "\n";
        
        if (isBalanced(expr)) {
            std::cout << "Result: VALID (Y)\n";
        } else {
            std::cout << "Result: INVALID (N)\n";
        }
        
        std::cout << "\n";
    }

    return 0;
}