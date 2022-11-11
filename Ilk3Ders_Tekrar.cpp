#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	
	int x;
	node* next;
	
	
}node;



void bastir(node*r);
node* sonaEkle(node*r, node* eklenen);
node* siraliEkle(node*r, node* eklenen);
node* nodeOlustur(int x);

node* elemanSil(node* r,int x);


int main(){
	
	
	node* root = NULL;
	
	
	root=siraliEkle(root,nodeOlustur(40));
	root=siraliEkle(root,nodeOlustur(30));
	root=siraliEkle(root,nodeOlustur(100));
	root=siraliEkle(root,nodeOlustur(70));
	root=siraliEkle(root,nodeOlustur(12));
	
	bastir(root);
	
	printf("****************************\n");
	root = elemanSil(root,40);
	
	bastir(root);
	
	return 0;
}


node* elemanSil(node* r,int x){
	
	
	
	if(r->x==x){
		r=r->next;
		printf("%d elemani listeden silindi!\n",x);
		return r;
	}
	
	node* iter=r;
	
	while(iter->next!=NULL&&iter->next->x!=x){
		iter=iter->next;	
	}
	
	if(iter->next==NULL){
		printf("%d degeri listede bulunamadi!\n",x);
	}
	
	iter->next=iter->next->next;
	printf("%d elemani listeden silindi!\n",x);
	return r;
	
}

node* siraliEkle(node*r,node* eklenen){
	
	//Liste bossa ekle
	if(r==NULL){
	r=eklenen;
	return r;	
	}
	
	//Listenin basina ekleme durumu
	if(eklenen->x < r->x){
		eklenen->next=r;
		r=eklenen;
		return r;
		
	}
	
	//Diger durumlar
	
	
	node* iter = r;
	
	while(iter->next!=NULL && eklenen->x > iter->next->x ){  // && ifadelerinin sagini solunu yer degisince yerini degistirince kod bozuluyor
		iter=iter->next;
	}
	
	eklenen->next=iter->next;
	iter->next=eklenen;
	return r;
	
	
	
	
}


node* sonaEkle(node* r, node* eklenen){
	
	if(r==NULL){
		r=eklenen;
		return r;
	}
	
	node* iter=r;
	while(iter->next!=NULL){
		iter=iter->next;
	}
	
	iter->next=eklenen;
	return r;
	
}
void bastir(node* r){
			
		int i=0;
	while(r!=NULL){
		printf("%d. elemanin x degeri: %d\n",i,r->x);
		i++;
		r=r->next;
	}
	
	
	
}
node* nodeOlustur(int x){
	node* temp = (node*) malloc(sizeof(node));
	temp->x=x;
	temp->next=NULL;
	return temp;
}