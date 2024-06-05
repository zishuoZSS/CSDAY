#include<stdio.h>
#include<unistd.h>
void printS()
{
	printf("* * * *\n");
	printf("*\n");
	printf("*\n");
	printf("*\n");
	printf("******\n");
	printf("*\n");
	printf("*\n");
	printf("*\n");
	printf("******\n");
}
int main()
{

	int col=0;

	printf("\033[H\033[J");

	while(1){

	for(int i=0;i<col;i++)

	{
		printf("\033[C");
	}
	printS();

	col++;

	usleep(400000);

	printf("\033[K\033[2J");

}
/*printf("\033[H\033[J");
while(1){

int x,y;

printf("Please enter a x:");

scanf("%d",&x);

printf("Please enter a y:");

scanf("%d",&y);

for(int i=0;i<x;i++)

{

	printf("\033[B");

	for(int j=0;j<y;j++)

	{

		printf("\033[C");

	}

}

		printS();
	    getchar();
	

	//	printf("\033[H\033[J");
}*/
return 0;
}