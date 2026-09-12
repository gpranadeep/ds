#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

// Insert at beginning
void insertBeginning(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;

    // If list is empty
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    struct Node *last = head->prev;

    newNode->next = head;
    newNode->prev = last;

    last->next = newNode;
    head->prev = newNode;

    head = newNode;
}

// Insert at a given position
void insertPosition(int value, int pos) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    // Position 1 means insert at beginning
    if (pos == 1) {
        insertBeginning(value);
        return;
    }

    // If list is empty
    if (head == NULL) {
        printf("List is empty. Only position 1 is valid.\n");
        return;
    }

    struct Node *temp = head;

    // Move to the node before the required position
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;

        // We have reached the head again
        if (temp == head) {
            printf("Invalid position!\n");
            return;
        }
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;
}

// Display the list
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;

    printf("Circular Doubly Linked List: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main() {
    insertBeginning(30);
    insertBeginning(20);
    insertBeginning(10);

    printf("After inserting at beginning:\n");
    display();

    insertPosition(25, 3);

    printf("After inserting 25 at position 3:\n");
    display();

    insertPosition(40, 5);

    printf("After inserting 40 at position 5:\n");
    display();

    return 0;
}