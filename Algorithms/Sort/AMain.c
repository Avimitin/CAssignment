#include <stdio.h>
#include <stdlib.h>

void Show(int len, int *a);
void QuickSort(int length, int *array);

int main(int argc, char *argv[]) {
    // Check input;
    if (argc < 3) {
        printf("Sort need at least 2 numbers to sort but got only %d", argc-1);
        return 0;
    } 

    int a[argc-1];

    // Parse args to int array;
    for (int i = 0; i < argc-1; i++) {
        a[i] = atoi(argv[i+1]);
    }

    // Print user's input;
    printf("Do you want to print the args? [Y/n]");
    char NeedPrint;
    scanf("%c", &NeedPrint);
    if (NeedPrint == 'Y' || NeedPrint == 'y') {
        printf("Args you input: ");
        Show(argc-1, a);
    } 
    else if (NeedPrint == 'n' || NeedPrint == 'N') { } 
    else {
        printf("Invalid input!\n");
        exit(-1);
    }
    
    // Print input after sort;
    QuickSort(argc-1, a);
    printf("After sort: ");
    Show(argc-1, a);

    // Exit;
    return 0;
}