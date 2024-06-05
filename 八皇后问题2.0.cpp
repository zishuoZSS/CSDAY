/*Through recursion and backtracking, 
all the solutions of the eight queens problem are found, 
and the state of each solution is printed, 
and finally the total number of solutions is output.*/
#include<stdio.h>
int place[8]={0};
int flag[8]={1,1,1,1,1,1,1,1};
int d1[15]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int d2[15]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int count=0;
void print()
{
	int i,j;
    count++;
	printf("No.%2d\n",count);
	int table[8][8]={0};
	for (i=0;i<8;i++)
	{
		table[i][place[i]]=1;
	}
	for (i=0;i<8;i++)
	{
		for (j=0;j<8;j++)
		{
	printf("%d",table[i][j]);
		}printf("\n");
	}
}
int queen(int n)
{
	int col;
	for (col=0;col<8;col++)
	{
		if (flag[col]&&d1[n-col+7]&&d2[n+col])
		{
			place[n]=col;
			flag[col]=0;
			d1[n-col+7]=0;
            d2[n+col]=0;
			if(n<7)	{queen(n+1);}
            else{print();}
            flag[col]=1;
			d1[n-col+7]=1;
			d2[n+col]=1;
		}
	}
	return count;
}
int main()
{
count=queen(0);
printf("%d",count);
	return 0;}