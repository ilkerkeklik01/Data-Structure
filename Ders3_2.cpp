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

	
	node* siraliEkle(node*r,int x){
		
		//Listenin bos olma durumu
		if(r==NULL){
			printf("Ilk durum ");
			r=(node*)(malloc(sizeof(node)));
			r->next=NULL;
			r->x=x;
			return r;
		}
		//Yeni gelen eleman ilk elemandan daha küçükse
			
			 if(x<r->x){
				printf("Ikinci durum ");
				node* temp =(node*)malloc(sizeof(node));
				temp->x=x; 
				temp->next=r;
				r=temp;
				return r;
			}
			
			//kalan bütün durumlar da burada değerlendirilir
		
		printf("Ucuncu durum ");
		node* iter =r;
		while(iter->next!=NULL && iter->next->x < x){
			iter=iter->next;
		}
		
		node* temp = (node*) malloc(sizeof(node));
		temp->x=x;
		temp->next= iter->next;
		iter->next=temp;
		
		return r;
		
	}


//Listelerde elemanlari sirali olarak ekleme
int main(){
	
	node* root =NULL;
	
	root=siraliEkle(root,400);
	root=siraliEkle(root,100);
	root=siraliEkle(root,300);
	root=siraliEkle(root,700);
	root=siraliEkle(root,200);
	root=siraliEkle(root,50);
	
	printf("\n");
	bastir(root);
	
	
	
	
}