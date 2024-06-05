#include<stdio.h>
//defineinitial is 0.
char table[3][3]={{' ', ' ', ' '},  
   	              {' ', ' ', ' '},  
                  {' ', ' ', ' '}};
//define fuction to win
char Player='X';
int Checkwin(){
	for (int i = 0; i < 3; i++) {  
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

 //each play
 void game()
 {int i,j;
 printf("Three,Two,One,Go!\n");
 initial(i,j);
 print(i,j);
 while(1)
 update(i,j);
 if(Checkwin())
 {
 printf("The winner is Player\n");
 break;
 }
 	return;
 	Player = (Player == 'X') ? 'O' : 'X'; 
 }
 void update(int i,int j){
 	int sign=1;
 	int i=0;
 	int j=0;
 	int x,y;
 	while(sign==1)
 	printf("Please print a address:")
 	scanf("%d%d",&x,&y);
 	if((i>=3)||(j>=3)||table[i-1][j-1]!=' ')
 	printf("again");
 	else if(table[i-1][j-1]==' ')
 	table[i-1][j-1]=Player;
 	sign = 0;
 }
 void initial(int i,j)
 {
 	int i =0;
	 for(i=0;i<3;i++)
	 {
	 	int j=0;
	 	for(j=0;j<3;j++)
		 {
		 	table[i][j]=' ';
		 }
	 }	
 	
 
 void print(int i,j)
 {
 	int i =0;
	 for(i=0;i<3;i++)
	 {
	 	int j=0;
	 	for(j=0;j<3;j++)
		 {
		 	printf("%c|%c|%c|\n",table[i][j]);
		 }
	 }	
 	
 } 
int main()
{
game();
return 0;
}


