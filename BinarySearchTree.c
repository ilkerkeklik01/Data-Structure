#include <stdio.h>
#include <stdlib.h>

typedef struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;

}node;

typedef node* nodePtr;

nodePtr getNewNode(int data){
    nodePtr newNode = (nodePtr) malloc(sizeof(node));
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->data=data;
    return newNode;
}

void insert(nodePtr* root , int data);

int search(nodePtr root, int data){
    if(root==NULL) return 0;
    else if(root->data==data) return 1;
    else if(data <= root->data) return search(root->left,data);
    else  return search(root->right,data);
}

int max=-999999999;
int findMax(nodePtr root){

    if(root==NULL) return max;
    else{
        max=root->data;
        findMax(root->right);
    }
    return max;

}

int min=999999999;
int findMin(nodePtr root){

    if(root==NULL) return min;
    else {
        min=root->data;
        findMin(root->left);
    }
    return min;

}


int main(){

    nodePtr root=NULL; // Creating an empty tree
    insert(&root,15);
    insert(&root,10);
    insert(&root,20);
    insert(&root,25);
    insert(&root,32);
    insert(&root,2132);
    insert(&root,232);
    insert(&root,5);
    insert(&root,22);
    insert(&root,23);
    insert(&root,-3);
    insert(&root,225);
    insert(&root,6);
    insert(&root,12);

    int num;
    printf("enter a number to be searched \n");

    scanf("%d",&num);
    printf("number to be searched: %d \n",num);

    int c = search(root,num);

    if(c==0) printf("not found");
    else if(c==1) printf("found");

    printf("\n max= %d", findMax(root));
    printf("\n min= %d", findMin(root));



    return 0;
}
void insert(nodePtr* rootPtr , int data){

    //inserting using recursion

    if(*rootPtr==NULL){ //empty tree
        *rootPtr = getNewNode(data);
        return;
    }
    else if(data <= (*rootPtr)->data){
        insert(&((*rootPtr)->left),data);
    }
    else if(data > (*rootPtr)->data){
        insert(&((*rootPtr)->right),data);
    }

}

