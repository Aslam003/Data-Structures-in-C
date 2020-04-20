#include<stdio.h>
#define queueMaxSize 100
int queue[queueMaxSize];
int front = -1; 
int rear = -1;
int IsEmpty(){
    if (front == -1 && rear == -1)
    {
        /* code */
        return 1;
    }
    return 0;
}
void Enqueue(int data){
    if ((rear + 1) % sizeof(queue) == front)
    {
        /* code */
        printf("Queue if full");
        return;
    }
    else if (IsEmpty())
    {
        /* code */
        rear = front = 0;
    }
    else
    {
        
        rear = (rear + 1) % sizeof(queue);
    }
    queue[rear] = data;
    
}
int Dequeue(){
    if (IsEmpty())
    {
        /* code */
        printf("Queue is empty");
    }
    else if (front == rear)
    {
        /* code */
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % sizeof(queue);
    }
    
}
int Front(){
    if (IsEmpty())
    {
        /* code */
        printf("Queue is empty");
        return 0;
    }
    printf("front is: %d",queue[front]);
    return queue[front];
}

void main(){
    Enqueue(5);
    Enqueue(7);
    Front();
    Dequeue();
    Dequeue();
    Enqueue(8);
    Front();
}