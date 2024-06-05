#include <stdio.h>
void putE(char j) {
    printf("\033[31m******\n");
    printf("  *\n");
    printf("  *\n");
    printf("******\n");
    printf("  *\n");
    printf("  *\n");
    printf("******\n\033[0m");
}

void putF(char j) {
    printf("\033[32m******\n");
    printf("  *\n");
    printf("  *\n");
    printf("******\n");
    printf("  *\n");
    printf("  *\n");
    printf("  *\n\033[0m");
}

void putH(char j) {
    printf("\033[33m* *\n");
    printf("* *\n");
    printf("******\n");
    printf("* *\n");
    printf("* *\n\033[0m");
}

// 创建一个函数指针数组
typedef void (*PatternFunc)(char);
PatternFunc patternFuncs[] = {putE, putF, putH};

int main() {
    char input[5]; 
    int numChars = 0;
    printf("Please enter up to 4 characters (E, F, or H): ");
    // diaoyongtuanhanshu
    for (int i = 0; i < numChars; i++) {
     char c; // zhuanhuanweidaxiezimu
        if (c == 'E') {
            patternFuncs[0](c);
        } else if (c == 'F') {
            patternFuncs[1](c);
        } else if (c == 'H') {
            patternFuncs[2](c);
        } else {
            printf("Unsupported character: %c\n", input[i]);
        }
    }

    return 0;
}