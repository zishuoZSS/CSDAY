#include <stdio.h>  
  
int main() {  
    int sum = 0;    // 初始化总和为0  
    int sign = 1;   // 初始化符号为正（1表示正，-1表示负）  
    int i = 1;      // 从1开始循环  
  
    for (; i <= 101; i += 2) {  // 循环遍历1到101的所有奇数  
        sum += sign * i;         // 将当前符号与当前奇数相乘，然后加到总和上  
        sign *= -1;             // 切换符号（正变负，负变正）  
    }  
  
    printf("The sum is: %d\n", sum);  // 输出结果  
    return 0;  
}