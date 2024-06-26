#include "SingleLinklist.h"

int main() {
    struct node nodeElement;

    nodeElement.data = 10;
    nodeElement.next = NULL;
    addNode(&nodeElement);
    /* printList();*/

    nodeElement.data = 20;
    nodeElement.next = NULL;
    addNode(&nodeElement);
    /*printList();*/

    nodeElement.data = 30;
    nodeElement.next = NULL;
    addNode(&nodeElement);
    printList();

    return 0;
}