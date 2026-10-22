#include <iostream>
#include "node.h"

int main()
{
    Node<int>* n1 = new_node(15);
    Node<int>* n2 = new_node(18);
    Node<int>* n3 = new_node(2);
    Node<int>* n4 = new_node(19);
    Node<int>* n5 = new_node(18);
    Node<int>* n6 = new_node(0);
    Node<int>* n7 = new_node(8);
    Node<int>* n8 = new_node(14);
    Node<int>* n9 = new_node(19);
    Node<int>* n10 = new_node(14);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;
    n9->next = n10;
    n10->next = nullptr;

    Node<int>* current = n1;
    int key = 18;
    int comparisons = 0;

    while (current != nullptr)
    {
        comparisons++;

        if (current->data == key)
        {
            std::cout << "Found: " << current->data << std::endl;
            break;
        }

        current = current->next;
    }

    std::cout << "Comparisons: " << comparisons << std::endl;

    return 0;
}