#include"stdio.h"
#include"conio.h"
#define MaxSize 500
typedef int ElementType;
typedef struct {
ElementType elements[MaxSize];
int front, rear;
}Queue;

void makenull(Queue*pQ){
	pQ->front = 0;
	pQ->rear = pQ->front;
}
int isEmpty( Queue pQ){
	return pQ.front == pQ.rear;
}
int size(Queue pQ){
	return(pQ.rear + MaxSize - pQ.front) % MaxSize;
}
int fullQueue(Queue pQ){
	return(pQ.rear + 1) % MaxSize == pQ.front;
}
void enQueue (ElementType x, Queue *pQ){
	if(fullQueue(*pQ)){
		printf("ERROR") ;
	}
	pQ->elements[pQ->rear] = x;
	pQ->rear = (pQ->rear + 1) % MaxSize;
}
ElementType deQueue (Queue *pQ){
	if(isEmpty(*pQ)){
		return -1;
	}
	ElementType x = pQ->elements[pQ->front];
	pQ->front = (pQ->front + 1) % MaxSize;
	return x;
}

