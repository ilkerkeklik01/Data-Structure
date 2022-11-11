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
node* ekle(node* r,int x){            // r nin kendi uzerinde yaptigim degisiklikler maindeki rootu etkilemez  
	
		//liste ilk basta bosken bu islem yapilmali
	if(r==NULL){
		printf("r null");
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
	
		



int main(){
	
	node* root =NULL;
	
	for(int i=0;i<10;i++){
		root=ekle(root,(i*10));
	}
	
	bastir(root);
	
	
	
	
	
	return 0;
}