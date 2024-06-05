#include<stdio.h>  
int col[8] = {0};  
int diag1[15] = {0};  
int diag2[15] = {0};  
int queens[8] = {0};  
int count = 0;  
  
int safe(int rows, int cols) {  
    if (col[cols])  
        return 0;  
    if (diag1[rows - cols + 7])  
        return 0;  
    if (diag2[rows + cols])  
        return 0;  
    else  
        return 1;  
}  
void print() {  
    int i, j;  
    for (i = 0; i < 8; i++) {  
        for (j = 0; j < 8; j++) {  
            if (queens[i] == j)  
                printf("Q ");  
            else  
                printf(". ");  
        }  
        printf("\n");  
    }  
    printf("\n"); 
}  
  
int solve(int n) {  
    if (n == 0) {  
        count++; 
        print();   
        return 1;  
    }  
    int i;  
    for (i = 0; i < 8; i++) {  
        if (safe(n, i)) {  
            queens[n] = i;  
            col[i] = 1;  
            diag1[n - i + 7] = 1;  
            diag2[n + i] = 1;  
            if (solve(n-1))  
            return 1;
            queens[n] = 0;  
            col[i] = 0;  
            diag1[n - i + 7] = 0;  
            diag2[n + i] = 0;  
        }  
    }  
    return 0;  
}   
int main() {  
    solve(7); 
    printf("Total solutions: %d\n", count); 
    return 0;  
}