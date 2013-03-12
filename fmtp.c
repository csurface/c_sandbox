
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_KEY_LENGTH 100

char* getValue(char* subject, char* key, char* value) {

    char* temp;
    char token[MAX_KEY_LENGTH];
    int len;

    sprintf(token, "%s=", key);

    len = strlen(key);
    if (len > MAX_KEY_LENGTH) {
        printf("Key length %d exceeds max %d\n", len, MAX_KEY_LENGTH);
        return NULL;
    }

    temp = strstr(subject, token);
    if (temp) {
        temp = temp + strlen(token);
        if (temp) {
            size_t span = strcspn(temp, "; \t\r\n");
            strncpy(value, (const char*)temp, span);
        }
    }


    return value;
}

int main(int argc, char* argv[]) {

    char* subject;
    char* key;
    char* value;

    if (argc < 3) {
        printf("Missing argument(s)\n");
        printf("fmtp <fmt string> <key>\n");
        return -1;
    }

    subject = argv[1];
    key = argv[2];
    printf("Searching \"%s\" for \"%s\"\n", subject, key);

    value = (char*)calloc(100, sizeof(char));
    getValue(subject, key, value);

    printf("%s = %s\n", key, value);

    free(value);

    return 0;
}

