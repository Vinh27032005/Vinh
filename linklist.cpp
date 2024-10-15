#include <conio.h>
#include "plistlib.h"
#include<stdio.h>

int a[]={32,51,27,83,66,45,11,5};

// a.ham nhap theo thu tu nhap
void appendList(int a[], int n, List *L){
	makeNull(&(*L));
	for(int i=0;i<n;i++){
		append(a[i],&(*L));
	}
}
// ham tao danh sach dao
void reverseList(int a[],int n, List *L){
	for (int i=0; i<n/2; i++){
		int tmp = a[i];
		a[i] = a[n-1-i];
		a[n-1-i] = tmp;
	}
	for (int j=0; j<n;j++)
		setAt(j,a[j],&(*L));
}


// ham sap xep bubble sort
void bubbleSort(List *L){
	PNode p = (Node*) malloc(sizeof(Node));
	PNode q = (Node*) malloc(sizeof(Node));
	p = *L;
	while (p->next != end(*L) ){
		q = p->next;
		while (q->next != NULL){
		if (p->next->data > q->next->data ) 
		{
			ElementType x = p->next->data;
			p->next->data = q->next->data;
			q->next->data = x;
			
		}
		q = q->next;
	}
	p = p->next;
}
}

// hàm chinh de chay chuong trinh
int main(int argc, char *argv[]){
	List L1;
	appendList(a, sizeof(a)/sizeof(int), &L1);
	print(L1);
	reverseList(a, sizeof(a)/sizeof(int), &L1);
	print(L1);
	insertAt(3,22,&L1);
	print(L1);
	bubbleSort(&L1);
	print(L1);
}


