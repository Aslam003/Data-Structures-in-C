#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define maxStackSize 100
int stack[maxStackSize];
int top = -1;

void push(int x){
    stack[++top] = x;
}
void pop(){
    top--;
}
int isempty(){
    if (top == -1)
    return 1;
    return 0;
    
}
char Top(){
    if (top == -1)
    {
        /* code */
        printf("\nStack is empty");
        return 0;
    }
    return stack[top];
}

int operationEval(int a,int b,int c){
    if (b == '+')
    {
        /* code */
        return a + c;
    }
    else if (b == '-')
    {
        /* code */
        return a - c;
    }
    else if (b == '*')
    {
        /* code */
        return a * c;
    }
    else if (b == '/')
    {
        /* code */
        return a / c;
    }
    
}
int postfixEvl(char *exp){
    int pop1, pop2;
    int res;
    printf("\n len: %d", strlen(exp));
    for (int i = 0; i < strlen(exp); i++)
    {
        /* code */
        if (isdigit(exp[i]))
        {
            /* code */
            push(exp[i]);
        }
        else if (exp[i] == '*' || exp[i] == '/' || exp[i] == '+' || exp[i] == '-')
        {
            /* code */
            pop2 = Top();
            pop();
            pop1 = Top();
            pop();
            res = operationEval(pop1 - '0', exp[i], pop2 - '0') + '0';

            push(res);
        }
    }
    return res - '0';
}
void infixToPostfix(char *infix){
    char infPostExp[100];
    int a = 0;
    char popped; 
    for (int i = 0; i < strlen(infix); i++)
    {
        /* code */
        if (isdigit(infix[i]))
        {
            /* code */
            infPostExp[a++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            /* code */
            push(infix[i]);
        }
        
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {   
            if (top == -1)
            {
                /* code */
                push(infix[i]);
                printf("d");
            }
            else if (Top() == '(')
            {
                /* code */
                push(infix[i]);
                
            }
            else if ((infix[i] == '*' || infix[i] == '/') && (Top() == '+' || Top() == '-') )
            {
                /* code */
                push(infix[i]);
            }
            else if ((infix[i] == '-' || infix[i] == '+') && (Top() == '*' || Top() == '/') )
            {
                /* code */
                popped = Top();
                infPostExp[a++] = popped;
                pop();
                push(infix[i]);
            }
            else if (infix[i] == '-' && Top() == '+')
            {
                /* code */
                push(infix[i]);
            }
            else if (infix[i] == '*' && Top() == '/' || infix[i] == '/' && Top() == '*')
            {
                /* code */
                push(infix[i]);
            }
            else if (infix[i] == '+' && Top() == '-')
            {
                /* code */
                
                popped = Top();
                infPostExp[a++] = popped;
                pop();
            }
            else if (infix[i] == Top() && Top() == '/')
            {
                /* code */
                push(infix[i]);
            }
            
            else if (infix[i] == Top() )
            {
                /* code */
                infPostExp[a++] = infix[i];
            } 
        }   
        else if (infix[i] == ')')
        {
            /* code */
            while (Top() != '(')
            {
                /* code */
                popped = Top();
                infPostExp[a++] = popped;
                pop();
            }
            pop();
        }      
    }
        while (isempty() == 0)
        {
            popped = Top();
            infPostExp[a++] = popped;
            pop();
            printf("\nexe");
        }
        infPostExp[a] = '\0';           
    printf("\nThe postfix expression is: ");
    for (int k = 0; k < strlen(infPostExp); k++)
    {
        /* code */
        printf("%c", infPostExp[k]);
    }
    printf("\nAfter evaluating the infix expression the solution is: %d", postfixEvl(infPostExp));
}
void main(){
    char infix[100];
    printf("Enter to infix expression: ");
    gets(infix);
    infixToPostfix(infix);   
}