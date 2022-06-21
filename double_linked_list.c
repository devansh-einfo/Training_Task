#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertF(struct Node** head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = (*head);
    newNode->prev = NULL;
    if((*head) != NULL)
        (*head)->prev = newNode;
        (*head) = newNode;
}

void insertA(struct Node* prev_node, int data){
    if(prev_node == NULL){
        printf("Previous Node cannot be NULL");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    prev_node->next = newNode;
    newNode->prev = prev_node;
    if(newNode->next != NULL)
        newNode->next->prev = newNode;
}

void insertE(struct Node** head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    struct Node* temp = *head;
    if(*head == NULL){
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    
    while(temp->next != NULL)
        temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
}

void delete(struct Node** head, struct Node* del_node){
    if(*head == NULL || del_node == NULL)
        return;
        
        if(*head == del_node)
            *head = del_node->next;
        if(del_node->next != NULL)
            del_node->next->prev = del_node->prev;
        if(del_node->prev != NULL)
            del_node->prev->next = del_node->next;
}

void display(struct Node* node){
    struct Node* last;
    while (node != NULL){
        printf("%d->", node->data);
        last = node;
        node = node->next;
    }
    if(node == NULL)
        printf("NULL\n");
}

int main(){
    struct Node* head = NULL;
    insertE(&head, 8);
    insertF(&head, 3);
    insertF(&head, 5);
    insertE(&head, 7);
    
    insertA(&head, 33);
    insertA(head->next, 85);
    display(head);
    
    delete(&head, head->next->next->next->next->next);

    display(head);
    
}
