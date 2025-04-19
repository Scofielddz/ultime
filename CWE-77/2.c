#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_file(char* file_path) {
    char *cmd;
    int cmd_len;
    char *cat = "cat ";

    cmd_len = strlen(cat) + strlen(file_path) + 1;
    cmd = malloc(cmd_len);
    
    strncpy(cmd, cat, strlen(cat));
    strncat(cmd, file_path, (cmd_len - strlen(cat)));

    system(cmd);
    free(cmd);
    cmd = NULL;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    print_file(argv[1]);

    return 0;
}
