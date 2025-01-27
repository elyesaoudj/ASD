#include <stdio.h>
#include "list.h"


Node* reverseDLlist(Node* head) {
    if(head == NULL){
        return NULL;
    }

    Node* current = head;
    Node* temp = NULL;

    while (current != NULL) {
        temp = getNext(current);
        setNext(current, getPrev(current));
        setPrev(current, temp);
        current = temp;
    }
    return getPrev(head);
}



