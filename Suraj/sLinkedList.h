#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void addNode(struct node* nodeElementPtr);
void deleteLastNode();
void reverseLinkedList();
void printList();

#endif // SLINKEDLIST_H
