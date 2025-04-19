#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LEN 64

char* validate_hostname(char *hostname, int len){
    if (hostname == NULL){
        return NULL;
    }
    char* valid_hostname = malloc(len + 1);
    for (int i = 0; i < len; i++){
        if (hostname[i] == '-' || hostname[i] == '.'){
            valid_hostname[i] = ' ';
        }
        else {
            valid_hostname[i] = hostname[i];
        }
    }
    return valid_hostname;
}

char* get_hostname(char *user_supplied_name, int len){
    if (len > MAX_NAME_LEN){
        return NULL;
    }
    char* hostname = malloc(MAX_NAME_LEN);

    char* valid_hostname = validate_hostname(user_supplied_name, len);
    if (valid_hostname == NULL){
        return NULL;
    }
    strcpy(hostname, valid_hostname);
    free(valid_hostname);
    valid_hostname = NULL;
    
    return hostname;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    // Get the hostname from user input
    char *user_supplied_name = argv[1];
    int len = strlen(user_supplied_name);

    // Get the valid hostname
    char* valid_hostname = get_hostname(user_supplied_name, len);
    
    if (valid_hostname != NULL) {
        printf("Valid hostname: %s\n", valid_hostname);
        free(valid_hostname); // Free the allocated memory for the hostname
    } else {
        printf("Invalid hostname or memory allocation error.\n");
    }

    return 0;
}