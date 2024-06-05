/*xuanzepaixu*/
#include<stdio.h>   
int main()  
{  
    int i, j;  
    int a[10];  
    int tem;  
    printf("please print a number:\n");  
    for(i = 0; i < 10; i++)  
    {  
        printf("a[%d]=", i);  
        scanf("%d", &a[i]);  
    }  
    for(i = 0; i < 10; i++)  
    {  
        int min = i;  
        for(j = i + 1; j < 10; j++)  
        {  
            if(a[j] < a[min])  
            {  
                min = j;  
            }  
        }  
        if(min != i)  
        {  
            tem = a[i];  
            a[i] = a[min];  
            a[min] = tem;  
        }  
    }  
    printf("the result is :\n");  
    for(i = 0; i < 10; i++)  
    {  
        printf("%d\t", a[i]);  
    }  
    printf("\n");  
    return 0;  
}