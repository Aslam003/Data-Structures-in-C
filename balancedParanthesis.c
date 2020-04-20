#include<stdio.h>
#include<string.h>
#define maxStackSize 100
int stack[maxStackSize];
int top = -1;
char Top(){
 if (top == -1)
 {
     /* code */
     printf("\nstack empty you can't push wrong paranthesis ");
     return 0;
 }
 return stack[top];
}
void push(char a){
    stack[++top] = a;
}
void pop(){
    if (top == -1)
    {
        /* code */
        printf("stack empty");
        return;
    }
    top--;
}
void main(){
    char str[100];
    printf("Enter the paranthesis string: ");
    gets(str);
    for (int i = 0; i < strlen(str); i++)
    {
        /* code */
        if (str[i] == '{' || str[i] == '[' || str[i] == '(')
        {
            /* code */
            push(str[i]);
        }
        else if (str[i] == ')' && Top() == '(' || str[i] == '}' && Top() == '{' || str[i] == ']' && Top() == '[')
        {
            /* code */
            pop();
        } 
    }
    if (top == -1)
    {
        /* code */
        printf("\nParanthesis is balanced");
    }
    else
    {
        
        printf("\n Incorrect paranthesis");
    }
    
    
    
}