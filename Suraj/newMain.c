#include "sLinkedlist.h"

int main() {
    struct node nodeElement;

    nodeElement.data = 10;
    nodeElement.next = NULL;
    addNode(&nodeElement);

    nodeElement.data = 20;
    nodeElement.next = NULL;
    addNode(&nodeElement);

    nodeElement.data = 30;
    nodeElement.next = NULL;
    addNode(&nodeElement);

    printf("Original Linked List:\n");
    printList();

    reverseLinkedList();

    printf("Reversed Linked List:\n");
    printList();

    return 0;
}
