#include<stdio.h>
#include<stdlib.h>
struct node
{
    /* data */
    int data;
    struct node * link;
};
struct node * rear = NULL;
struct node * front = NULL;

int IsEmpty(){
    if (rear == NULL && front == NULL)
    {
        /* code */
        return 1;
    }
    return 0;

}
void Enqueue(int data){
    struct node * temp;
    temp = (struct node *) malloc(sizeof(struct node));
    (*temp).data = data;
    (*temp).link = NULL;
    if (rear == NULL && front == NULL)
    {
        /* code */
        rear = front = temp;
        return;
    }
    (*rear).link = temp;
    rear = temp;
}
int Dequeue(){
    struct node * temp;
    if (IsEmpty())
    {
        /* code */
        printf("Queue is empty");
        return 0;
    }
    else if (front == rear)
    {
        /* code */
        temp = front;
        front = rear = NULL;
    }
    else
    {
        temp = front;
        front = (*front).link;
    }
    free(temp);   
}
int Front(){
    if (IsEmpty())
    {
        /* code */
        printf("Queue is empty");
        return NULL;
    }
    return front->data;
}

void main(){
    Enqueue(5);
    Enqueue(10);    
    Dequeue();
    Enqueue(20);
    Dequeue();
    printf("Front is: %d",Front());
}
