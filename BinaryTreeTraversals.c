#include<stdio.h>
#include<stdlib.h>
int arr[10];
int x = 0;
struct node{
    int data;
    struct node * left;
    struct node* right;
};
struct node * root = NULL;
struct node * createNode(int data){
    struct node * newNode ;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(int data){     
    if ( root == NULL)
    {
        root = createNode(data);
    }
    else
    {   
        struct node * temp, *prev;
        temp = root;
        prev = NULL;
    while (temp != NULL)
    {
        /* code */
        prev = temp;
        if (data < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if (  data < prev->data)
        prev->left = createNode(data);
    else
        prev->right = createNode(data);
    } 
}
 void printLevelHeight(struct node *root, int level){
      if (root == NULL)
    {
        /* code */
        return;
    }
    if (level == 1)
    {
        /* code */
        printf(" %d", root->data);
    }
    else if(level > 1){
        printLevelHeight(root->left, level-1);
        printLevelHeight(root->right, level-1);    
    }
}  
   
int height(struct node *root){
    if(root == NULL)
    return 0;
    else
    {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if(leftHeight > rightHeight)
        return (leftHeight+1);
        else return(rightHeight + 1);
    }   
}

void LevelOrder(struct node * root){
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        /* code */
        printLevelHeight(root, i);
    }
}
void preOrder(struct node *root){
    if (root == NULL) 
    return;
    printf(" %d,", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct node *root){
    if (root == NULL) 
    return;
    postOrder(root->left);
    postOrder(root->right);
    printf(" %d,", root->data);
}

void inOrder(struct node *root){
    if (root == NULL) 
    return;
    inOrder(root->left);
    printf(" %d,", root->data);
    inOrder(root->right);
}
void printArr(){
    printf("\narray is:");
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        /* code */
        if (arr[i] == 0)
        {
            /* code */
            continue;
        }
        printf(" %d", arr[i]);
    }
}
void searchElement(struct node* root,int data){
    if (root == NULL)
    {
        /* code */
        printf("\nHush! ");
        return;
    }
    else if (root->data == data)
    {
        /* code */
        printf("\nElement %d is present\n", root->data);
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
        searchElement(root->right,data);
        return;
    }
    printf("No such element is present: %d\n ", data);
}
void main(){
    insert(20);
    insert(10);
    insert(30);
    insert(25);
    insert(5);
    insert(12);
    searchElement(root,10);
    printf("\nLevel order traversals is:");
    LevelOrder(root);
    printf("\nInorder traversals is:");
    inOrder(root);
    printf("\npreorder traversals is:");
    preOrder(root);
    printf("\npostorder traversals is:");
    postOrder(root);
    printArr();
}


// queue formation
 