#include <stdio.h>
#include <stdlib.h>


#define queueSize 30


typedef struct dataType{
	int data;
}dataType;

typedef struct queueType{
	int front;
	int rear;
	dataType content[queueSize];
}queueType;
queueType queue;




//Function prototypes

int isEmpty(queueType q);
int isFull(queueType q);


int enqueue(queueType* qp,dataType* item);
int dequeue(queueType* qp);

int main(){
	queue.rear=-1;
queue.front=0;
	
	dataType  n;
	
	for(int i=1;i<=5;i++){
		n.data=i*10;
		
		enqueue(&queue,&n);	
		
	}
	printf("front %d rear %d\n",queue.front,queue.rear);
	
	for(int i=1;i<=3;i++){
		
		
		dequeue(&queue);	
		
	}
	
	for(int i=queue.front;i<=queue.rear;i++){
		printf("queue %d. : data: %d\n",(i+1),queue.content[i].data);
	}
	
		
}

int isEmpty(queueType q){
	
	return (q.rear-q.front+1<=0);
	
}
int dequeue(queueType* qp){
	
	if(isEmpty(*qp)) {
	printf("sıra bos\n");
	return 0;	
	}
	
	for(int i=1;i<=qp->rear;i++){
		qp->content[i-1] = qp->content[i];
	}
	qp->rear--;
	return 1;
}






int isFull(queueType q){
	return (q.rear-q.front+1>=queueSize);
}




int enqueue(queueType* qp,dataType* item){
		
	if(isFull(*qp)) {
	
	printf("Sıra dolu\n"); 
	return 0;	
	}
	
	qp->content[++(qp->rear)] = *item;
	return 1;
}





