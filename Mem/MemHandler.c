#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *name = malloc(200 * sizeof(char));
    if (name == NULL) {
        fprintf(stderr, "unable to malloc new memory.");
    } else {
        strcpy(name, "abc");
    }
    printf("%s", name);
    free(name);
    return 0;
}