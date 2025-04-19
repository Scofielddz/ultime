#include <stdio.h>
#include <stdlib.h>

char** initialize_data(int num_char, char* init_chars)
{
    int len_init = strlen(init_chars);
    char** data = (char**)malloc(sizeof(char*) * num_char);
    for (int i = 0; i < num_char; i++)
    {
        data[i] = (char*)malloc(sizeof(char) * len_init);
    }
    for (int i = 0; i < num_char; i++)
    {
        data[i] = init_chars;
    }
    return data;
}

int main(int argc, char** argv) {
    int num_char = 5;
    char* init_chars = "hello";
    char** data = initialize_data(num_char, init_chars);

    if (data != NULL) {
        // Print the initialized data
        for (int i = 0; i < num_char; i++) {
            printf("data[%d]: %s\n", i, data[i]);
            free(data[i]);  // Free memory for each string
        }
        free(data);  // Free the array of pointers
    }

    return 0;
}
