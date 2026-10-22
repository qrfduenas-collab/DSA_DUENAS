#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H

#include <iostream>
#include <string>

template <typename T>
class doubleList {
public:
    T data;
    doubleList<T>* next = nullptr;
    doubleList<T>* prev = nullptr;
};

// ===================
// creating a node
// ===================
template <typename T>
doubleList<T>* new_node(T newData) {
    doubleList<T>* newNode = new doubleList<T>();
    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// ===================
// traversal
// ===================
template <typename T>
void dllTraverse(doubleList<T>* currentNode) {
    doubleList<T>* tail = nullptr;
    while (currentNode != nullptr) {
        // prints the data
        std::cout << currentNode->data << " ";
        // save the current node as the last visited node
        tail = currentNode;
        // move to the next node
        currentNode = currentNode->next;
    }

    std::cout << std::endl;

    // reverse traversal
    std::cout << "Reverse Traversal: ";
    while (tail != nullptr) {
        std::cout << tail->data << " ";
        tail = tail->prev;
    }

    std::cout << std::endl;
}

// ===================
// insertion at the head
// ===================
template <typename T>
void dllInsertHead(T newData, doubleList<T>** currentHead) {
    // create a new node
    doubleList<T>* newNode = new_node(newData);

    // SET the new node to point to the current head
    newNode->next = *currentHead;

    // current head will be pointed to the new node
    if (*currentHead != nullptr) {
        (*currentHead)->prev = newNode;
    }

    // update the head pointer
    *currentHead = newNode;
}

// ===================
// general insertion
// ===================
template <typename T>
void dllInsertAfter(doubleList<T>* prevNode, T newData) {
    if (prevNode == nullptr) {
        std::cout << "The given previous node cannot be NULL" << std::endl;
        return;
    }

    // create a new node
    doubleList<T>* newNode = new_node(newData);

    // set new node's next to prevNode's next
    newNode->next = prevNode->next;

    // connect prevNode's next to newNode
    prevNode->next = newNode;

    // connect newNode's prev to prevNode
    newNode->prev = prevNode;

    // connect next node's prev to newNode if it exists
    if (newNode->next != nullptr) {
        newNode->next->prev = newNode;
    }
}

// ===================
// insertion at the end
// ===================
template <typename T>
void dllInsertEnd(T newData, doubleList<T>* currentHead) {
    // create a new node
    doubleList<T>* newNode = new_node(newData);

    if (currentHead == nullptr) {
        return;
    }

    // traverse until the last node
    doubleList<T>* currentNode = currentHead;
    while (currentNode->next != nullptr) {
        currentNode = currentNode->next;
    }

    // connect the last node to the new node
    currentNode->next = newNode;

    // connect the prev node to the new node
    newNode->prev = currentNode;
}

// ===================
// general deletion (deletes a given node)
// ===================
template <typename T>
void dllDeleteNode(doubleList<T>** currentHead, doubleList<T>* delNode) {
    if (*currentHead == nullptr || delNode == nullptr) return;

    // if node to be deleted is head node
    if (*currentHead == delNode) {
        *currentHead = delNode->next;
    }

    // change next only if node to be deleted is NOT the last node
    if (delNode->next != nullptr) {
        delNode->next->prev = delNode->prev;
    }

    // change prev only if node to be deleted is NOT the first node
    if (delNode->prev != nullptr) {
        delNode->prev->next = delNode->next;
    }

    delete delNode;
}

// ===================
// delete from end
// ===================
template <typename T>
void dllDeleteEnd(doubleList<T>** currentHead) {
    if (*currentHead == nullptr) return;

    doubleList<T>* temp = *currentHead;

    if (temp->next == nullptr) {
        *currentHead = nullptr;
        delete temp;
        return;
    }

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->prev->next = nullptr;
    delete temp;
}

#endif