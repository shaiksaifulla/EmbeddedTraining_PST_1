

#include "SingleLinklist.h"

int main()
{
	struct node nodeElement;
	nodeElement.data = 10;
	nodeElement.next = NULL;

	addNode(&nodeElement);

	printList();
	printf("\n");
	nodeElement.data = 20;
	nodeElement.next = NULL;

	addNode(&nodeElement);

	printList();
	printf("\n");

	nodeElement.data = 30;
	nodeElement.next = NULL;

	addNode(&nodeElement);

	printList();
	printf("\n");
}