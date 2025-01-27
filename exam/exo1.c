#include <stdio.h>
#include "list.h"


Node* initializeList() {
    Node* head = createNode(1);
    Node* current = head;

    for (int i = 2; i <= 5; i++) {
        Node* newNode = createNode(i);
        setNext(current, newNode);
        current = newNode;
    }
    return head;
}

//  insert node at the head of the list
Node* InsertAtHead(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        setNext(newNode, *head);
        *head = newNode;
    }
    return *head;
}

// insert node at the end of the list
void insertAtEnd(Node* head, int value) {
    Node* newNode = createNode(value);
    Node* current = head;

    while (getNext(current) != NULL) {
        current = getNext(current);
    }
    setNext(current, newNode);
}

// insert node in the middle of the list
void InsertAtMiddle(Node* head, int value) {
    if (head == NULL) {
        printf("Error: List is empty. Cannot insert in the middle.\n");
        return;
    }

    Node* slow = head;
    Node* fast = head;
    Node* newNode = createNode(value);

    while (fast != NULL && getNext(fast) != NULL) {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    }

    Node* temp = getNext(slow);
    setNext(slow, newNode);
    setNext(newNode, temp);
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", getValue(current));
        current = getNext(current);
    }
    printf("NULL\n");
}

int main() {
    // Initialize the list with values 1 to 5
    Node* list = initializeList();
    printf("Initial list:\n");
    printList(list);

    // Insert a value in the middle
    printf("\nInserting 3 in the middle:\n");
    InsertAtMiddle(list, 3);
    printList(list);

    // Insert a value at the head
    printf("\nInserting 0 at the head:\n");
    InsertAtHead(&list, 0);
    printList(list);

    // Insert a value at the end
    printf("\nInserting 6 at the end:\n");
    insertAtEnd(list, 6);
    printList(list);

    return 0;
}
