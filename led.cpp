#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 

#define FRAME_COUNT 10
#define HEIGHT 10
#define WIDTH 10
#define PATTERN_SIZE 3

char patterns[PATTERN_SIZE][HEIGHT][WIDTH+1] = {
    {"    o    ", "   ooo   ", "  ooooo  ", " ooooooo ", "ooooooooo", " ooooooo ", "  ooooo  ", "   ooo   ", "    o    ", "         "},
    {" o o o o ", "  o o o  ", "o o o o o", " o o o o ", "  o o o  ", "o o o o o", " o o o o ", "  o o o  ", " o o o o ", "         "},
    {" o       ", "  o     o", "   o   o ", "    o o  ", "     o   ", "    o o  ", "   o   o ", "  o     o", " o       ", "         "}
};

void ini_pattern(char pattern[HEIGHT][WIDTH+1], const char (*src_pattern)[WIDTH+1]) {
    for(int j = 0; j < HEIGHT; j++) {
        memcpy(pattern[j], src_pattern[j], WIDTH + 1);
    }
}

void update(char pattern[HEIGHT][WIDTH+1], int dx, int dy) {
    for(int y = HEIGHT - 1; y >= 0; y--) {
        for(int x = WIDTH - 1; x >= 0; x--) {
            if(pattern[y][x] != ' ') {
                int new_x = (x + dx + WIDTH) % WIDTH;
                int new_y = (y + dy + HEIGHT) % HEIGHT;
                pattern[y][x] = ' ';
                pattern[new_y][new_x] = patterns[0][y][x];
            }
        }
    }
}

void write_file(const char* filename, char pattern[HEIGHT][WIDTH+1]) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    for(int y = 0; y < HEIGHT; y++) {
        fwrite(pattern[y], sizeof(char), WIDTH + 1, file);
    }
    fclose(file);
}

void read_file(const char* filename, char pattern[HEIGHT][WIDTH+1]) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    for(int y = 0; y < HEIGHT; y++) {
        if(fgets(pattern[y], WIDTH + 2, file) == NULL) break;
        pattern[y][WIDTH] = '\0';
    }
    fclose(file);
}

void replay_frames(const char* filename_pre, int start_frame, int end_frame) {
    for (int i = start_frame; i <= end_frame; i++) {
        char filename[20];
        snprintf(filename, sizeof(filename), "%s%d.txt", filename_pre, i);
        char temp_pattern[HEIGHT][WIDTH + 1];
        read_file(filename, temp_pattern);
        for (int y = 0; y < HEIGHT; y++) {
            printf("%s", temp_pattern[y]);
        }
        Sleep(500); 
        system("cls"); 
    }
}

int main() {
    char pattern[HEIGHT][WIDTH+1];
    ini_pattern(pattern, patterns[0]);
    write_file("frame0.txt", pattern);

    int dx = 1, dy = 0;
    for (int i = 1; i < FRAME_COUNT; i++) {
        update(pattern, dx, dy);
        char filename[20];
        snprintf(filename, sizeof(filename), "frame%d.txt", i);
        write_file(filename, pattern);

        system("cls");
        for(int y = 0; y < HEIGHT; y++) {
            printf("%s", pattern[y]);
        }
        Sleep(500); 
    }

    replay_frames("frame", 0, FRAME_COUNT - 1);

    return 0;
}