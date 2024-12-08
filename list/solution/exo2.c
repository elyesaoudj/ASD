#include <stdio.h>
#include "list.h"


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
    Node* head = createNode(1);
    Node* one = createNode(2);
    Node* two = createNode(3);
    Node* three = createNode(4);
    Node* four = createNode(5);
    setNext(head,one);
    setNext(one, two);
    setNext(two, three);
    setNext(three,four);
    

    Node* list = head;

    
    printf("\n");
    printList(list);

    
    
    return 0;
}
