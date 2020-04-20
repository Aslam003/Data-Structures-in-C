#include<stdio.h>
#include<stdlib.h>
 struct node{
     struct node *prev;
     int data;
     struct node* next;
 };
 struct node *head;
struct node *createNewNode(int data){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
 void insertFirst(int data){
    struct node *temp;
    temp = createNewNode(data);
    if(head == NULL)
    {
        /* code */
        head = temp;
        return;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;

      
 }
 void insertLast(int data){
     struct node *temp, *temp2;
     temp = createNewNode(data);
     temp2 = head;
     if (head == NULL)
     {
         /* code */
         head = temp;
         return;
     }
     while (temp2->next != NULL)
     {
         /* code */
         temp2 = temp2->next;
     }
     temp->prev = temp2;
     temp2->next = temp;
       
 }
 void delete(int n){
     struct node *temp, *ptr;
     ptr = head;
     if (n == 1)
     {
         /* code */
         temp = ptr;
         head = ptr->next;
         free(temp);
     }
     else
     {
         
         for (int i = 0; i < n - 2; i++)
         {
             /* code */
             ptr = ptr->next;
         }
         temp = ptr->next;
         ptr->next = temp->next;
         free(temp);
     }
 }
     
void deleteElement(int data){
    struct node *temp1, *temp2, *ptr;
    ptr =  head;
    while ((*ptr).data != data)
    {
        /* code */
        ptr = (*ptr).next;
    }
    if ((*ptr).data == head->data)
    {
        /* code */
        temp1 = ptr;
        temp2 = temp1->next;
        head = (*temp1).next;
        temp2->prev = NULL;
        free(temp1);
    }
    else
    {
        temp1 = ptr;
        temp2 = ptr->prev;
        (*temp2).next = temp1->next;
        temp2 = temp1->next;
        temp2->prev = temp1->prev;
        free(temp1);
    }  
}
 void print(){
     struct node *temp;
     temp = head;
     while (temp != NULL)
     {
         /* code */
         printf(" %d", temp->data);
         temp = temp->next;
     }
     
 }
 void main(){
     head = NULL;
     insertFirst(1);
     insertFirst(5);
     insertFirst(3);
     insertLast(8);
     insertLast(10);
    //  delete(1);
    //  delete(4);
    deleteElement(8);
    deleteElement(1);
     print();

 }