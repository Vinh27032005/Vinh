#include <stdio.h>
#include "alistlib.h"
#include"queuelib.h"
#define NumofE 20
int a[]={32, 51,27,83,66,11,45,22,75};

void pushStack(int a[], int n, Stack* S) {
    makeNullStack(S);
    
    for (int i = 0; i < n; i++) {
        push(a[i], S);
        printf("%d ", a[i]);
    }
    printf("\n");
}
void reverseStack(Stack* S) {
    Queue Q;
    makenull(&Q); 

    // chuyen phan tu tu ngan xep vao hang doi
    while (!isEmptyStack(*S)){
        enQueue(pop(S), &Q);
    }

    // chuyen phan tu tu hang doi vao lai ngan xep
    while (!isEmpty(Q)) {
        push(deQueue(&Q), S);
    }
}
void printStack1(Stack S) {
	
    for (int i = 0; i <= S.top; i++) {
        printf("%d ", S.elements[i]);
    }
    printf("\n");
}

void bringinttoqueue(int a[], int n, Queue *pQ){
	makenull(pQ);
	int i;
	for(i=0;i<n;i++){
		enQueue(a[i],pQ);
	}
}
void printQueue(Queue q){
	
	if(!isEmpty(q)){
		int k = size(q);
	
		for(int i=0;i<k;i++){
			printf("%d ",q.elements[(i+q.front)%MaxSize]);
		}
		printf("\n");
	}else printf("hang doi trong\n");
	
}
void reverseQueue(Queue *Q) {
    Stack S;
    makeNullStack(&S);

    while (!isEmpty(*Q)) {
        push(deQueue(Q), &S);
    }

    while (!isEmptyStack(S)) {
        enQueue(pop(&S), Q);
    }
}

void printString(int *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d", a[i]);
    printf("\n");
}

void PCQueue(){
	int random[NumofE];
	for(int i=0;i<NumofE;i++){
		random[i] = rand() % 2;
	}
	printString(random,NumofE);
	Queue q;
	makenull(&q);
	for(int i=0;i<NumofE;i++){
	if(random[i]){
		printf("nguoi san xuat hay dua du lieu vao trong hang doi:\n");
		enQueue(1,&q);
	}else{
		printf("nguoi tieu dung su dung san pham: %d trong hang doi ",deQueue(&q));
	}
	printQueue(q);
	}
}
int main(){
	Stack L1;
	pushStack(a, sizeof(a)/sizeof(int), &L1);

	reverseStack(&L1);
	printStack1(L1);
	
	Queue Q1;
	
	bringinttoqueue(a, sizeof(a)/sizeof(int), &Q1);
	printQueue(Q1);
	
	reverseQueue(&Q1);
	printQueue(Q1);
	
	PCQueue();
	
}

