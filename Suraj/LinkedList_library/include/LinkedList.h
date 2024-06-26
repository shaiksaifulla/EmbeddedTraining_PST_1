#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

// Definition for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data);

// Function to insert a new node at the beginning of the list
void insertAtBeginning(Node** head, int data);

// Function to insert a new node at the end of the list
void insertAtEnd(Node** head, int data);

// Function to delete a node with a given key
void deleteNode(Node** head, int key);

// Function to traverse the list and print its elements
void printList(Node* head);

// Function to search for a node with a given key
Node* search(Node* head, int key);

// Function to delete the entire list
void deleteList(Node** head);

#endif // LINKED_LIST_H
