/*Implementation of Matrix Multiplication with Three-layer for Loop*/
#include <stdio.h>
void matrix_multi(double A[3][4], double B[4][5], double C[3][5]) {
    int i, j, k;
    for (i = 0; i < 3; i++) {        
       for (j = 0; j < 5; j++) {    
            C[i][j] = 0;               
            for (k = 0; k < 4; k++) { 
                C[i][j] += A[i][k] * B[k][j]; 
            }
        }
    }
}

int main() {
    
    double A[3][4] = {
        {1, 2, 34, 4},
        {5, 61, 7, 8},
        {9, 1, 11, 17}
    };
    double B[4][5] = {
        {13, 14, 15, 16, 17},
        {14, 29, 20, 21, 22},
        {3, 28, 25, 36, 27},
        {8, 29, 50, 31, 32}
    };
    double C[3][5]; 

    
    matrix_multi(A, B, C);

    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%.2f ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}