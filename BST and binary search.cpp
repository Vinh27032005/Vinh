// NLR
void pre_order(Tree T){
	if(T != NULL){
		printf("%d ",T->key);
		pre_order(T->left);
		pre_order(T->right);
}
}
// LNR 
void in_order(Tree T){
    if(T != NULL){
        in_order(T->left);
        printf("%d ",T->key);
        in_order(T->right);
    }
    
}
// LRN
void post_order(Tree T){
    if(T != NULL){
        post_order(T->left);
        post_order(T->right);
        printf("%d ",T->key);
    }
}
// search key and path
void print_path(int x, Tree T) {
    while (T != NULL) {
        printf("%d ", T->key);
        if (x == T->key) {
            printf(" --> Tim thay\n");
            return;
        } else if (x < T->key) {
            T = T->left;
        } else {
            T = T->right;
        }
    }
    printf(" --> Tim khong thay\n");
}
// height of tre
int get_height(Tree T) {
    if (T == NULL) {
        return -1;  // N?u cây r?ng, chi?u cao tr? v? là -1
    } else {
        int left_height = get_height(T->left);  // Chi?u cao c?a cây con trái
        int right_height = get_height(T->right);  // Chi?u cao c?a cây con ph?i

        // Chi?u cao c?a cây hi?n t?i là chi?u cao c?a cây con cao nh?t + 1
        if (left_height > right_height) {
            return left_height + 1;
        } else {
            return right_height + 1;
        }
    }
}
// binary search
int binarySearch(int x, List L){
	int startp, endp, midp;
	startp=0;
	endp=L.size-1;
	while (startp<=endp){
		midp= (startp+endp)/2;
		if(x==L.Elements[midp]){
			return midp;
		}else if (L.Elements[midp]>x){
			endp=midp-1;
		}else {
			startp=midp+1;
		}
	}
	return -1;
}
// delete node
Tree find_min(Tree T) {
    while (T->left != NULL) {
        T = T->left;
    }
    return T;
}
Tree delete_node(int x, Tree T) {
    // N?u cây r?ng, không có g? ð? xóa
    if (T == NULL) {
        return T;
    }

    // N?u khóa c?n xóa nh? hõn khóa c?a nút hi?n t?i, t?m trong cây con trái
    if (x < T->key) {
        T->left = delete_node(x, T->left);
    }
    // N?u khóa c?n xóa l?n hõn khóa c?a nút hi?n t?i, t?m trong cây con ph?i
    else if (x > T->key) {
        T->right = delete_node(x, T->right);
    }
    // Khi t?m th?y nút c?n xóa
    else {
        // Trý?ng h?p 1: Nút c?n xóa không có con (nút lá)
        if (T->left == NULL && T->right == NULL) {
            free(T);
            T = NULL;
        }
        // Trý?ng h?p 2: Nút c?n xóa ch? có m?t con
        else if (T->left == NULL) {
            Tree temp = T;
            T = T->right;
            free(temp);
        }
        else if (T->right == NULL) {
            Tree temp = T;
            T = T->left;
            free(temp);
        }
        // Trý?ng h?p 3: Nút c?n xóa có hai con
        else {
            // T?m nút nh? nh?t trong cây con ph?i (thay th? nút c?n xóa b?ng nút nh? nh?t)
            Tree temp = find_min(T->right);
            T->key = temp->key;
            // Xóa nút nh? nh?t trong cây con ph?i
            T->right = delete_node(temp->key, T->right);
        }
    }
    return T;
}





