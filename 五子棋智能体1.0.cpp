#include<stdio.h>    
#include<stdlib.h>  
#include<time.h>
char table[9][9] = {    
    {' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' '}, 
	{' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' '},
	{' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' '},
	{' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' '},
	{' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' '},
	{' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' '},
	{' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' '},
	{' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' '},
	{' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' '},    };    
  
char Player = 'a';    
  
int Checkwin() {
    for (int i = 0; i < 9 - 4; i++) {
        for (int j = 0; j < 9; j++) {
            if (table[i][j] == Player && 
                table[i + 1][j] == Player &&
                table[i + 2][j] == Player &&
                table[i + 3][j] == Player &&
                table[i + 4][j] == Player) {
                return 1;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - 4; j++) {
            if (table[i][j] == Player && 
                table[i][j + 1] == Player &&
                table[i][j + 2] == Player &&
                table[i][j + 3] == Player &&
                table[i][j + 4] == Player) {
                return 1;
            }
        }
    }
    for (int i = 0; i < 9 - 4; i++) {
        for (int j = 0; j < 9 - 4; j++) {
            if (table[i][j] == Player && 
                table[i + 1][j + 1] == Player &&
                table[i + 2][j + 2] == Player &&
                table[i + 3][j + 3] == Player &&
                table[i + 4][j + 4] == Player) {
                return 1;
            }
        }
    }
    for (int i = 0; i < 9 - 4; i++) {
        for (int j = 4; j < 9; j++) {
            if (table[i][j] == Player && 
                table[i + 1][j - 1] == Player &&
                table[i + 2][j - 2] == Player &&
                table[i + 3][j - 3] == Player &&
                table[i + 4][j - 4] == Player) {
                return 1;
            }
        }
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
        if ((x < 0) || (x >= 9) || (y < 0) || (y >= 9) || table[x][y] != ' ') {    
            printf(" Try again.\n");    
        } else {   
            table[x][y] = Player;    
            *i = x;   
            *j = y;    
            break;  
        }  
    } while (1);  
}  
  
void print() {    
    for (int i = 0; i < 9; i++) {    
        for (int j = 0; j < 9; j++) {    
            printf("%c | ", table[i][j]);    
        }    
        printf("\n");    
        for (int k = 0; k < 9; k++) {    
            printf("----");    
        }    
        printf("\n");    
    }    
}    
  void machine() {
    srand(time(NULL)); 
    int x, y;
    do {
        x = rand() % 3; 
        y = rand() % 3; 
    } while (table[x][y] != ' ');

    table[x][y] = (Player == 'a') ? 'b' : 'a';
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
        machine();
		//Player = (Player == 'a') ? 'b' : 'a';    
    }    
}    
int main() {    
    game();    
    return 0;    
}