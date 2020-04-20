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
Node search(Node root, int data){
    if (root == NULL)
    {
        /* code */
        return NULL;
    }
    else if (root->data == data)
    {
        /* code */
        return root;
    }
    
    if (data <= root->data)
    {
        /* code */
        search(root->left, data);
    }
    else search(root->right, data);
}

Node inorderSuccessor(Node root, int data){
    Node successor = NULL, ancestor;
    Node find = search(root, data);
    if (find == NULL)
    {
        /* code */
        printf("No such element");
        return 0;
    }
    else if (find->right != NULL)
    {
        /* code */
        successor = find->right;
        while (successor->left != NULL)
        {
            /* code */
            successor = successor->left;
        }
    }
    else 
    {
        /* code */
        ancestor = root;
        while (ancestor != find)
        {
            /* code */
            if (find->data < ancestor->data)
            {
                /* code */
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else{
                ancestor = ancestor->right;
            }
        }
    }
    
    return successor;
}
void main(){
    root = insert(root,20);
    insert(root,10);
    insert(root,30);
    insert(root,15);
    insert(root,17);
    insert(root,52);
    insert(root,9);
    insert(root,22);
    insert(root,82);
    insert(root,18);
    insert(root,5);
    insert(root,42);
    insert(root,12);
    insert(root,3);
    Node successor = inorderSuccessor(root, 34);
    if (successor == NULL)
    {
        /* code */
        printf("\nThere is no successor");
    }
    else
    printf("\nThe successor is: %d", successor->data);
}