#include<stdio.h>
#include<stdlib.h>
struct node
{
    /* data */
    int data;
    struct node* next;
    
};
void push(struct node* * headref, int newData){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = newData;
    newNode -> next = (*headref);
}

void main(){
    struct node * head;
    struct node * first;
    struct node * second;
   
   head = (struct node*)malloc(sizeof(struct node));
   
   first = (struct node*)malloc(sizeof(struct node));
   
   second = (struct node*)malloc(sizeof(struct node));
    head -> data = 10;
    head -> next = first;
    first -> data = 20;
    first -> next = second;
    second -> data = 30;
    second -> next = NULL;
printf("%d", head->next);

}