#include <stdio.h>
#include <stdlib.h>

void print_files(char* file_path)
{
    char* dir = getenv("DIR");
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

    // Call the print_files function with the provided file path
    print_files(argv[1]);

    return 0;
}
