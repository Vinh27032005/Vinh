#include <stdio.h>
#include "alistlib.h"
int a[]={32, 51,27,83,66,11,45,22,75};

void appendList(int a[], int n, List *L){
	makeNull(L);
	int i;
	for(i=0;i<n;i++){
		append(a[i],L);
	}
}

void swap(Position p, Position q, List *L){
	ElementType temp;
	temp=getAt(p,*L);
	setAt(p,getAt(q,*L),L);
	setAt(q,temp,L);
}

void bubbleSort(List *L){
	Position i,j;
	for(i=first(*L); i!=endList(*L); i=next(i,*L)){
		for(j = next(i,*L); j!=endList(*L); j=next(j,*L)){
			if(getAt(i,*L)>getAt(j,*L)){
				swap(i,j,L);
			}
		}
	}
}

int main(){
	List L1;
	appendList(a, sizeof(a)/sizeof(int), &L1);
	printList(L1);
	bubbleSort(&L1);
	printList(L1);
}
