/*maopaopaixu*/
#include<stdio.h>
int main()
{
	int i,j;
	int a[10];
	int tem;
	printf("please print a number:\n");
	for(i=0;i<10;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
	for(i=1;i<10;i++)
	{
		for(j=9;j>=i;j--)
		{
			if(a[j]<a[j-1])
			{
				tem   =a[j-1];
				a[j-1]=a[j];
				a[j]  =tem;
			}
		}
	}
		printf("the result is :\n");
		for(i=0;i<10;i++)
		{
			printf("%d\t",a[i]);
		}
	
	printf("\n");
	return 0;
	
}