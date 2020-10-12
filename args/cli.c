#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Expected 1 argument but got %d.\n", argc -1);
    } else {
        printf("arg: %s\n", argv[1]);
    }
    return 0;
}