#include"stdio.h"
#include"stdlib.h"
typedef int DataType;
struct Node {
	DataType data;
	struct Node *left;
	struct Node *right;
};
typedef struct Node* Tree;
Tree T;

void makeNull(Tree *pT){
	(*pT) = NULL;
}
int emptytree(Tree T){
	return T == NULL;
}
Tree create2(DataType v,Tree l, Tree r){
	Tree N;
	N = (struct Node*)malloc(sizeof(struct Node));
	N->data = v;
	N->left = l;
	N->right = r;
	return N;
}
Tree leftchild(Tree n){
	if(n!=NULL){
		return n->left;
	}else{
		return NULL;
	}
}
Tree rightchild(Tree n){
	if(n!=NULL){
		return n->right;
	}else{
		return NULL;
	}
}

void NLR(Tree root){
	if(!emptytree(root)){
		printf("%c ",root->data);
		NLR(root->left);
		NLR(root->right);
}
}
void LNR(Tree root){
	if(!emptytree(root)){
		LNR(root->left);
		printf("%c ",root->data);
		LNR(root->right);
}
}
void LRN(Tree root){
	if(!emptytree(root)){
		LRN(root->left);
		LRN(root->right);
		printf("%c ",root->data);
}
}
int nb_nodes(Tree root){
	if(emptytree(root))
	return 0;
	else return 1 + nb_nodes(leftchild(root))+ nb_nodes(rightchild(root));
	
}
int isLeaf(Tree n){
	if(n!=NULL) return(leftchild(n) == NULL) && (rightchild(n) == NULL);
	else return 0;

}
int nb_leaf(Tree root){
	if(emptytree(root)){
		return 0;
	}else if(isLeaf(root)){
		return 1;
	}else return nb_leaf(rightchild(root)) + nb_leaf(leftchild(root));

}
int main(){
//	Tree T1,T2,T3,T4,T5,T6,T7;
//	makeNull(&T7);
//	//T = create2('+', create2('*',create2('3',NULL,NULL),create2('5',NULL,NULL)),create2('7',NULL,NULL));
//	T1 = create2('+',create2('a',NULL,NULL),create2('b',NULL,NULL));
//	T2 = create2('+',create2('d',NULL,NULL),create2('e',NULL,NULL));
//	T3 = create2('*',create2('c',NULL,NULL),T2);
//	T4 = create2('+',T1,T3);
//	T5 = create2('+',T4,create2('f',NULL,NULL));
//	T6 = create2('+',create2('g',NULL,NULL),create2('8',NULL,NULL));
//	T7 = create2('*',T5,T6);
//	NLR(T7);
//	printf("\n------------------------------");
//	printf("\n");
//	LNR(T7);
//	printf("\n------------------------------");
//	printf("\n");
//	LRN(T7);
//	printf("\n------------------------------");
//	printf("\n");
//	nb_nodes(T7);
//	int count1 = nb_nodes(T7);
//	printf("%d\n",count1);
//	int count2 = nb_leaf(T7);
//	printf("%d",count2);
//	
//	
Tree T1,T2,T3,T4,T5,T6,T7;
	makeNull(&T7);
	T1 = create2('+',create2('2',NULL,NULL),create2('7',NULL,NULL));
	T2 = create2('+',create2('a',NULL,NULL),create2('c',NULL,NULL));
	T3 = create2('*',create2('8',NULL,NULL),T2);
	T4 = create2('+',T1,T3);
	T5 = create2('+',T4,create2('k',NULL,NULL));
	T6 = create2('+',create2('b',NULL,NULL),create2('d',NULL,NULL));
	T7 = create2('*',T5,T6);
	NLR(T7);
	printf("\n------------------------------");
	printf("\n");
	LNR(T7);
	printf("\n------------------------------");
	printf("\n");
	LRN(T7);
	printf("\n------------------------------");
	printf("\n");
	nb_nodes(T7);
	int count1 = nb_nodes(T7);
	printf("%d\n",count1);
	int count2 = nb_leaf(T7);
	printf("%d",count2);

}


