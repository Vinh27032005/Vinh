#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100
typedef struct {
    int a;
    int n;
} Term;
typedef struct {
    Term terms[MAX_TERMS];
    int num;
} Polynomial;

Polynomial createPolynomial() {
    Polynomial poly;
    poly.num = 0; 
    return poly;
}
// Function to insert a term into a polynomial
void insertTerm(Polynomial* poly, int a, int n) {
    if (a == 0) return;
    int i = poly->num - 1;
    
    while (i >= 0 && poly->terms[i].n < n) {
        poly->terms[i + 1] = poly->terms[i];
        i--;
    }
    
    if (i >= 0 && poly->terms[i].n == n) {
        poly->terms[i].a += a;
 	}
    else {
        poly->terms[i + 1].a = a;
        poly->terms[i + 1].n = n;
        poly->num++;
    }
}
// Funciton to take polynomial from user
Polynomial inputPolynomial() {
    Polynomial poly = createPolynomial();
    int num;
    printf("Nhap so hang co trong da thuc: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        int a, n;
        printf("Nhap he so va so mu %d: ", i + 1);
        scanf("%d %d", &a, &n);
        insertTerm(&poly, a, n);
    }
    return poly;
}
// Function to print a polynomial
void printPolynomial(Polynomial poly) {
    for (int i = 0; i < poly.num; i++) {
    	if(poly.terms[i].n!=0)
        printf("%dx^%d", poly.terms[i].a, poly.terms[i].n);
        else
        printf("%d", poly.terms[i].a);
        if (i != poly.num - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}
// Function to add two polynomials
Polynomial add(Polynomial poly1, Polynomial poly2) {
    Polynomial result = createPolynomial();

    int i = 0, j = 0;
    while (i < poly1.num && j < poly2.num) {
        if (poly1.terms[i].n > poly2.terms[j].n) {
            insertTerm(&result, poly1.terms[i].a, poly1.terms[i].n);
            i++;
        } else if (poly1.terms[i].n < poly2.terms[j].n) {
            insertTerm(&result, poly2.terms[j].a, poly2.terms[j].n);
            j++;
        } else {
            int new_a = poly1.terms[i].a + poly2.terms[j].a;
            insertTerm(&result, new_a, poly1.terms[i].n);
            i++;
            j++;
        }
    }

    while (i < poly1.num) {
        insertTerm(&result, poly1.terms[i].a, poly1.terms[i].n);
        i++;
    }

    while (j < poly2.num) {
        insertTerm(&result, poly2.terms[j].a, poly2.terms[j].n);
        j++;
    }

    return result;
}
// Function to compute the derivative of a polynomial
Polynomial derivate(Polynomial poly) {
    Polynomial result = createPolynomial();

    for (int i = 0; i < poly.num; i++) {
        if (poly.terms[i].n != 0) {
            int new_a = poly.terms[i].a * poly.terms[i].n;
            int new_n = poly.terms[i].n - 1;
            insertTerm(&result, new_a, new_n);
        }
    }

    return result;
}

