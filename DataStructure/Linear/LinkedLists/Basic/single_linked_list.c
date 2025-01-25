#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node
{
	int          data; // Data stored in the node
	struct Node *next; // Pointer to the next node
};

// Function to create a new node
struct Node *createNode(int data)
{
	struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
	if (newNode == NULL)
	{
		printf("Memory allocation failed!\n");
		exit(1);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtHead(struct Node **head, int data)
{
	struct Node *newNode = createNode(data);
	newNode->next = *head;
	*head = newNode;
	printf("Inserted %d at the beginning.\n", data);
}

// Function to insert a node at the end of the list
void insertAtTail(struct Node **head, int data)
{
	struct Node *newNode = createNode(data);
	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		struct Node *temp = *head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
	printf("Inserted %d at the end.\n", data);
}

// Function to insert a node at a specific position
void insertAtPosition(struct Node **head, int data, int position)
{
	if (position < 1)
	{
		printf("Invalid position. Position should be >= 1.\n");
		return;
	}

	if (position == 1)
	{
		insertAtHead(head, data); // Insert at the beginning if position is 1
		return;
	}

	struct Node *newNode = createNode(data);
	struct Node *temp = *head;
	for (int i = 1; i < position - 1; i++)
	{
		if (temp == NULL)
		{
			printf("Position %d is out of bounds.\n", position);
			return;
		}
		temp = temp->next;
	}

	if (temp == NULL)
	{
		printf("Position %d is out of bounds.\n", position);
		return;
	}

	newNode->next = temp->next;
	temp->next = newNode;
	printf("Inserted %d at position %d.\n", data, position);
}

// Function to search for a node with a specific value
struct Node *searchNode(struct Node *head, int data)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		if (temp->data == data)
		{
			return temp; // Return the node if found
		}
		temp = temp->next;
	}
	return NULL; // Return NULL if not found
}

// Function to delete a node with a specific value
void deleteNode(struct Node **head, int data)
{
	if (*head == NULL)
	{
		printf("List is empty. Nothing to delete.\n");
		return;
	}

	// If the node to be deleted is the head
	if ((*head)->data == data)
	{
		struct Node *temp = *head;
		*head = (*head)->next;
		free(temp);
		printf("Deleted node with value %d.\n", data);
		return;
	}

	// Search for the node to be deleted
	struct Node *current = *head;
	struct Node *previous = NULL;
	while (current != NULL && current->data != data)
	{
		previous = current;
		current = current->next;
	}

	// If the node was not found
	if (current == NULL)
	{
		printf("Node with value %d not found.\n", data);
		return;
	}

	// Unlink the node from the list
	previous->next = current->next;
	free(current);
	printf("Deleted node with value %d.\n", data);
}

// Function to traverse and print the linked list
void traverseList(struct Node *head)
{
	struct Node *temp = head;
	if (temp == NULL)
	{
		printf("List is empty.\n");
		return;
	}
	printf("Linked List: ");
	while (temp != NULL)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

// Function to free the entire linked list
void freeList(struct Node **head)
{
	struct Node *temp;
	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	printf("List has been freed.\n");
}

// Main function to demonstrate the linked list operations
int main()
{
	struct Node *head = NULL; // Initialize an empty linked list

	// Insert elements
	insertAtHead(&head, 10);
	insertAtTail(&head, 20);
	insertAtTail(&head, 30);
	insertAtHead(&head, 5);

	// Traverse the list
	traverseList(head);

	// Insert at a specific position
	insertAtPosition(&head, 15, 3); // Insert 15 at position 3
	traverseList(head);

	// Search for a node
	int          searchValue = 20;
	struct Node *foundNode = searchNode(head, searchValue);
	if (foundNode != NULL)
	{
		printf("Node with value %d found.\n", searchValue);
	}
	else
	{
		printf("Node with value %d not found.\n", searchValue);
	}

	// Delete a node
	deleteNode(&head, 20);
	traverseList(head);

	// Free the list
	freeList(&head);

	return 0;
}
