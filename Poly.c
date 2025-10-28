#include <stdio.h>
#include <stdlib.h>

struct poly {
    float coeff;
    int exp;
};

struct poly a[50], b[50], c[50]; 

int main()
{
    int i, deg1, deg2, m = 0; 
    
    printf("\n Enter the highest degree of poly 1: ");
    scanf("%d", &deg1);
    
    for (i = 0; i <= deg1; i++)
    {
        printf("\n Enter the coeff of x^%d: ", i);
        scanf("%f", &a[i].coeff);
        a[i].exp = i;
    }
    
    printf("\n Enter the highest degree of poly 2: ");
    scanf("%d", &deg2);
    
    for (i = 0; i <= deg2; i++)
    {
        printf("\n Enter the coeff of x^%d: ", i);
        scanf("%f", &b[i].coeff);
        b[i].exp = i;
    }
    
    printf("\n Expression 1 = %.2f", a[0].coeff);
    for (i = 1; i <= deg1; i++) 
    {
        printf(" + %.2fx^%d", a[i].coeff, a[i].exp);
    }
    
    printf("\n Expression 2 = %.2f", b[0].coeff);
    for (i = 1; i <= deg2; i++) 
    {
        printf(" + %.2fx^%d", b[i].coeff, b[i].exp);
    }
    
    if (deg1 > deg2)
    {
        for (i = 0; i <= deg2; i++)
        {
            c[m].coeff = a[i].coeff + b[i].coeff;
            c[m].exp = a[i].exp; 
            m++;
        }
        
        for (i = deg2 + 1; i <= deg1; i++)
        {
            c[m].coeff = a[i].coeff;
            c[m].exp = a[i].exp;
            m++;
        }
    }
    else
    {
        for (i = 0; i <= deg1; i++)
        {
            c[m].coeff = a[i].coeff + b[i].coeff;
            c[m].exp = a[i].exp;
            m++;
        }
        
        for (i = deg1 + 1; i <= deg2; i++)
        {
            c[m].coeff = b[i].coeff;
            c[m].exp = b[i].exp;
            m++;
        }
    }
    
    printf("\n\n Expression after addition = %.2f", c[0].coeff);
    
    for (i = 1; i < m; i++) 
    {
        printf(" + %.2fx^%d", c[i].coeff, c[i].exp);
    }
    
    printf("\n");
    
    return 0;
}