#include <stdio.h> 
#define MAX 100 
// Function to read a matrix 
void readMatrix(int mat[MAX][MAX],
int rows, int cols) { 
printf("Enter elements of %dx%d
matrix:\n", rows, cols); 
for(int i = 0; i < rows; i++) 
for(int j = 0; j < cols; j++) 
scanf("%d", &mat[i][j]); 
} 
// convertoriginal matrixtosparserepresentation 
int convertToSparse(int mat[MAX][MAX],
int rows, int cols, int sparse[MAX][3]) { 
    int k = 1; 
    for(int i = 0; i < rows; i++) { 
        for(int j = 0; j < cols; j++) { 
            if(mat[i][j] != 0) { 
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
// Function to print sparse matrix 
void printSparse(int sparse[MAX][3], int size) { 
    printf("Sparse Matrix Representation:\n"); 
    for(int i = 0; i < size; i++) 
        printf("%d %d %d\n", sparse[i][0],
        sparse[i][1], sparse[i][2]); 
} 
 
// Function to add two sparse matrices 
int addSparse(int sp1[MAX][3],
int sp2[MAX][3], int result[MAX][3]) { 
    if(sp1[0][0] != sp2[0][0] ||
    sp1[0][1] != sp2[0][1]) { 
        printf("Matrix dimensions 
        do not match.\n"); 
        return -1; 
    } 
 
    int i = 1, j = 1, k = 1; 
    int total1 = sp1[0][2]; 
    int total2 = sp2[0][2]; 
 
    while(i <= total1 && j <= total2) { 
        if(sp1[i][0] == sp2[j][0] &&
        sp1[i][1] == sp2[j][1]) { 
            result[k][0] = sp1[i][0]; 
            result[k][1] = sp1[i][1]; 
            result[k][2] = 
            sp1[i][2] + sp2[j][2]; 
            i++; j++; k++; 
        } else if(sp1[i][0] < sp2[j][0] || 
                (sp1[i][0] == sp2[j][0]
                && sp1[i][1] < sp2[j][1])) 
                { 
            result[k][0] = sp1[i][0]; 
            result[k][1] = sp1[i][1]; 
            result[k][2] = sp1[i][2]; 
            i++; k++; 
        } else { 
            result[k][0] = sp2[j][0]; 
            result[k][1] = sp2[j][1]; 
            result[k][2] = sp2[j][2]; 
            j++; k++; 
        } 
    } 
 
    while(i <= total1) { 
        result[k][0] = sp1[i][0]; 
        result[k][1] = sp1[i][1]; 
        result[k][2] = sp1[i][2]; 
        i++; k++; 
    } 
 
    while(j <= total2) { 
        result[k][0] = sp2[j][0]; 
        result[k][1] = sp2[j][1]; 
        result[k][2] = sp2[j][2]; 
        j++; k++; 
    } 
 
    result[0][0] = sp1[0][0]; 
    result[0][1] = sp1[0][1]; 
    result[0][2] = k - 1; 
 
    return k; 
} 
 
// Function to convert sparse to original matrix 
void sparseToMatrix(int sparse[MAX][3],
int result[MAX][MAX]) { 
    int rows = sparse[0][0]; 
    int cols = sparse[0][1]; 
    int total = sparse[0][2]; 
 
    // Initialize to zero 
    for(int i = 0; i < rows; i++) 
        for(int j = 0; j < cols; j++) 
            result[i][j] = 0; 
 
    for(int i = 1; i <= total; i++) 
        result[sparse[i][0]][sparse[i][1]]
        = sparse[i][2]; 
} 
 
// Function to print a matrix 
void printMatrix(int mat[MAX][MAX], 
int rows, int cols) { 
printf("Matrix:\n"); 
for(int i = 0; i < rows; i++) { 
for(int j = 0; j < cols; j++) 
printf("%d ", mat[i][j]); 
printf("\n"); 
} 
} 
// Main function 
int main() { 
int rows, cols; 
int mat1[MAX][MAX], mat2[MAX][MAX]; 
int sparse1[MAX][3], sparse2[MAX][3],
sparseSum[MAX][3]; 
int resultMat[MAX][MAX]; 
printf("Enter number of rows and columns: "); 
scanf("%d %d", &rows, &cols); 
// Read original matrices 
printf("\nMatrix 1:\n"); 
readMatrix(mat1, rows, cols); 
printf("\nMatrix 2:\n"); 
readMatrix(mat2, rows, cols); 
// Convert to sparse 
int size1 = convertToSparse(mat1, 
rows, cols, sparse1); 
int size2 = convertToSparse(mat2,
rows, cols, sparse2); 
// Print sparse matrices 
printf("\nSparse Matrix 1:\n"); 
printSparse(sparse1, size1); 
printf("\nSparse Matrix 2:\n"); 
printSparse(sparse2, size2); 
// Add sparse matrices 
int sumSize = addSparse(sparse1,
sparse2, sparseSum); 
if(sumSize == -1) return 1;  
// Print sparse sum 
printf("\nSparse Matrix Sum:\n"); 
printSparse(sparseSum, sumSize); 
// Convert to original matrix 
sparseToMatrix(sparseSum, resultMat); 
// Print final matrix 
printf("\nFinal Resultant Matrix:\n"); 
printMatrix(resultMat, rows, cols); 
return 0; 
}