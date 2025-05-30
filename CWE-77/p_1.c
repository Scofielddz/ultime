#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_MAX 128

void list_directory(char* dir) {
    for (int i = 0; i < strlen(dir) - 1; i++) {
        if (dir[i] == ';' || dir[i] == '|' || dir[i] == '&' || dir[i] == '$') {
            printf("Error: invalid path\n");
            return;
        }
    }
    char cmd[CMD_MAX] = "ls ";
    if (strlen(dir) > CMD_MAX - 3) {
        printf("Error: File name too long\n");
        return;
    }
    strcat(cmd, dir);
    system(cmd);
    return 0;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }
    
    list_directory(argv[1]);
    
    return 0;
}