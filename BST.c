#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * left;
    struct node * right;
};
struct node* nodeCreation(int data){
    struct node* newNode;
    newNode  = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct node* insert(struct node* root, int data){
    if (root == NULL)
    {
        /* code */
        root = nodeCreation(data);
    }
    else if (data <= root->data)
    {
        /* code */
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}
void searchElement(struct node* root, int data){
    if (root == NULL)
    {
        /* code */
        printf("\nHush! ");
    }
    
    else if (root->data == data)
    {
        /* code */
        printf("\nElement %d is present", root->data);
        return;
    }
    else if (data <= root->data)
    {
        /* code */
        searchElement(root->left, data);
        return;
    }
    else if (data > root->data)
    {
        /* code */
        searchElement(root->right, data);
        return;
    }
    printf("No such element is present: %d", data);
}
void printMax(struct node * root){
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
    printf("\nMaximum element in the tree is %d", root->data);
}
void printMin(struct node * root){
    if(root == NULL)
    printf("\nNo elements in the tree");
    while (root->left != NULL)
    {
        /* code */
        root = root->left;
    }
    printf("\nMinimum element in the tree is %d", root->data);
    
}

int findHeight(struct node * root){
    if (root == NULL)
    {
        /* code */
        return -1;
    }
    
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return (leftHeight >= rightHeight ? leftHeight : rightHeight) + 1;
    
}

void main(){
    struct node * root = NULL;
    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 8);
    root = insert(root, 9);
    root = insert(root, 3);
    root = insert(root, 0);
    root = insert(root, 1);
    root = insert(root, 12);
    root = insert(root, 16);
    searchElement(root, 7);
    searchElement(root, 8);
    searchElement(root, 10);
    printMax(root);
    printMin(root);
    printf("\nHeight of the tree is: %d",findHeight(root));
}