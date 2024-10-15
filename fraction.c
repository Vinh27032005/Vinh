#include <stdio.h>
#include <math.h>
typedef struct{
    int numerator;
    int denominator;
}Fraction;
int UCLN(int a,int b){
    int temp;
    a=abs(a);
    b=abs(b);
    while(b!=0){
        temp=b;
        b=a%b;
        a=temp;
    }return a;
}
Fraction simplify(Fraction frac){
    int ucln= UCLN(frac.numerator,frac.denominator);
    frac.numerator /= ucln;
    frac.denominator /=ucln;
    return frac;
}
Fraction read(){
    Fraction ps1;
    printf("Nhap phan so:");
    scanf("%d/%d",&ps1.numerator,&ps1.denominator);
    return ps1;
}
void print(Fraction p){
    printf("%d/%d\n",p.numerator,p.denominator);
}
Fraction add(Fraction p1, Fraction p2){
    Fraction result;
    result.numerator=p1.numerator*p2.denominator+p2.numerator*p1.denominator;
    result.denominator=p1.denominator*p2.denominator;
    return simplify(result);
}
Fraction subtract(Fraction p1, Fraction p2){
    Fraction result;
    result.numerator=p1.numerator*p2.denominator-p2.numerator*p1.denominator;
    result.denominator=p1.denominator*p2.denominator;
    return simplify(result);
}
Fraction multiply(Fraction p1, Fraction p2){
    Fraction result;
    result.numerator=p1.numerator*p2.numerator;
    result.denominator=p1.denominator*p2.denominator;
    return simplify(result);
}
Fraction divide(Fraction p1, Fraction p2){
    Fraction result;
    result.numerator=p1.numerator*p2.denominator;
    result.denominator=p1.denominator*p2.numerator;
    return simplify(result);
}
int main(){
    Fraction ps1=read();
    Fraction ps2=read();
    printf("Cong hai phan so: ");
    print(add(ps1,ps2));
    printf("Tru hai phan so: ");
    print(subtract(ps1,ps2));
    printf("Nhan hai phan so: ");
    print(multiply(ps1,ps2));
    printf("Chia hai phan so: ");
    print(divide(ps1,ps2));
}