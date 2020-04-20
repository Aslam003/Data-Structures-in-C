//Using Arrays
#include<stdio.h>
# define MaxStackSize  100
int stack[MaxStackSize];
int Top = -1;
void top(){
    if (Top == -1)
    {
        /* code */
        printf("stack is empty");
        return ;
    }
    printf("%d", stack[Top]);
}

void push(int data){
    if (Top == MaxStackSize - 1)
    {
        /* code */
        printf("Stack overflow");
        return; 
    }
    
    stack[++Top] = data;
    return;
}
void pop(){
    if (Top == -1) {
    printf("Stack is empty");
    return;
    }
    Top--;
}
void print(){
    for (int i = 0; i <= Top; i++)
    {
        /* code */
        printf(" %d", stack[i]);
    }
    
}

int main(){
push(5);
pop();
push(2);
pop();
push(4);
push(1);
top();
print();
}