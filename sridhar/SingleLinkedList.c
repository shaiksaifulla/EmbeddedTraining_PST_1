#include "SingleLinkedlist.h"

static struct node* head = NULL;
static struct node* tail = NULL;

void addNode(struct node* nodeElementPtr)
{
    // temp is pointer to structure
    struct node* temp = malloc(sizeof(struct node));
    temp->data = nodeElementPtr->data;
    temp->next = nodeElementPtr->next;

    if (head == NULL) 
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void printList(void) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(void) {
    struct node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    tail = NULL;
}
