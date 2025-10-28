#include <stdio.h>
struct poly {
    int coeff, exp;
};
int main() {
    struct poly p1[10], p2[10], res[20];
    int n1, n2, k = 0, i = 0, j = 0;
    printf("Enter no. of terms in poly 1: ");
    scanf("%d", &n1);
    for (i = 0; i < n1; i++) {
        printf("Enter coeff and exp for term %d: ", i + 1);
        scanf("%d %d", &p1[i].coeff, &p1[i].exp);
    }
    printf("Enter no. of terms in poly 2: ");
    scanf("%d", &n2);
    for (i = 0; i < n2; i++) {
        printf("Enter coeff and exp for term %d: ", i + 1);
        scanf("%d %d", &p2[i].coeff, &p2[i].exp);
    }
    i = j = 0;
    while (i < n1 && j < n2) {
        if (p1[i].exp == p2[j].exp) {
            res[k].coeff = p1[i].coeff + p2[j].coeff;
            res[k].exp = p1[i].exp;
            if (res[k].coeff != 0) k++;
            i++; j++;
        } else if (p1[i].exp > p2[j].exp) {
            res[k] = p1[i]; k++; i++;
        } else {
            res[k] = p2[j]; k++; j++;
        }
    }
    while (i < n1) { res[k] = p1[i]; k++; i++; }
    while (j < n2) { res[k] = p2[j]; k++; j++; }
    printf("Result: ");
    for (i = 0; i < k; i++) {
        printf("%dx^%d", res[k - 1 - i].coeff, res[k - 1 - i].exp);
        if (i < k - 1) printf(" + ");
    }
    printf("\n");
    return 0;
}
