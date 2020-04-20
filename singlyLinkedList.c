#include<stdio.h>
#include<stdlib.h>
void reverse();
void recursiveReverse();
struct node{
    int data;
    struct node* next;
};
struct node * head;
void insert(int key, int data){
    struct node* newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if(key == 1){
        newNode->next = head;
        head = newNode;
        return;
    }
    temp = head;
    for(int k = 1; k < key-1; k++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
int insertFirst(int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if(head != NULL)
    temp->next = head;
    head = temp;
    return 0;
    }
int insertLast(int y){
    struct node *lastNode, *temp;
    lastNode = (struct node*)malloc(sizeof(struct node));
    lastNode->data = y;
    lastNode->next = NULL;
    if(head == NULL){
    head = lastNode;
    return 0;
    }
    temp = head;
    while (temp->next != NULL){
    temp = temp->next;
    }
    temp->next = lastNode;    
}
void delete(int n){
    struct node *temp1, *temp2;
    temp1 = head;
    if(n == 1){
        head = temp1->next;
        free(temp1);
    }
    for (int i = 0; i < n-2 ; i++)
        temp1 = temp1->next;
    temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}
void deleteLast(){
    struct node *temp, *temp2;
    temp = head;
    if(head == NULL)
    printf("\nLinked list is empty");
    else if (temp->next == NULL)
    {
        /* code */
        head = NULL;
        free(temp);            
    } 
    else
    {
        while (temp->next != NULL)
        {
            /* code */
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = NULL;
        free(temp);
    }
}
void deleteFirst(){
    struct node* temp;
    temp = head;
    if(head == NULL)
    printf("\nList is empty");
    head = temp->next;
    free(temp);
}
void print(){
    struct node* temp = head;
    while (temp != NULL)
    {
        /* code */
        printf(" %d", temp->data);
        temp = temp->next; 
    }  
    printf("\n");
}
void recursivePrint(struct node* ptr){
    if(ptr == NULL)
    return;
    printf(" %d", ptr->data);
    recursivePrint(ptr->next);
}
void recursiveReversePrint(struct node* revPtr){
    if(revPtr == NULL)
    return;
    recursiveReversePrint(revPtr->next);
    printf(" %d", revPtr->data);
}
int main(){
    int i,x,y,n,key;
    head = NULL;
    printf("\nEnter number of items to insert: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
          scanf("%d", &y);
          insertFirst(y);
     }
    //  insert(1,1);
    //  insert(2,2);
    //  insert(3,5);
    //  insert(2,2);
    // delete(3);
    // deleteLast();
    // deleteFirst();
    print();
    //recursivePrint(head);
    //printf("\n");
    //recursiveReversePrint(head);
    //reverse();
    recursiveReverse(head);
    print();
    return 0;
}
void reverse(){
    struct node *prev, *current, *next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        /* code */
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    //print();
}

void recursiveReverse(struct node *ptr){
    struct node *prev;
    if(ptr->next == NULL)
    {
        /* code */
        head = ptr;
        return;
    }
    recursiveReverse(ptr->next);
    
    prev = ptr->next;
    prev->next = ptr;
    ptr->next = NULL;
}