#include <stdio.h>
#include <stdlib.h>

int MAX_SIZE = 32;

char* encode_input(char *user_supplied_string){
    int i, dst_index;
    char* dst_buf = (char*)malloc((5 * sizeof(char) * MAX_SIZE) + 1);
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
        printf("Usage: %s <string to encode>\n", argv[0]);
        return 1;
    }

    char *input_string = argv[1];
    
    // Call the encode_input function
    char* encoded_string = encode_input(input_string);
    
    // Output the encoded string
    printf("Encoded String: %s\n", encoded_string);
    
    // Free the allocated memory
    free(encoded_string);
    
    return 0;
}