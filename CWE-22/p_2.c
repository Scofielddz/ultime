#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void file_operation(char* flag, char* file_name, char* data)
{
    char* dir = '/home/users/user1/';

    char* path = malloc(strlen(dir) + strlen(file_name) + 1);
    if (path == NULL)
    {
        printf("Error allocating memory\n");
        return;
    }
    strcpy(path, dir);
    strcat(path, file_name);

    char* resolved_path = realpath(path, NULL);
    if (resolved_path == NULL)
    {
        printf("Invalid path\n");
        return;
    }

    if (strncmp(resolved_path, dir, strlen(dir)) != 0) {
        printf("Access to the path is denied\n");
        free(path);
        return;
    }
    
    FILE* f = fopen(resolved_path, flag);
    if (f == NULL) {
        printf("Error opening file: %s\n", path);
        free(path);
        path = NULL;
        return;
    }
    if (*flag == 'w')
    {
        fprintf(f, "%s\n", data);
    }
    else if (*flag == 'r')
    {
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
    if (argc < 3) {
        printf("Usage: %s <r|w> <filename> [data if write]\n", argv[0]);
        return 1;
    }

    char* flag = argv[1];
    char* file_name = argv[2];
    char* data = NULL;

    if (strcmp(flag, "w") == 0) {
        if (argc < 4) {
            printf("Error: data must be provided for write operation\n");
            return 1;
        }
        data = argv[3];
    } else if (strcmp(flag, "r") != 0) {
        printf("Invalid operation. Use 'r' to read or 'w' to write.\n");
        return 1;
    }

    file_operation(flag, file_name, data);

    return 0;
}
