/*#include <stdio.h>
#include <string.h>
#include <windows.h>
 
int main()
{
    char str[100] = "HELLO WORLD! GOOD BYE!";
    int i,j;
	while(1)
	{
		for(i=0;i<strlen(str);i++)
		{
			system("cls");
			for(j=i;j<strlen(str);j++)
			{
				printf("%c",str[j]);
			}
			Sleep(100);
			printf("\n");
		}
	}
    return 0;
}*/
#include <stdio.h>  
#include <string.h>  
#include <windows.h>  
  
#define WIDTH 20 
#define HEIGHT 5 
  
int main()  
{  
    char str[WIDTH * HEIGHT + 1][] = "HELLO WORLD!\nGOODBYE WORLD!";  
    char pattern[HEIGHT][WIDTH + 1];   
    int i, j, k, colOffset;  
  
    k = 0;  
    for (i = 0; i < HEIGHT && k < strlen(str); i++) {  
        for (j = 0; j < WIDTH && k < strlen(str) && str[k] != '\n'; j++, k++) {  
            pattern[i][j] = str[k];  
        }  
        pattern[i][j] = '\0';  
        if (str[k] == '\n') {  
            k++;  
        }  
    }  
  
    while (1) {  
        for (colOffset = 0; colOffset < WIDTH; colOffset++) {  
            system("cls");   
  
          
            for (i = 0; i < HEIGHT; i++) {  
                for (j = colOffset; j < WIDTH && pattern[i][j - colOffset] != '\0'; j++) {  
                    printf("%c", pattern[i][j - colOffset]);  
                }  
                printf("\n");  
            }  
  
            Sleep(100);   
        }  
    }  
  
    return 0;  
}