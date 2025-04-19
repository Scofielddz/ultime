#include <stdio.h>
#include <stdlib.h>

void print_files(char* file_path)
{
    if (file_path == NULL) {
        printf("Error: Invalid Path\n");
        return;
    }
    char* dir = getenv("DIR");
    if (dir == NULL) {
        printf("Error: DIR environment variable not set\n");
        return;
    }

    int file_path_len = strlen(dir) + strlen(file_path) + 1;
    char* full_path = malloc(file_path_len);
    strcpy(full_path, dir);
    strcat(full_path, file_path);
    strcat(full_path, "\0");

    char* resolved_path = realpath(full_path, NULL);
    if (resolved_path == NULL) {
        printf("Error: Invalid Path\n");
        return;
    }

    FILE* file = fopen(resolved_path, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", resolved_path);
        return;
    }

    char line[256];
    while(fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
    free(full_path);
    full_path = NULL;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    char* file_path = argv[1];
    print_files(file_path);

    return 0;
}
