#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
};
struct Node *head = NULL;

void insertPosition(int value, int pos) {
    if (pos <= 0) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
    insertBeginning(value);
        return;
    }

    if (head == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct Node *temp = head;

    // Find the node just before the desired position
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;

        // We have reached the head again,
        // so the position is invalid.
        if (temp == head) {
            printf("Invalid position\n");
            return;
        }
    }

    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;
}