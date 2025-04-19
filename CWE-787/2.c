#include <stdio.h>
#include <stdlib.h>

int MAX_SIZE = 32;

char* encode_input(char *user_supplied_string){
    int i, dst_index;
    char* dst_buf = (char*)malloc((4 * sizeof(char) * MAX_SIZE) + 1);
    if ( MAX_SIZE <= strlen(user_supplied_string) ){
        exit(1);
    }

    dst_index = 0;
    for ( i = 0; i < strlen(user_supplied_string); i++ ){
        if('&' == user_supplied_string[i] ){
            dst_buf[dst_index++] = '&';
            dst_buf[dst_index++] = 'a';
            dst_buf[dst_index++] = 'm';
            dst_buf[dst_index++] = 'p';
            dst_buf[dst_index++] = ';';
        }
        else if ('<' == user_supplied_string[i] ){
            dst_buf[dst_index++] = '&';
            dst_buf[dst_index++] = 'l';
            dst_buf[dst_index++] = 't';
            dst_buf[dst_index++] = ';';
        }
        else if ('>' == user_supplied_string[i] ){
            dst_buf[dst_index++] = '&';
            dst_buf[dst_index++] = 'g';
            dst_buf[dst_index++] = 't';
            dst_buf[dst_index++] = ';';
        }
        else dst_buf[dst_index++] = user_supplied_string[i];
    }
    dst_buf[dst_index] = '\0';
    
    return dst_buf;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <string_to_encode>\n", argv[0]);
        return 1;
    }

    // Get the user-supplied string
    char *user_input = argv[1];

    // Encode the string
    char *encoded_string = encode_input(user_input);

    // Print the encoded string
    printf("Encoded String: %s\n", encoded_string);

    // Free the allocated memory
    free(encoded_string);

    return 0;
}