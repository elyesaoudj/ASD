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

void sort (Node* head ){
        if (head == NULL || getNext(head)==NULL)
        return;

        Node* current=head;
        Node* NextNode;
        int swapped;

        do
        {
           swapped=0;
           current=head;
           int temp;
           while (getNext(current) != NULL  )
           {
            NextNode = getNext(current);
            if ( getValue(current) > getValue(NextNode) ){
            temp = getValue(current);
            setValue(current, getValue(NextNode));
            setValue(NextNode, temp);
            swapped = 1;
            }
            current=NextNode;
           }
            
        } while (swapped);
    }


int main()
{
    Node* head = createNode(10);
    setNext(head, createNode(30));
    setNext(getNext(head), createNode(20));

    printList(head);
    printf("\n");
    printf("sorted list :\n");
    sort(head);
    printList(head);
    
    
    return 0;
}
