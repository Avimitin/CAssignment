#include <stdio.h>

void Show(int len, int *a);
void ShellSort(int length, int *array);

int main(int argc, char *argv[]) {
    // Check input;
    if (argc < 3) {
        printf("Sort need at least 2 numbers to sort but got only %d", argc-1);
        return 0;
    } 

    int a[argc-1];

    // Parse args to int array;
    for (int i = 0; i < argc-1; i++) {
        a[i] = *argv[i+1]-48;
    }

    // Print user's input;
    printf("Args you input: ");
    Show(argc-1, a);
    
    // Print input after sort;
    ShellSort(argc-1, a);
    printf("After sort: ");
    Show(argc-1, a);

    // Exit;
    return 0;
}