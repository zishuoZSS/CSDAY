#include<stdio.h>
int main(){
	int i,j;
	int January[5][7]={(0,1,2,3,4,5,6),(7,8,9,10,11,12,13),(14,15,16,17,18,19,20),(21,22,2,24,25,26,27),(28,29,30,31)};
    for(i=0;i<5;i++)
	{
		for(j=0;j<7;j++)
	{
	printf("%d\t",January[i][j]);
 	}
 	printf("\n");
 	}
	
	return 0;
}