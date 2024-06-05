/* run this program using the console pauser or add your own getch, system("pause") or input loop 
#include<graphics.h>
using namespace std;
int main(){
   	initgraph(600,600); 
   	setcolor(WHITE);
   	setfillstyle(SOLID_FILL,WHITE);
   	fillellipse(300,300,100,100);
   	getch();
   	closegraph();
   	return 0;
}*/
#include <graphics.h>
#include <conio.h>
#include <time.h>
// 颜色与字符的下标有关
#define MAX_CHAR 16
#define DROP_NUM 50      // 雨点数
#define W  800
#define H  600

struct CharDrop
{
  int x;
  int y;
  wchar_t  ch;
  COLORREF color; // 颜色
};

CharDrop drops[DROP_NUM][MAX_CHAR];
wchar_t generate_random_chinese();
// 初始化字符
void InitDrop();
void InitDrop(int NUM);  // 带参数更新
// 更新字符串
void UpdataDrop();
// 输出字符串
void ShowDrop();
int main()
{
  initgraph(W, H);
  setbkmode(TRANSPARENT);
  clock_t seed;
  seed = clock();
  srand(seed);
  settextstyle(15,0,_T("隶书"));
  InitDrop();
  BeginBatchDraw();
  while (true)
  {
    ShowDrop();    // 显示雨线
    Sleep(100);
    UpdataDrop();  // 更新雨点
    FlushBatchDraw();
  }
  EndBatchDraw();
}
wchar_t generate_random_chinese()
{
  wchar_t base = L'一'; // 汉字编码起始值
  wchar_t offset = rand() % 20902; // 汉字编码总数
  return base + offset;
}
void InitDrop()
{
  for (int j = 0; j < DROP_NUM; j++)
  {
    // 生成一个X坐标
    int x = (rand() % (W - 1 + 1)) + 1;
    // 生成一个Y坐标
    int y = (rand() % (0 - (-800)+1)) -800;
    for (int i = 0; i < MAX_CHAR; i++)
    {
      drops[j][i].x = x;
      drops[j][i].y = y - i * 15;
      drops[j][i].ch = generate_random_chinese(); // Random number or character
      if (i == 0)
      {
        drops[j][i].color = WHITE;
      }
      else
      {
        double dx = MAX_CHAR;       // 颜色分级
        double redStep = (GetRValue(BLACK) - GetRValue(YELLOW)) / dx;
        double greenStep = (GetGValue(BLACK) - GetGValue(YELLOW)) / dx;
        double blueStep = (GetBValue(BLACK) - GetBValue(YELLOW)) / dx;
        drops[j][i].color = RGB(GetRValue(YELLOW) + i * redStep,
          GetGValue(YELLOW) + i * greenStep,
          GetBValue(YELLOW) + i * blueStep);
      }
    }
    drops[j][MAX_CHAR - 1].color = BLACK;
  }
}

void InitDrop(int j)  // 带参数更新
{
  // 生成一个X坐标
  int x = (rand() % (W - 1 + 1)) + 1;
  // 生成一个Y坐标
  int y = (rand() % (0 - (-800) + 1)) - 800;
  for (int i = 0; i < MAX_CHAR; i++)
  {
    drops[j][i].x = x;
    drops[j][i].y = y - i * 15;
    drops[j][i].ch = generate_random_chinese(); // Random number or character
    if (i == 0)
    {
      drops[j][i].color = WHITE;
    }
    else
    {
      double dx = MAX_CHAR;       // 颜色分级
      double redStep = (GetRValue(BLACK) - GetRValue(YELLOW)) / dx;
      double greenStep = (GetGValue(BLACK) - GetGValue(YELLOW)) / dx;
      double blueStep = (GetBValue(BLACK) - GetBValue(YELLOW)) / dx;

      drops[j][i].color = RGB(GetRValue(YELLOW) + i * redStep,
        GetGValue(YELLOW) + i * greenStep,
        GetBValue(YELLOW) + i * blueStep);
    }
  }
  drops[j][MAX_CHAR - 1].color = BLACK;
}

void ShowDrop()
{
  for (int j = 0; j < DROP_NUM; j++)
  {
    for (int i = 0; i < MAX_CHAR; i++)
    {
      settextcolor(drops[j][i].color);
      outtextxy(drops[j][i].x, drops[j][i].y, drops[j][i].ch);
    }
  }
}

void UpdataDrop()
{
  for (int j = 0; j < DROP_NUM; j++)
  {
    for (int i = MAX_CHAR - 1; i > 0; i--)
    {
      drops[j][i].x = drops[j][i].x;
      drops[j][i].y = drops[j][i].y + 15;
      drops[j][i].ch = drops[j][i - 1].ch;
    }
    drops[j][0].x = drops[j][0].x;
    drops[j][0].y = drops[j][0].y + 15;
    drops[j][0].ch = generate_random_chinese();
    drops[j][0].color = WHITE;
    if (drops[j][MAX_CHAR - 1].y > H)
    {
      InitDrop(j);
    }
  }
}
