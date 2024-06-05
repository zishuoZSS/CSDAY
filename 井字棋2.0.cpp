#include<stdio.h>  
  
char table[3][3] = {  
    {' ', ' ', ' '},  
    {' ', ' ', ' '},  
    {' ', ' ', ' '}  
};  
  
table[i][j+1] == Playechar Player = 'X';  
  
int Checkwin() {  for (int i = 0; i < 3; i++) {  
        if (table[i][0] == Player && table[i][1] == Player && table[i][2] == Player) {  
            return 1; //row 
        }  
        if (table[0][i] == Player && table[1][i] == Player && table[2][i] == Player) {  
            return 1; // col
        }  
    }  
    if (table[0][0] == Player && table[1][1] == Player && table[2][2] == Player) {  
        return 1; // diag1  
    }  
    if (table[0][2] == Player && table[1][1] == Player && table[2][0] == Player) {  
        return 1; // diag2
    }  
    return 0;
      
}   
void update(int i, int j) {  
    int x, y;  
    printf("Please enter a position : ");  
    scanf("%d %d", &x, &y);  
    x--; 
    y--;  
    if ((x < 0) || (x >= 3) || (y < 0) || (y >= 3) || table[x][y] != ' ') {  
        printf("Try again.\n");  
        update(i, j);   
    } else {  
        table[x][y] = Player;  
        i = x; 
        j = y;  
    }  
}  
  void initial() {  
    for (int i = 0; i < 3; i++) {  
        for (int j = 0; j < 3; j++) {  
            table[i][j] = ' ';  
        }  
    }  
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
    initial();  
    print();  
    while (1) {  
        update(i, j);   
        if (Checkwin()) {  
            printf("The winner is Player %c\n", Player);  
            break;  
        }  
        Player = (Player == 'X') ? 'O' : 'X';  
        print(); 
    }  
}  
int main() {  
    game();  
    return 0;  
}