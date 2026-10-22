#include <iostream>
#include <string>
#include "double_LL.h"

int main() {

    // CREATION OF HEAD NODE:
    doubleList<std::string>* head = new_node(std::string("Song_A"));

    // CREATION OF OTHER NODES:
    doubleList<std::string>* second = new_node(std::string("Song_B"));
    doubleList<std::string>* third = new_node(std::string("Song_C"));

    // LINK THE NODES
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    std::cout << "Initial Traversal" << std::endl;
    dllTraverse(head);

    std::cout << "Inserting at the head" << std::endl;
    dllInsertHead(std::string("Song_Intro"), &head);
    dllTraverse(head); 

    std::cout << "General Insertion (Inserting 'Song_X' after 'Song_B'):" << std::endl;
    dllInsertAfter(second, std::string("Song_X"));
    dllTraverse(head);

    std::cout << "Inserting at the end ('Song_Z'):" << std::endl;
    dllInsertEnd(std::string("Song_Z"), head);
    dllTraverse(head);

    std::cout << "General Deletion (Deleting 'Song_X'):" << std::endl;
    dllDeleteNode(&head, second->next);
    dllTraverse(head);

    std::cout << "Deleting from the end:" << std::endl;
    dllDeleteEnd(&head);
    dllTraverse(head);

    return 0;
}