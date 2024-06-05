#include<stdio.h>
void hannuota(int n,char from,char temp,char goal)
{
if(n==1){
printf("Move 1 from %c to %c\n",from,goal);
		return;
		}
	hannuota(n-1,from,goal,temp);
	printf("Move %c to %c\n",n,from,goal);
	hannuota(n-1,temp,goal,from);
	}
	int main(){
	int n;
	printf("Enter a number :");
	scanf("%d",&n);
	hannuota(n,'A','B','C');
	return 0;
	}	
