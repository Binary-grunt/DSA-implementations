#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node
struct Node
{
	int          data; // Data field
	struct Node *next; // Pointer to the next node
};

// Function to create a new node
struct Node *createNode(int data)
{
	struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

// Insert a node at the head (beginning) of the LinkedList
void insertAtHead(struct Node **head, int data)
{
	struct Node *newNode = createNode(data);
	newNode->next = *head;
	*head = newNode;
}

// Insert a node at the tail (end) of the LinkedList
void insertAtTail(struct Node *head, int data)
{
	struct Node *newNode = createNode(data);
	struct Node *temp = head;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

// Insert a node at a specific position in the LinkedList
void insertAtPosition(struct Node **head, int data, int position)
{
	struct Node *newNode = createNode(data);

	if (position == 0)
	{
		newNode->next = *head;
		*head = newNode;
		return;
	}

	struct Node *temp = *head;
	for (int i = 0; i < position - 1 && temp != NULL; i++)
	{
		temp = temp->next;
	}

	if (temp == NULL)
	{
		printf("Invalid position\n");
		return;
	}

	newNode->next = temp->next;
	temp->next = newNode;
}

// Traverse the LinkedList and print all elements
void traverse(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

// Search for a value in the LinkedList
int search(struct Node *head, int key)
{
	struct Node *temp = head;
	int          position = 0;

	while (temp != NULL)
	{
		if (temp->data == key)
		{
			return position; // Found
		}
		temp = temp->next;
		position++;
	}
	return -1; // Not found
}

// Delete the node at the head of the LinkedList
void deleteAtHead(struct Node **head)
{
	if (*head == NULL)
		return; // Empty list

	struct Node *temp = *head;
	*head = (*head)->next;
	free(temp);
}

// Delete the node at a specific position in the LinkedList
void deleteAtPosition(struct Node **head, int position)
{
	if (*head == NULL)
		return; // Empty list

	struct Node *temp = *head;

	if (position == 0)
	{ // Delete head
		*head = temp->next;
		free(temp);
		return;
	}

	for (int i = 0; i < position - 1 && temp != NULL; i++)
	{
		temp = temp->next;
	}

	if (temp == NULL || temp->next == NULL)
	{
		printf("Invalid position\n");
		return;
	}

	struct Node *nodeToDelete = temp->next;
	temp->next = temp->next->next;
	free(nodeToDelete);
}

// Delete a node by its value
void deleteByValue(struct Node **head, int key)
{
	struct Node *temp = *head;
	struct Node *prev = NULL;

	if (temp != NULL && temp->data == key)
	{ // Delete head
		*head = temp->next;
		free(temp);
		return;
	}

	while (temp != NULL && temp->data != key)
	{
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL)
		return; // Key not found

	prev->next = temp->next;
	free(temp);
}

// Main function to test LinkedList operations
int main()
{
	struct Node *head = NULL; // Initialize an empty LinkedList

	// Insertion operations
	insertAtHead(&head, 10);
	insertAtHead(&head, 5);         // List: 5 -> 10
	insertAtTail(head, 20);         // List: 5 -> 10 -> 20
	insertAtPosition(&head, 15, 2); // List: 5 -> 10 -> 15 -> 20

	// Display the LinkedList
	printf("LinkedList after insertion: ");
	traverse(head);

	// Searching for a value
	int searchValue = 15;
	int position = search(head, searchValue);
	if (position != -1)
	{
		printf("Value %d found at position %d\n", searchValue, position);
	}
	else
	{
		printf("Value %d not found in the list\n", searchValue);
	}

	// Deletion operations
	deleteAtHead(&head);        // List: 10 -> 15 -> 20
	deleteAtPosition(&head, 1); // List: 10 -> 20
	deleteByValue(&head, 20);   // List: 10

	// Display the LinkedList after deletions
	printf("LinkedList after deletion: ");
	traverse(head);

	return 0;
}
