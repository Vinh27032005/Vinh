#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    char *digits;
    int length;
    int sign;
}BigNum;
void scanBigNum(BigNum *n,char c){
    char num[1000];
    printf("Enter %c:   ",c);
    scanf("%s", num);
    if(num[strlen(num)-1] == '\n')
        num[strlen(num)-1] = '\0';
    n->digits = (char *)malloc(strlen(num)+1);
    strcpy(n->digits,num);
    n->length = strlen(n->digits);
    for (int i = 0; i < n->length; i++) {
    n->digits[i] = num[n->length - 1 - i];
    }
    }
void printBigNum(BigNum num) {
    if (num.sign == -1) {
        printf("-");
    }
    for (int i = num.length - 1; i >= 0; i--) {
        printf("%c", num.digits[i]);
    }
    printf("\n");
}
int compareBigNum(BigNum a, BigNum b) {
    if (a.length > b.length) return 1;
    if (a.length < b.length) return -1;
    for (int i = a.length -1; i >= 0; i--) {
        if (a.digits[i] > b.digits[i]) return 1;
        if (a.digits[i] < b.digits[i]) return -1;
    }
    return 0;
}
void swap(BigNum *a, BigNum *b){
    BigNum temp = *a;
    *a = *b;
    *b = temp;
    }
BigNum sum(BigNum a,BigNum b){
    BigNum result;
    result.length = (a.length > b.length) ? a.length + 1 : b.length + 1;
    result.digits = (char *)malloc(sizeof(char) * (result.length + 1));

    int carry = 0;
    int k = 0; 
    for(int i = a.length - 1, j = b.length - 1 ; i>=0 || j>=0 || carry>0 ; i--, j--, k++){
                
        int aDigit = (i >= 0) ? a.digits[i] - '0' : 0;
        int bDigit = (j >= 0) ? b.digits[j] - '0' : 0;
        int sum = aDigit + bDigit + carry;
                
        result.digits[k] = (sum % 10) + '0';
        carry = sum / 10;
        }
    result.digits[k] = '\0';
    result.length = strlen(result.digits);
    return result;
    }
BigNum subtract(BigNum num1, BigNum num2) {
    BigNum result;
    result.digits = (char*)calloc(num1.length, sizeof(char));
    result.length = 0;
    result.sign = 1; 

    int compare = compareBigNum(num1, num2);

    if (compare == 0) { 
        result.digits[0] = '0';
        result.length = 1;
        return result;
    }
    int isNegative = (compare < 0) ? 1 : 0;
        
    BigNum larger = isNegative ? num2 : num1;
    BigNum smaller = isNegative ? num1 : num2;

    int borrow = 0;
    for (int i = 0; i < larger.length; i++) {
        int digit1 = larger.digits[i] - '0';
        int digit2 = (i < smaller.length) ? smaller.digits[i] - '0' : 0;

        int sub = digit1 - digit2 - borrow;
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.digits[result.length++] = sub + '0';
        }
    while (result.length > 1 && result.digits[result.length - 1] == '0') {
        result.length--;
    }
    result.sign = isNegative ? -1 : 1;

    return result;
}
int main(){
    BigNum a,b;
    scanBigNum(&a,'a');
    scanBigNum(&b,'b');
    printf("Add 2 number: ");
    printBigNum(sum(a,b));
    printf("Subtract 2 number: ");
    printBigNum(subtract(a,b)); 
            
    free(a.digits);	
    free(b.digits);
}