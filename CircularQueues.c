#include <stdio.h>
#include <stdlib.h>




#define queueSize 10


int dequeue();
void enqueue(int x);
int isEmpty();
int isFull();


int front = -1;
int rear = -1; 

int queue[queueSize];

/*
	if the index of the current position is i, the next position must be (i+1) % queueSize in the circular queue 
	
	if i == queueSize -1(last index of array) next position must be queueSize % queueSize which is 0 
	
	
	(i + queueSize -1 ) % queueSize  is the previous position  (i did add queueSize to make value positive )
	
*/

int main(){
	
	
	
	
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	enqueue(6);
	enqueue(7);
	enqueue(8);
	enqueue(9);
	enqueue(10);

	
	printf("\nsilinen %d \n",dequeue());
	printf("\nsilinen %d \n",dequeue());
	printf("\nsilinen %d \n",dequeue());
	printf("\nsilinen %d \n",dequeue());
	printf("\nsilinen %d \n",dequeue());
	printf("\nsilinen %d \n",dequeue());
	printf("\nsilinen %d \n",dequeue());
	printf("\nsilinen %d \n",dequeue());
	printf("\nsilinen %d \n",dequeue());

	

	enqueue(11);
	enqueue(12);
	enqueue(13);
	
	
	
	
	
	
	
	//yazdıramıyorum şaka gibi
	
	
	printf("front: %d rear: %d \n\n",front,rear);
	
	
	
	
	
	
	if(rear>=front){
		for(int i=front;i<=rear;i++){
		
		if(i!=-1){
		
		printf("value: %d --- ",queue[i]);
		
			
		}
		
			
	}
	}else{
		
		for(int i=front;i<queueSize;i++){
			
			printf("value1: %d --- ",queue[i]);
		
		}
		for(int i=0;i<=rear;i++){
			printf("value2: %d --- ",queue[i]);
		}
		
		
		
		
	}
	
	
	
	
	return 0;
}

int isEmpty(){
	if(front==-1&&rear==-1){
		return 1;
	}
	else {
		return 0;	
	}
	
	
	
}

void enqueue(int x){
	if(isFull()){
	
		return;
	}else if(isEmpty()){
		front=0;
		rear=0;
	}else{
		rear = (rear+1)%queueSize;
	}
	queue[rear]=x;
	
	
	
}
int isFull(){

	if(((rear+1)%queueSize)==front){
		printf("\nFULL\n");
		return 1;
	}
	
	return 0;
}

int dequeue(){
	if(isEmpty()){
		printf("\nbos\n");
		return-9999;
	}else if(front==rear){
		int temp =front;
		front=-1;
		rear=-1;
		return queue[temp];
	}else{
		int temp = front;
		front=(front+1)%queueSize;
		return queue[temp];
	}
	
	
	
}





