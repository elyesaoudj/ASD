#include <stdio.h>
#include "list.h"

void reverse(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* nextNode = NULL;

    // Traverse the list
    while (current != NULL) {
        // Store the next node
        nextNode = getNext(current);

        // Reverse the current node's pointer
        setNext(current, prev);

        // Move the prev and current pointers one step forward
        prev = current;
        current = nextNode;
    }

    // Update the head to the last node (which is now the first node)
    *head = prev;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", getValue(current));  // Print the value of the current node
        current = getNext(current);           // Move to the next node
    }
    printf("NULL\n");  // End of list
}
int main()
{
    Node* head = createNode(10);
    setNext(head, createNode(20));
    setNext(getNext(head), createNode(30));

    printList(head);
    printf("\n");
    printf("reversed list :\n");
    reverse(&head);
    
    printList(head);
    return 0;
}
