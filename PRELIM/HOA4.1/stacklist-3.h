#ifndef STACK_LIST_H
#define STACK_LIST_H

// class node that contains data and the next
template <typename T>
class Node {
public:
    T data;      // VALUE THAT WE NEED STORE
    Node* next;  // POINTER TO THE NEXT NODE
};

template <typename T>
Node<T>* head = nullptr;

// isEmpty function (placed before pop/top/display to avoid forward declaration errors)
template <typename T>
bool isEmpty() {
    return head<T> == nullptr;
}

// push
template <typename T>
void push(T newData) {
    // create a new node and assign the newData
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;

    // new node points to current top, then becomes the new top
    newNode->next = head<T>;
    head<T> = newNode;
}

// pop
template <typename T>
T pop() {
    // checks if the stack is empty
    if (head<T> == nullptr) {
        std::cout << "Stack underflow." << std::endl;
        return T();
    }

    // save the current top node
    Node<T>* temp = head<T>;
    // store its data
    T tempVal = temp->data;

    // move the head to the next node
    head<T> = head<T>->next;
    // free the removed node
    delete temp;
    // return the removed value
    return tempVal;
}

// top
template <typename T>
void top() {
    // error catching:
    if (isEmpty<T>()) {
        std::cout << "Stack underflow" << std::endl;
        return;
    }

    // display the Top Node
    std::cout << "Top of stack: " << head<T>->data << std::endl;
}

// Display all
template <typename T>
void displayAll() {
    if (isEmpty<T>()) {
        std::cout << "Stack is empty" << std::endl;
        return;
    }

    std::cout << "Stack contents (top to bottom): ";
    Node<T>* temp = head<T>;
    while (temp != nullptr) {
        std::cout << "\n| " << temp->data << " | ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

#endif
