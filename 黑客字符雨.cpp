/*#include<graphics.h>
#include<time.h>
#include<Windows.h>

struct Meteor 
{
	int x;
	int y;
	int step;
	char ch[10];
}meteor[50];

struct Charmeteor
{
	int x=50;
	int y=100;
	char CH[30];
}charmeteor;

void initmeteor() 
{
	for (int i = 0; i < 52; i++) {
		meteor[i].x = rand() % 800;
		meteor[i].y = rand() % 600;
		meteor[i].step = rand() % 5 + 5;
		for (int j = 0; j < 10; j++) {
			meteor[i].ch[j] = ((char)(rand() % (126 - 33) + 33));
		}
	}
}

void daymeteor() 
{
	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 10; j++) {
			outtextxy(meteor[i].x, meteor[i].y-15*j, meteor[i].ch[j]);
			settextcolor(RGB(222, 255- 25.5 * j, 0));
		}
	}
}

void movemeteor()
{
	for (int i = 0; i < 52; i++) {
		meteor[i].y += meteor[i].step;
		if (meteor[i].y > 800) {
			meteor[i].step = rand() % 5 + 5;
			meteor[i].y=- 2;
		}
	}
}

void movebianh()
{
	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 10; j++) {
			meteor[i].ch[j]= ((char)(rand() % (126 - 33) + 33));
		}
	}

}

int main()
{
	
	initgraph(800, 600);
	initmeteor();
	BeginBatchDraw();
	while (1) {
		cleardevice();
		Sleep(50);
		daymeteor();
		movebianh();
		movemeteor();
		FlushBatchDraw();
	}
	
	system("pause");
	return 0;
}*/
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
#include <windows.h>  
  
#define MAX_METEORS 50  
#define WIDTH 80   
#define HEIGHT 20  
  
typedef struct {  
    int x;  
    int y;  
    int step;  
    char ch;   
} Meteor;  
  
void initMeteors(Meteor meteors[], int count) {  
    srand(time(NULL));  
    for (int i = 0; i < count; i++) {  
        meteors[i].x = rand() % WIDTH;  
        meteors[i].y = rand() % HEIGHT;  
        meteors[i].step = rand() % 3 + 2;   
        meteors[i].ch = '0' + rand() % 10;   
    }  
}  
  
void printMeteors(Meteor meteors[], int count) {  
    for (int i = 0; i < count; i++) {  
          
        if (meteors[i].y < HEIGHT) {  
            
            printf("\033[32m\033[%d;%dH%c\033[0m", meteors[i].y, meteors[i].x, meteors[i].ch);  
         
			}  
    }  
      
    fflush(stdout);  
}  
  
void moveMeteors(Meteor meteors[], int count) {  
    for (int i = 0; i < count; i++) {  
        meteors[i].y += meteors[i].step;  
        if (meteors[i].y >= HEIGHT) {  
            meteors[i].y = 0;  
            meteors[i].step = rand() % 3 + 2;   
            meteors[i].ch = '0' + rand() % 10;  
        }  
    }  
}  
  
int main() {  
    Meteor meteors[MAX_METEORS];  
    initMeteors(meteors, MAX_METEORS);  
  
    while (1) {  
        system("cls");  
        printMeteors(meteors, MAX_METEORS);  
        moveMeteors(meteors, MAX_METEORS);  
        Sleep(1000);   
    }  
  
     
    // return 0;  
}