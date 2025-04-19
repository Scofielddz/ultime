#include <stdio.h>
#include <stdlib.h>

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
    char* hostname = malloc(64);
    if (len > 64){
        return NULL;
    }

    char* valid_hostname = validate_hostname(user_supplied_name, len);
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

    // Get the user-supplied hostname
    char* user_supplied_name = argv[1];
    int len = strlen(user_supplied_name);

    // Get the validated hostname
    char* hostname = get_hostname(user_supplied_name, len);
    
    if (hostname == NULL) {
        printf("Error: Hostname is too long or invalid.\n");
        return 1;
    }

    printf("Validated hostname: %s\n", hostname);

    // Free allocated memory
    free(hostname);
    hostname = NULL;

    return 0;
}
