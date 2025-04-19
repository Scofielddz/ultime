#include <stdio.h>
#include <stdlib.h>

void read_files(int num_files, char **files) {
    FILE *fp;
    char *data = malloc(1024);

    for (int i = 0; i < num_files; i++) {
        fp = fopen(files[i], "r");
        if (fp == NULL) {
            printf("Error opening file %s\n", files[i]);
        }
        else {
            printf("File %s:\n", files[i]);
            while (fgets(data, 1024, fp) != NULL)
            {
                printf("%s", data);
            }
            fclose(fp);
        }
    }
    free(data);
    data = NULL;
}

int main(int argc, char** argv) {
    // Check if at least one file argument is provided
    if (argc < 2) {
        printf("Usage: %s <file1> [file2] ... [fileN]\n", argv[0]);
        return 1;
    }

    // Call read_files with the number of files and the file names
    read_files(argc - 1, &argv[1]);

    return 0;
}
