#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertB(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insertA(struct Node* prev_node, int new_data){
    if(prev_node == NULL){
        printf("Previous node cannot be NULL");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void insertE(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if(*head_ref == NULL){
        *head_ref = new_node;
         return;
    }
    while (last->next != NULL) last = last->next;
    last->next = new_node;
    return;
}

void delete(struct Node** head_ref, int key){
    struct Node *temp = *head_ref, *prev;
    
    if(temp != NULL && temp->data == key){
        *head_ref = temp->next;
        return;
    }
    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
    return;
    prev->next = temp->next;
}

void print(struct Node* node){
    while(node != NULL){
        printf("%d->", node->data);
        node = node->next;
    }
}

int main(){
    struct Node* head = NULL;
    
    insertE(&head, 9);
    insertB(&head, 5);
    insertB(&head, 2);
    insertE(&head, 1);
    insertA(head->next, 8);
    
    printf("Linked list: ");
    print(head);
    
    printf("\nAfter Deleting: ");
    delete(&head, 2);
    print(head);
}