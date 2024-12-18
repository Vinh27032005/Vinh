#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

//arrayStack
typedef int ElementType;
typedef struct{
	ElementType elements[MAXSIZE];
	int top;
}Stack;

void makeNullStack(Stack *S){
	S->top = -1;
}

int isEmpty(Stack S){
	return (S.top==-1);
}

int isFull(Stack S){
	return (S.top == MAXSIZE-1);
}

void push(ElementType x,Stack *S){
	if(isFull(*S))
		printf("Stack is full!!\n");
	else{
		S->top=S->top+1;
		S->elements[S->top]=x;
	}
}
ElementType pop(Stack *S){
	if(isEmpty(*S))
		printf("Stack is empty!!");
	else{
		ElementType x = S->elements[S->top];
		S->top=S->top-1;
		return x;
	}
}
void printStack(Stack *S){
	while(!isEmpty(*S)){
		printf("%d",pop(S));
	}printf("\n");
}

typedef int Position;
typedef int ElementType;
typedef struct{
 ElementType elements[MAXSIZE];
  Position size;
}List;
List L;
/*
Initialize an empty list
*/
void makeNull(List *L){
// Insert your code here
	L->size=0;
}

/*
return Number of elements
*/
int len(List L){
	return L.size;
}

/*
Check whether the list is empty?
*/
int empty(List L){
	return (L.size==0);
}

/*
Check whether the list is full?
*/
int fullList(List L){
	return (L.size==MAXSIZE);
	
}

/*
Traverse the list to print out all elements
*/
void printList(List L){
	Position i;
	for(i=1; i<=L.size;++i) printf("%d ", L.elements[i-1]);
	printf("\n");
}

/*
Return the element at position p
*/
ElementType getAt(Position p, List L){
// Insert your code here
	return L.elements[p-1];

}

/*
Return the first position in L
*/
Position first(List L){
// Insert your code here
	return 1;

}

/*
Return the end position in L
*/
Position endList(List L){
// Insert your code here
	return L.size+1;
}
/*
Update the element at position p by a new value
*/
void setAt(Position p, ElementType x,List *L){
// Insert your code here
	L->elements[p-1]= x;
}
/*
Insert x at position p
*/
void insertAt(Position p, ElementType x, List *L){
// Insert your code here
	if(fullList(*L)){
		printf("The list is full!!\n");
	}
	if(p<1 || p>L->size+1){
		printf("Position Error! Exit....");
		exit(EXIT_FAILURE);
	}else{
		Position q;
		for(q=L->size;q>=p;q--){
			L->elements[q]=L->elements[q-1];
		}
		L->size++;
		L->elements[p-1]=x;
	}
}
/*
Remove and return the element at position p
*/
ElementType popAt(Position p, List *L){
	ElementType x;
	if(p>=1 && p<=L->size){
		x= L->elements[p-1];
		Position q;	
		for(q=p;q<endList(*L);q++)
			L->elements[q-1]=L->elements[q];	
		L->size--;
		return x;
	}
	else{ 
		printf("Position Error! Exit....\n");
		exit(EXIT_FAILURE);
	}	
}
/*
Insert x to the first position
*/
void insertFirst(ElementType x, List *L){
// Insert your code here
	insertAt(first(*L), x, L);
}
/*
Remove and return the first element
*/
ElementType popFirst(List *L){
	return popAt(first(*L), L);
}
/*
Append a new element to the list
*/
void append(ElementType x,List *L){
// Insert your code here
	insertAt(endList(*L), x, L);
}

/*
Remove and return the last element
*/
ElementType popLast(List *L){
	return popAt(endList(*L), L);
}

/*
Return the position of the first appearance of x in the list
*/
Position locate(ElementType x, List L){
	Position p;
	int found=0;
	for(p=first(L);p<endList(L) && !found;p++)
			if (L.elements[p-1]==x) found=1;
		return p;
}

/*
Return the next position of p in L
*/
Position next(Position p,List L){
// Insert your code here
	if(p>=1 && p<=L.size){
		return p+1;
	}else{
		printf("Position Error! Exit....");
		exit(EXIT_FAILURE);
	}
}

/*
Return the previous position of p in L
*/
Position previous(Position p,List L){
	if(p>=1 && p<=L.size){
		return p-1;
	}
	else{ 
		printf("Position Error! Exit....\n");
		exit(EXIT_FAILURE);
	}	
}
