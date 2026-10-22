#include "node.h"
#include <iostream>

#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

template <typename T>
void linearSearch(T data[], int arrSize, T dataFind)
{
    // Step 1: i = 0
    int i = 0;

    // Step 2: Repeat while i < n
    while (i < arrSize)
    {
        // Step 3: If item == data[i]
        if (dataFind == data[i])
        {
            std::cout << "Searching is successful" << std::endl;
            return;
        }

        // Step 4: i = i + 1
        i++;
    }

    // Step 5: If i == n
    std::cout << "The element is not found" << std:endl;
}

template <typename T>
void linearSearchLL(Node<T> *node, T dataFind)
{
    // repeat the loop until the current node is null
    while (node != nullptr)
    {

        // if item == current node's data then display searching is successful
        if (dataFind == node->data)
        {
            std::cout << "the search is success\n";
            return;
        }

        // if not, move to the next node
        node = node->next;
    }

    //the searching reached nullptr, -> search is unsuccessful
    std::cout << "the element is not found \n";
}

template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last) {

    Node<T>* slow = start;
    Node<T>* fast = start;

    // Fast pointer moves twice as fast as slow pointer
    while (fast != last && fast->next != last) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // Return the slow pointer address as the middle node
    return slow;
}

template <typename T>
void binarySearch(T data[], int arrSize, T dataFind)
{
    int low = 0;
    int up = arrSize - 1;

    while (low <= up)
    {
        int mid = (low + up) / 2;

        if (dataFind == data[mid])
        {
            std::cout << "Search element is found!" << std::endl;
            return;
        }
        else
        {
            if (dataFind < data[mid])
            {
                up = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }

    std::cout << "Search element is not found" << std::endl;
}

template <typename T>
void binarySearchLL(Node<T>* start, T findData) {
    Node<T>* last = nullptr;

    do {
        Node<T>* mid = getMiddle(start, last);

        if (mid == nullptr) {
            std::cout << "the element is not found \n";
            return;
        }

        if (mid->data == findData) {
            std::cout << "the search is success\n";
            return;
        }
       
        else if (mid->data < findData) {
            start = mid->next; // Set start pointer to next of middle element
        }
        
        else {
            last = mid; // Set last pointer to middle element
        }

    } while (last == nullptr || last != start);

    std::cout << "the element is not found \n";
}

#endif