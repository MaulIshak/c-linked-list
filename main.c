#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

void printNodes(Node*);

int main() {
    Node *head = malloc(sizeof(Node));
    head->data = 10;
    head->next = NULL;
    
    Node *current = malloc(sizeof(Node));
    current->data = 98;
    current->next = NULL;
    head->next = current;
    
    current = malloc(sizeof(Node));
    current->data = 70;
    current->next = NULL;
    head->next->next = current;
    
    current = malloc(sizeof(Node));
    current->data = 100;
    current->next = NULL;
    head->next->next->next = current;
    

    printNodes(head);
    return 0;
}

void printNodes(Node *head){
    Node *current = head;
    while(current->next != NULL){
        printf("[%d|%p] -> ", current->data, current->next);
        current = current->next;
    }
    printf("[%d|%p]", current->data, current->next);
}