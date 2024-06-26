
#include "SingleLinklist.h"

static struct node* head = NULL;
static struct node* tail = NULL;

void addNode(struct node* nodeElementPtr)
{
	// temp is pointer to structure
	struct node* temp = malloc(sizeof(struct node));
	temp->data = nodeElementPtr->data;
	temp->next = nodeElementPtr->next;

	if (head == NULL) // currently the linklist is empty
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

void printList()
{
	struct node* temp = head;
	while (temp != NULL)
	{
		printf("%d \t->\t", temp->data);
		temp = temp->next;
	}
}
