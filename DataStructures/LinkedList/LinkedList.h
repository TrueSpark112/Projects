#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "node.cpp"
using namespace std;


// Linked list class to
// implement a linked list.
template<Typename T>
class Linkedlist<T> {
    node* head;

public:
    // Default constructor
    Linkedlist() { head = NULL; }

    // Function to insert a
    // node at the end of the
    // linked list.
    void insertNode(T);

    // Function to print the
    // linked list.
    void printList();

    // Function to delete the
    // node at given position
    void deleteNode(T);
};
#endif
