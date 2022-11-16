#include <stdio.h>
#include <stdlib.h>



typedef struct node{

    int data;
    struct node* next;

}node;

typedef node* nodePtr;


void enqueue(int x);
int dequeue();
void printQueue();
int frontElement();
int isEmpty();



nodePtr front = NULL;
nodePtr rear =NULL;

/*
 *
 * enqueue to rear
 * dequeue from front
 *
 * if we try to dequeue to rear we must be assign rear pointer to previous element of queue which is impossible
 */

int main(){

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    dequeue();
    dequeue();
    dequeue();
    enqueue(31);
    enqueue(32);
    enqueue(33);

    printQueue();




    return 0;
}
void enqueue(int x){
    if(front== NULL){
        front = (nodePtr) malloc(sizeof(node));
    front->data=x;
    front->next=NULL;
    rear=front;
    return;
    }

    rear->next=(nodePtr) malloc(sizeof(node));
    rear->next->data=x;
    rear->next->next=NULL;
    rear=rear->next;
}

int dequeue(){

    int temp;

    if(front== NULL){
        printf("The queue is already empty");
        return -9999;
    }else if(front==rear){
        temp=front->data;
        front=NULL;
        rear=NULL;
        return temp;
    }else{
        nodePtr tempPtr = front;
        temp=tempPtr->data;
        front=front->next;
        free(tempPtr);
        return temp;
    }

}

void printQueue(){
    nodePtr iter=front;

    while(iter!=NULL){
        printf("%d -- ",iter->data);

        iter=iter->next;
    }

}

