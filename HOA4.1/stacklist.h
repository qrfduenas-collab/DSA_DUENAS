#ifndef STACK_LIST_H
#define STACK_LIST_H

#include <iostream>

// Node structure for the linked list
template <typename T>
struct Node {
    T data;
    Node<T>* next;
};

// Global head pointer for the stack
template <typename T>
Node<T>* head = nullptr;

// Check if the stack is empty
template <typename T>
bool isEmpty() {
    return head<T> == nullptr;
}

// Push an item onto the stack
template <typename T>
void push(T newData) {
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = head<T>;
    head<T> = newNode;
}

// Pop an item from the stack and return its value
template <typename T>
T pop() {
    if (isEmpty<T>()) {
        std::cout << "Stack underflow.\n";
        return T();
    }
    Node<T>* temp = head<T>;
    T tempVal = temp->data;
    head<T> = head<T>->next;
    delete temp;
    return tempVal;
}

// Get the top item without removing it
template <typename T>
void top() {
    if (isEmpty<T>()) {
        std::cout << "Stack underflow\n";
        return;
    }
    std::cout << "Top of stack: " << head<T>->data << "\n";
}

// Display all items in the stack from top to bottom
template <typename T>
void displayAll() {
    if (isEmpty<T>()) {
        std::cout << "Stack is empty\n";
        return;
    }
    std::cout << "Stack contents (top to bottom): ";
    Node<T>* temp = head<T>;
    while (temp != nullptr) {
        std::cout << "\n| " << temp->data << " |";
        temp = temp->next;
    }
    std::cout << "\n";
}

#endif