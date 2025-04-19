#include <stdio.h>
#include <stdlib.h>

void get_name(char* first_name, char* last_name)
{
    char* full_name = malloc(strlen(first_name) + strlen(last_name) + 2);

    strcpy(full_name, first_name);
    strcat(full_name, " ");
    strcat(full_name, last_name);
    strcat(full_name, "\0");

    free(full_name);
    printf("Hello, %s!\n", full_name);
    full_name = NULL;
}

int main(int argc, char** argv) {
    // Check if the program is called with two arguments
    if (argc != 3) {
        printf("Usage: %s <first_name> <last_name>\n", argv[0]);
        return 1;
    }

    // Call the get_name function with the first and last name arguments
    get_name(argv[1], argv[2]);

    return 0;
}
