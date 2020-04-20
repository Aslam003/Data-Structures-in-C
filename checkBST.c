#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node * left;
    struct node * right;
};
typedef struct node * Node;
Node root = NULL;

Node createNewnode(int data){
    Node newNode =(Node)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode; 
}
Node insert(Node root,int data){
    if (root == NULL)
    {
        root = createNewnode(data);
        return root;
    }
    else if (data <= root->data)
    {
        /* code */
        root->left = insert (root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
}


int printMax(struct node * root){
    if (root == NULL)
    {
        /* code */
        printf("\nNo elements in the tree");
    }
    
    while (root->right != NULL)
    {
        /* code */
        root = root->right;
    }
    return root->data;
}
int printMin(struct node * root){
    if(root == NULL)
    printf("\nNo elements in the tree");
    while (root->left != NULL)
    {
        /* code */
        root = root->left;
    }
    return root->data;
}

bool isBST(Node root, int min, int max){
    if (root == NULL)
    {
        return true;
    }
    if ((root->data > min) && (root->data < max) && isBST(root->left, min, root->data) && isBST(root->right, root->data, max))
    {
        /* code */
        return true;
    }
    else return false;  
}

void main(){
    root = insert(root,20);
    insert(root,10);
    insert(root,30);
    insert(root,5);
    int max = printMax(root);
    int min = printMin(root);
    if (isBST)
    {
        /* code */
        printf("The above constructed tree is a binary tree:");
    }
    
}