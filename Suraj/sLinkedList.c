#include "sLinkedlist.h"

static struct node* head = NULL;
static struct node* tail = NULL;

void addNode(struct node* nodeElementPtr) {
    // Allocate memory for the new node
    struct node* temp = malloc(sizeof(struct node));
    temp->data = nodeElementPtr->data;
    temp->next = nodeElementPtr->next;

    if (head == NULL) { // If the linked list is empty
        head = temp;
        tail = temp;  
    }
    else {
        tail->next = temp;
        tail = temp;
    }
}

void deleteLastNode() {
    if (head == NULL) { // If the linked list is empty
        printf("Linked List is empty\n");
        return;
    }

    if (head->next == NULL) { // If the linked list has only one element
        free(head);
        head = NULL;
        tail = NULL;
        return;
    }

    struct node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    tail = temp;
}

void reverseLinkedList() {
    struct node* prev = NULL;
    struct node* current = head;
    struct node* temp = NULL;

    while (current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }

    head = prev;
}

void printList() {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n"); // Indicate the end of the list
}
