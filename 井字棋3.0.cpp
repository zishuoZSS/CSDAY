#include<stdio.h>    
  
char table[3][3] = {    
    {' ', ' ', ' '},    
    {' ', ' ', ' '},    
    {' ', ' ', ' '}    
};    
  
char Player = 'X';    
  
int Checkwin() {    
    for (int i = 0; i < 3; i++) {    
        if (table[i][0] == Player && table[i][1] == Player && table[i][2] == Player) {    
            return 1;    
        }    
        if (table[0][i] == Player && table[1][i] == Player && table[2][i] == Player) {    
            return 1;    
        }    
    }    
    if (table[0][0] == Player && table[1][1] == Player && table[2][2] == Player) {    
        return 1;    
    }    
    if (table[0][2] == Player && table[1][1] == Player && table[2][0] == Player) {    
        return 1;    
    }    
    return 0;  
}    
  
void update(int *i, int *j) {    
    int x, y;  
    do {  
        printf("Please enter a position (row col): ");    
        if (scanf("%d %d", &x, &y) != 2) {  
            while (getchar() != '\n');  
            printf("Invalid input. Please enter two integers.\n");  
            continue;  
        }  
        x--;   
        y--;    
        if ((x < 0) || (x >= 3) || (y < 0) || (y >= 3) || table[x][y] != ' ') {    
            printf("Try again.\n");    
        } else {    
            table[x][y] = Player;    
            *i = x;   
            *j = y;    
            break;  
        }  
    } while (1);  
}  
  
void print() {    
    for (int i = 0; i < 3; i++) {    
        for (int j = 0; j < 3; j++) {    
            printf("%c | ", table[i][j]);    
        }    
        printf("\n");    
        for (int k = 0; k < 3; k++) {    
            printf("---");    
        }    
        printf("\n");    
    }    
}    
  
void game() {    
    int i, j;    
    printf("Three, Two, One, Go!\n");    
    print();    
    while (1) {    
        update(&i, &j);     
        print();  
        if (Checkwin()) {    
            printf("The winner is Player %c\n", Player);    
            break;    
        }    
        Player = (Player == 'X') ? 'O' : 'X';    
    }    
}    
  
int main() {    
    game();    
    return 0;    
}