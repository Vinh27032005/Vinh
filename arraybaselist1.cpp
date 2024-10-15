#include "alistlib.h"
#include <stdio.h>
void swap(Position q, Position p, List *L){
	ElementType temp = L->elements[p-1];
	L->elements[p-1]= L->elements[q-1];
	L->elements[q-1]= temp;
}
void sort(List *L){
	Position p,q;
	p=first(*L);
	while(p!=endList(*L)){
		q=next(p,*L);
		while(q!=endList(*L)){
			if(getAt(p,*L) > getAt(q,*L)){
				swap(p,q,L);
			}
			q=next(q,*L);
		}
		p=next(p,*L);
	}
}
int main(){
	List L;
	makeNull(&L);
	int n,tmp;

	printf("Enter the number of elements:  ");
	scanf("%d",&n);
	int i;
	for(i=0; i<n; i++){
		printf("Enter element %d: ",i+1);
		scanf("%d", &tmp);
		append(tmp,&L);
	}
	printf("Unsort List: ");
	printList(L);

	sort(&L);

	printf("Sort List: ");
	printList(L);
}
