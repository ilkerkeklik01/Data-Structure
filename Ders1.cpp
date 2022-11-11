#include <stdio.h>
#include <stdlib.h>

struct n{
	int x;
	n* next;
};
typedef n node ;


//Linked List
int main(){
	node* root; //bu linked listin headeri 
	
	root = (node*)malloc(sizeof(node));//memory allocation
	
	//şu an rootun gösterdiig yer listemin ilk kutusu
	
	/*
	(*root).x=2;
					Bu iki satır da listenin ilk elemanının x değerini değiştirmekte
	root->x=3;
	*/
	root->x=10;
	
	root->next=(node*)malloc(sizeof(node));
	root->next->x=20; 
	
	root->next->next=(node*)malloc(sizeof(node));
	root->next->next->x=30;
	
	root->next->next->next=NULL; //Listemdeki sonuncu elemanın nexti hiçbir şeyi göstermesin ki nerde duracagımı bileyim
		
	node* iter;
	iter=root;    //iterator rootla aynı yeri gösteriyor 
	
	
	
	while(iter!=NULL){
	printf("%d\n",iter->x);
	iter = iter->next;		
	}
	iter=root; //iterator ı başa aldım
	
	printf("*****************************************\n");
	
	//şimdi listenin sonuna bir eleman eklemeyi deneyelim
	int k=0;
	while(iter!=NULL){
		
		printf("iterator %d.elemani gosteriyor\n",k);
		k++;	
		iter=iter->next;
	} // bu dongunun sonunda iterator listenin son elemanının next pointerınnın gösterdiği yeri gösterir;
	
	printf("*****************************************\n");
	
	iter=(node*)malloc(sizeof(node));
	iter->x=40;
	iter->next=NULL;	
	
	iter=root;
	while(iter!=NULL){
	printf("%d\n",iter->x);
	iter = iter->next;		
	}
	
	//Gordugunuz gibi ekledigimiz son node hafızada kayıp durumda 
	//hemen düzeltelim
	
	printf("*****************************************\n");
	
	
	iter=root;
		int j=0;
	while(iter->next!=NULL){
		
		printf("iterator %d.elemani gosteriyor\n",j);
		j++;	
		iter=iter->next;
	}//Bu dongunun sonunda iterator sondan bir onceki elemanın nexti pointerının gosterdigi yeri gosterir.
	//Yani iterator sonuncu elemanı gösterir
	
	printf("*****************************************\n");
	
	//Şimdi listenin sonuna yeni bir eleman ekleyelim
	
	iter->next= (node*)malloc(sizeof(node));
	iter->next->x=40;
	iter->next->next=NULL;
	
	iter = root;
	
	
	while(iter!=NULL){
	printf("%d\n",iter->x);
	iter = iter->next;		
	}
	
	printf("*****************************************\n");
	
	//Simdi listemize dongu ile birden fazla eleman ekleyelim
	iter= root; //iterator i bastaki nesneyi gosterecek sekilde aldim
	
	
	while(iter->next!=NULL){
		iter=iter->next;      //bu donguyle iterator son elemani gosteriyor
		
	}
	
	for(int i=0;i<=5;i++){
		iter->next=(node*)malloc(sizeof(node)); //sondaki elemanin next pointerina node kadar memory allocate ettim
		iter=iter->next;							//iteri yeni ayirdigim node u gosterecek sekilde guncelledim
		iter->x=50+(i*10);						//node larin datalarini 10-10 artacak sekilde devam ettiriyorum
		iter->next=NULL;						//son elemanin next pointerini bosluga atiyorum ki sikinti cikmasin
	}
	
	//elemanlarin hepsini bastan gezelim
	
	iter=root;
	
	while(iter!=NULL){
		printf("%d\n",iter->x);		
		iter=iter->next;
	}
	
	
	 
	
	
	
	
	
	return 0;
}