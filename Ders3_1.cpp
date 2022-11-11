#include <stdio.h>
#include <stdlib.h>
typedef struct n{
	int x;
	n* next;
}node;


void bastir(node* r){
	
	
	
	while(r!=NULL){
		printf("%d ",r->x);
		r=r->next;
	}
	
}
node* ekle(node* r,int x){ 
	if(r==NULL){
		r=(node*)malloc(sizeof(node));
		r->x=x;
		r->next=NULL;
	return r;
	}
	node* iter=r;
	
	while(iter->next!=NULL){
		iter=iter->next;
	}
	
	iter->next=(node*)malloc(sizeof(node));
	iter=iter->next;
	iter->x=x;
	iter->next=NULL;
	return r;	
}	
	


//Listelerde araya eleman ekleme
int main(){
	
	node* root =NULL;
	for(int i=0;i<5;i++){
		root =ekle(root,(i*10));
	}
	bastir(root);
	
	//Let us add an element 15 between 10-20 
	
	node* iter =root;
	iter=iter->next; //iter su an 10 u gosteriyor
	
	node eklenecekNode ;
	eklenecekNode.x=15;
	
	eklenecekNode.next=iter->next;
	iter->next=&eklenecekNode;
	
	printf("\n");
	bastir(root);
	
	//Let us add an element 35 between 30-40 
	
	node* iter2 = root;
	for(int i=0;i<4;i++){
		iter2=iter2->next;
	}
	//iter2 30 u gosteriyor
	
	node* temp = (node*)malloc(sizeof(node));
	temp->x=35;
	
	//ilk once temp sonraki elemana baglansin ki listenin geri kalaniyla baglantimiz kopmasin
	temp->next=iter2->next; //temp su an 40 i gosteriyor
	iter2->next=temp;
	
	printf("\n");
	
	bastir(root);
	
	return 0;
}