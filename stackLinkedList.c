#include<stdio.h>
#include<stdlib.h>

struct node
{
    /* data */
    int data;
    struct node *link;
};
struct node *top = NULL;
int isEmpty(){
    if (top == NULL)
    return 1;
    return 0;
}
void Top(){
    if (isEmpty())
    {
        /* code */
        printf("Stack is empty");
        return;
    }
    struct node *temp;
    temp = top;
    printf("%d",temp->data);
}

void push(int data){
    struct node * temp;
    temp = (struct node*)malloc(sizeof(struct node));
    (*temp).data = data;
    (*temp).link = NULL;
    if (top == NULL)
    {
        /* code */
        top = temp;
        return;
    }
    (*temp).link = top;
    top = temp;
    
}
void pop(){
    if (!isEmpty)
    {
        /* code */
        printf("Stack is empty");
        return;
    }
    struct node *temp;
    temp = top;
    top = (*temp).link;
    free(temp);    
}

void main(){
    push(5);
    push(2);
    pop();
    pop();
    Top();
}