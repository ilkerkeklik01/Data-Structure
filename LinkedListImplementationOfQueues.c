#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	int data;	
	struct node* next;
	
}node;

typedef node* nodePtr;



//Linked list implementation of queue
//FIFO
//dequeue from the beginning of the linked list
//enqueue to the last of the linked list

void enqueue(nodePtr* root,int x,nodePtr* end);

int dequeue(nodePtr* root);

void bastir(node* r);
int main(){
	nodePtr root = NULL;
	nodePtr end = NULL;
	
	
	
	for(int i=1;i<=100;i++){
		enqueue(&root,i,&end);
	}
	
	bastir(root);
	printf("\n");
	for(int i=1;i<=50;i++){
		dequeue(&root);
	}
	
	bastir(root);
	printf("\n");
	for(int i=1;i<=50;i++){
		enqueue(&root,i*10,&end);
	}
	
	bastir(root);
	
	
	
	
	
	return 0;
}


void enqueue(nodePtr* root,int x,nodePtr* end){
		if(*root==NULL){
			*root= (nodePtr)malloc(sizeof(node));
			(*root)->data=x;
			(*root)->next=NULL;
			*end = *root; 	 
			 
			return ;
		}
		
		(*end)->next = (nodePtr)malloc(sizeof(node));
		(*end)->next->data=x;
		(*end)->next->next=NULL;
		*end = (*end)->next;
	
}

int dequeue(nodePtr* root){
	if(root==NULL){
		printf("Sira bos");
		return -1;
	}
	
	int rValue =(*root)->data;
	node* temp = *root;
	*root=(*root)->next;
	free(temp);
	return rValue;
	
	
}
void bastir(node* r){
	
	
	
	while(r!=NULL){
		
		printf("%d ",r->data);
		r=r->next;
	}
	
}



