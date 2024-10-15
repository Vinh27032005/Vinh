#include <stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef int Position;

typedef struct NodeTag {
  ElementType data;
  struct NodeTag *next; 
}Node;

typedef Node *List;
typedef Node* PNode;
typedef List Stack;
/*
Initialize an empty list
*/
void makeNull(List *L){
 (*L) = (Node*) malloc (sizeof (Node));
 if (*L == NULL){
  printf( "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
 }
 (*L)->next = NULL;
}

/*
return Number of elements
*/
int len(List L){
 int count =0;
 PNode q = L;
 while (q->next != NULL){
  q= q->next;
  count++;
 }
 return count;
}

/*
Check whether the list is empty?
*/
int empty(List L){
 return (L->next == NULL);
}

/*
Check whether the list is full?
*/
int fullList(List L){
 
}

/*
Traverse the list to print out all elements
*/
void print(List L){
 if (empty(L)){
  printf ("List is empty"); return;}
 PNode q = L;
 while (q->next != NULL){
  printf ("%d ", q->next->data);
  q = q->next;
 }
 printf ("\n");
}
/*
Return the pointer referring to the ith element
*/
PNode getPosition(Position p, List L){
 if (empty(L) ||p < 0 || p > len(L)) {
        printf("Invalid position!\n");
        return NULL;
    }
 int countPosition = 0;
 PNode q = L;
 while (countPosition !=p ){
  q = q->next;
  countPosition++;
 }
 return q;
}
/*
Return the pointer referring to the next position of i in L
*/
PNode next(Position p,List L){
 if (empty(L) || p < 0 || p > len(L)) {
        printf("Invalid position!\n");
        return NULL;
    }
 PNode q = getPosition(p+1, L);
 return q;
}

/*
Return the pointer referring to the previous position of p in L
*/
PNode previous(Position p,List L){
 if (empty(L) || p < 0 || p > len(L)) {
        printf("Invalid position!\n");
        return NULL;
    }
 PNode q = getPosition(p-1, L);
 return q;
}
/*

/*
Return the element at position p
*/
ElementType getAt(Position p, List L){
 if (empty(L) || p < 0 || p > len(L)) {
        printf("Invalid position!\n");
        return NULL;
    }
 PNode q = getPosition(p, L);
 return q->next->data;
}
/*
Return the pointer referring to the first element of L
*/
PNode first(List L){
 return L;
}

/*
Return the pointer referring to the last element of L
*/
PNode end(List L){
 PNode q = L;
 while (q->next != NULL)
  q = q->next;
 return q;
}
/*
Update the element at position p by a new value
*/
void setAt(Position p, ElementType x,List *L){
 PNode q = getPosition(p, *L);
 q->next->data = x;
}
/*
Insert x at position p
*/
void insertAt(Position p, ElementType x, List *L){
 if (empty(*L) || p < 0 || p > len(*L)) {
        printf("Invalid position!\n");
        return ;
    }
 PNode q = getPosition(p, *L);
 PNode tmp = (Node*) malloc (sizeof(Node));
 if (tmp == NULL){
  printf( "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
 }
 tmp->data = x;
 tmp->next = q->next;
 q->next = tmp;
}
ElementType popAt(Position p, List *L){
 if (empty(*L) || p < 0 || p >= len(*L)) {
        fprintf(stderr, "Invalid position or empty list!\n");
        exit(EXIT_FAILURE);
    }
 PNode q = getPosition(p, *L);
 ElementType x = q->next->data;
 PNode tmp = next(p, *L);
 q->next = tmp->next ;
 free(tmp);
 return x;
}

/*
Insert x to the first position
*/
void insertFirst(ElementType x, List *L){
 PNode q = (Node*) malloc (sizeof(Node));
 if (q == NULL){
  printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
 }
 q->data = x;
 q->next = (*L)->next;
 (*L)->next = q;
}

/*
Remove and return the first element
*/
ElementType popFirst(List *L){
 if (empty(*L)) {
        printf("List is empty!\n");
        exit(EXIT_FAILURE);
    }
 PNode q = (*L)->next;
 ElementType x = (*L)->next->data;
 (*L)->next = (*L)->next->next;
 free(q);
 return x;
}
/*
Append a new element to the list
*/
void append(ElementType x,List *L){
 if ((*L)->next == NULL){
  PNode a = (Node*) malloc (sizeof (Node));
  if (a == NULL){
  printf( "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
 }
  a->data = x;
  (*L)->next = a;
  a->next = NULL;
 }
 else{
 PNode q = end(*L);
 PNode tmp = (Node*) malloc (sizeof (Node));
 tmp->data = x;
 q->next = tmp;
 tmp->next = NULL;
}
}

/*
Remove and return the last element
*/
ElementType popLast(List *L){
 if (empty(*L)) {
        printf("List is empty!\n");
        exit(EXIT_FAILURE);
    }
 PNode last = end(*L);
 PNode q = previous(len(*L), *L);
 ElementType x = q->next->data;
 q->next = NULL;
 free(last);
 return x;
}

/*
Return the position of the first appearance of x in the list
*/
Position locate(ElementType x, List L){
 PNode q = L;
 int  countPosition =0;
 while (q->next!= NULL ){
  if (q->next->data == x) return countPosition;
  else q = q->next;
 countPosition++;
 }
 return -1;
}
