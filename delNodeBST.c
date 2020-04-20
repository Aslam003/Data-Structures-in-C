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
void inOrder(struct node *root){
    if (root == NULL) 
    return;
    inOrder(root->left);
    printf(" %d", root->data);
    inOrder(root->right);
}
Node findMin(Node root){
    //printf("data:%d", root->data);
    Node temp = root;
    while (temp->left!= NULL)
    {
        /* code */
        temp = temp->left;
    }
    return temp;
}

Node delete(Node root, int data){
    if (root == NULL)
    {
        /* code */
        return root;
    }
    else if (data < root->data)
    {
        /* code */
        root->left = delete(root->left, data);
    }
    else if(data > root->data){
        root->right = delete(root->right, data);
    }
    else{
        if(root->left == NULL && root->right ==NULL){
            free(root);
            root = NULL;
        }
        else if(root->left == NULL){
            Node temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL){
            Node temp = root;
            root = root->left;
            free(temp);
        }
        else{
            
            Node temp = findMin(root->right);
            printf("min:%d", temp->data);
            root->data = temp->data;
            root->right = delete(root->right,temp->data);
            
        }
    }
    return root;
}

void main(){
    root = insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 25);
    insert(root, 35);
    insert(root, 15);
    insert(root, 50);
    delete(root,20);
    delete(root,30);
    printf("\nelemets are");
    inOrder(root);   
}