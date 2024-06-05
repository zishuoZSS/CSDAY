/*The offset is calculated to illustrate that m, n determines the return.*/
#include<stdio.h>
int two_dim_array_access(int* x, int i, int j, int m, int n, int C) {
    int p = ((m-i) * C + (n-j));
    return *(x + p);
}
int main() {
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};

    int result1 = two_dim_array_access(&A[0][0], 0, 0, 1, 2, 3);
    int result2 = two_dim_array_access(&A[1][2], 1, 2, 1, 2, 3);

    printf("Result 1: %d\n", result1); 
    printf("Result 2: %d\n", result2); 

    return 0;
}