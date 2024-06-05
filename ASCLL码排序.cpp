/*A sort function is defined to sort a two-dimensional character array,
 then a two-dimensional character array cA is created in the main function,
 the sort function is called to sort, and the sorted result is printed*/
#include <stdio.h>  
void sort(char arr[5][6]) {  
    int row = 5;  
    int col = 6;  
    char temp;  
  
    for (int i = 0; i < row - 1; i++) {  
        for (int j = 0; j < row - i - 1; j++) {  
            int sumA = 0, sumB = 0;  
            for (int k = 0; k < col; k++) {  
                sumA += (int)arr[j][k];  
                sumB += (int)arr[j + 1][k];  
            }  
            if (sumA > sumB) {  
                for (int k = 0; k < col; k++) {  
                    temp = arr[j][k];  
                    arr[j][k] = arr[j + 1][k];  
                    arr[j + 1][k] = temp;  
                }  
            }  
        }  
    }  
}  
  
int main() {  
    char cA[5][6] = {  
        {'S', 'D', 'U', 'Y', 'E', 'S'},  
        {'C', 'H', 'I', 'N', 'A', '!'},  
        {'A', 'F', 'T', 'E', 'R', 'X'},  
        {'h', 'e', 'r', 'o', 'a', 'b'},  
        {'C', 'y', 'y', 'D', 'S', '!'},    
    };  
    char cA_sorted[5][6];  
    sort(cA);  
    for (int i = 0; i < 5; i++) {  
        for (int j = 0; j < 6; j++) {  
            cA_sorted[i][j] = cA[i][j];  
        }  
    }  
    for (int i = 0; i < 5; i++) {  
        for (int j = 0; j < 6; j++) {  
            printf("%c ", cA_sorted[i][j]);  
        }  
        printf("\n");  
    }  
  
    return 0;  
}