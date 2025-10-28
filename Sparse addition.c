#include <stdio.h>
struct sparse {
    int row, col, val;
};

int main() {
    int m1[10][10], m2[10][10], res[10][10], rows, cols, i, j, n1 = 0, n2 = 0, k = 0;
    struct sparse s1[50], s2[50], sres[100];

    // Input normal matrices
    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter matrix 1 (%d x %d):\n", rows, cols);
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &m1[i][j]);
    printf("Enter matrix 2 (%d x %d):\n", rows, cols);
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &m2[i][j]);

    // Convert matrix 1 to sparse
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            if (m1[i][j] != 0) n1++;
    s1[0].row = rows; s1[0].col = cols; s1[0].val = n1;
    n1 = 1;
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            if (m1[i][j] != 0) {
                s1[n1].row = i;
                s1[n1].col = j;
                s1[n1].val = m1[i][j];
                n1++;
            }

    // Convert matrix 2 to sparse
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            if (m2[i][j] != 0) n2++;
    s2[0].row = rows; s2[0].col = cols; s2[0].val = n2;
    n2 = 1;
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            if (m2[i][j] != 0) {
                s2[n2].row = i;
                s2[n2].col = j;
                s2[n2].val = m2[i][j];
                n2++;
            }

    // Print sparse matrices
    printf("Sparse matrix 1 (row col value):\n");
    for (i = 0; i < n1; i++)
        printf("%d %d %d\n", s1[i].row, s1[i].col, s1[i].val);
    printf("Sparse matrix 2 (row col value):\n");
    for (i = 0; i < n2; i++)
        printf("%d %d %d\n", s2[i].row, s2[i].col, s2[i].val);

    // Add sparse matrices
    sres[0].row = rows; sres[0].col = cols; sres[0].val = 0; // Initialize header
    i = j = 1; k = 1;
    while (i < n1 && j < n2) {
        if (s1[i].row == s2[j].row && s1[i].col == s2[j].col) {
            sres[k].row = s1[i].row;
            sres[k].col = s1[i].col;
            sres[k].val = s1[i].val + s2[j].val;
            if (sres[k].val != 0) k++;
            i++; j++;
        } else if (s1[i].row < s2[j].row || (s1[i].row == s2[j].row && s1[i].col < s2[j].col)) {
            sres[k] = s1[i]; k++; i++;
        } else {
            sres[k] = s2[j]; k++; j++;
        }
    }
    while (i < n1) { sres[k] = s1[i]; k++; i++; }
    while (j < n2) { sres[k] = s2[j]; k++; j++; }
    sres[0].val = k - 1; // Update non-zero count

    // Print sparse result
    printf("Sparse result (row col value):\n");
    for (i = 0; i < k; i++)
        printf("%d %d %d\n", sres[i].row, sres[i].col, sres[i].val);

    // Convert sparse result to normal matrix
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            res[i][j] = 0;
    for (i = 1; i < k; i++)
        res[sres[i].row][sres[i].col] = sres[i].val;

    // Print result matrix
    printf("Resultant matrix (%d x %d):\n", rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }

    return 0;
}
