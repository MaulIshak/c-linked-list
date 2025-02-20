#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

void printNodes(Node*);
Node* _getLastNode(Node*);
Node* createNewNode(int value);
void push(Node*, int value);
int getListLen(Node*);
int getListLen(Node*);
void pop(Node*);
Node* _getBeforeLastNode(Node* head);

int main() {
    Node *head = malloc(sizeof(Node));
    head->data = 10;
    head->next = NULL;
    
    Node *current = malloc(sizeof(Node));
    current->data = 98;
    current->next = NULL;
    head->next = current;
    
    // current = malloc(sizeof(Node));
    // current->data = 70;
    // current->next = NULL;
    // head->next->next = current;
    // Node *new = createNewNode(10);
    push(head, 10);
    push(head, 25);
    push(head, 80);
    push(head, 100);
    push(head, 124);
    pop(head);
    
    printNodes(head);

    printf("List Lenght: %d", getListLen(head));
    return 0;
}

void printNodes(Node *head){
    if(head == NULL){
        printf("No list to print");
    }else{
        Node *current = head;
        while(current->next != NULL){
            printf("[%d|%p] -> ", current->data, current->next);
            current = current->next;
        }
        printf("[%d|%p]\n", current->data, current->next);
    }
}

Node* _getLastNode(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node *current = head;
    while(current->next != NULL){
        current = current->next;
    }
    return current;
}
Node* _getBeforeLastNode(Node* head){
    if(head == NULL){
        return NULL;
    }else{
        Node *current = head;
        while(current->next->next != NULL){
            current = current->next;
        }
        return current;
    }

}

Node* createNewNode(int value){
    Node *node = malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}
int getListLen(Node* head){
    if(head != NULL){
        Node *current = head;
        int count = 1;
        while(current->next != NULL){
            current = current->next;
            count++;
        }
        return count;
    }else{
        return 0;
    }

}

void push(Node* head, int value){
    Node *last = _getLastNode(head);
    Node *new = createNewNode(value);
    last->next = new;
}

void pop(Node* head){
    if(head == NULL){
        printf("No node to pop");
    }else{
        Node *beforeLast = _getBeforeLastNode(head);
        free(beforeLast->next);
        beforeLast->next = NULL;
    }
}