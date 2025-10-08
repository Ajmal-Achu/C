#include <stdio.h>
#define MAX 100

void readMatrix(int mat[MAX][MAX], int rows, int cols) {
    printf("Enter elements of %dx%d matrix:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

int convertToSparse(int mat[MAX][MAX], int rows, int cols, int sparse[MAX][3]) {
    int k = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }
        }
    }
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = k - 1;
    return k;
}

void transposeSparse(int sparse[MAX][3], int trans[MAX][3]) {
    int rows = sparse[0][0];
    int cols = sparse[0][1];
    int nonZero = sparse[0][2];
    int k = 1;
    trans[0][0] = cols;
    trans[0][1] = rows;
    trans[0][2] = nonZero;
    for (int i = 0; i < cols; i++) {
        for (int j = 1; j <= nonZero; j++) {
            if (sparse[j][1] == i) {
                trans[k][0] = sparse[j][1];
                trans[k][1] = sparse[j][0];
                trans[k][2] = sparse[j][2];
                k++;
            }
        }
    }
}

void sparseToMatrix(int sparse[MAX][3], int mat[MAX][MAX]) {
    int rows = sparse[0][0];
    int cols = sparse[0][1];
    int terms = sparse[0][2];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] = 0;
        }
    }
    for (int i = 1; i <= terms; i++) {
        int r = sparse[i][0];
        int c = sparse[i][1];
        mat[r][c] = sparse[i][2];
    }
}

void printMatrix(int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void printSparse(int sparse[MAX][3], int size) {
    printf("Row Col Val\n");
    for (int i = 0; i < size; i++) {
        printf("%3d %3d %3d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

int main() {
    int rows, cols;
    int mat[MAX][MAX], transMat[MAX][MAX];
    int sparse[MAX][3], transSparse[MAX][3];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    readMatrix(mat, rows, cols);

    int size = convertToSparse(mat, rows, cols, sparse);

    printf("\nOriginal Sparse Matrix (Triplet Form):\n");
    printSparse(sparse, size);

    transposeSparse(sparse, transSparse);

    printf("\nTransposed Sparse Matrix (Triplet Form):\n");
    printSparse(transSparse, size);

    sparseToMatrix(transSparse, transMat);

    printf("\nTransposed Full Matrix:\n");
    printMatrix(transMat, cols, rows);

    return 0;
}
