#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void resolve_path(char* path)
{
    char* p = path;
    while (*p != '\0') {
        if (*p == ' ') {
            *p = '-';
        }
        p++;
    }
}

void print_file(char* file_name)
{
    char* dir = getenv("dir");
    if (dir == NULL) {
        printf("Error: dir environment variable not set\n");
        return;
    }

    int path_len = strlen(dir) + strlen(file_name) + 1;
    char* path = malloc(path_len);
    if (path == NULL) {
        printf("Error allocating memory\n");
        return;
    }
    strcpy(path, dir);
    strcat(path, file_name);
    
    resolve_path(path);

    FILE* f = fopen(path, "r");
    if (f == NULL) {
        printf("Error opening file\n");
        free(path);
        path = NULL;
        return;
    }
    else {
        char line[256];
        while (fgets(line, sizeof(line), f)) {
            printf("%s\n", line);
        }
    }
    fclose(f);
    free(path);
    path = NULL;
}
int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    print_file(argv[1]);

    return 0;
}
