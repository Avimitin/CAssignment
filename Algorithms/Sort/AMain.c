#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sort method
void QuickSort(int length, int *array);
void InsertionSort(int length, int *array);
void MergeSortBU(int length, int *array);
void MergeSort(int length, int *a);
void SeclectionSort(int length, int *array);
void ShellSort(int length, int *array);

// API
void Show(int len, int *a);
void Start();
double During();
char *SortMethod;

int SameStr(char *a, char *b) {
    if (strcmp(a, b) == 0) {
        return 1;
    }
    return 0;
}

void MainSort(int length, int *array) {
    if (SameStr(SortMethod, "insert")) {
        InsertionSort(length, array);
    }
    if (SameStr(SortMethod, "mergebu")) {
        MergeSortBU(length, array);
    }
    if (SameStr(SortMethod, "mergeud")) {
        MergeSort(length, array);
    }
    if (SameStr(SortMethod, "quick")) {
        QuickSort(length, array);
    }
    if (SameStr(SortMethod, "selection")) {
        SeclectionSort(length, array);
    }
    if (SameStr(SortMethod, "shell")) {
        ShellSort(length, array);
    }
}

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

    // Select one method to sort;
    char *existMethod[] = {"insert", "mergebu", "mergeud", "quick", "selection", "shell"};
    printf("Select a sort method: insert/mergebu/mergeud/quick/selection/shell :");
    SortMethod = calloc(10, sizeof(char));
    scanf("%s", SortMethod);
    int isValid = 0;
    for (int i = 0; i < 6; i++) {
        if (SameStr(SortMethod, existMethod[i])) {
            isValid = 1;
            break;
        }
    }

    if (!isValid) {
        printf("Invalid input!\n");
        exit(-1);
    }
    
    // sort and count time
    Start();
    MainSort(argc-1, a);
    double end = During();
    
    // Print sorted input or not?
    printf("Sort Done. Do you want to print the sorted input? [Y/n]");
    char NeedPrint;
    while (NeedPrint == '\n' || NeedPrint == '\0') {
        NeedPrint = getchar();
    }
    if (NeedPrint == 'Y' || NeedPrint == 'y') {
        printf("Args you input: ");
        Show(argc-1, a);
    } 
    else if (NeedPrint == 'n' || NeedPrint == 'N') { } 
    else {
        printf("Invalid input!\n");
        exit(-1);
    }

    // print sorting time.
    printf("Exact sorting time: %f s\n", end);

    // Exit;
    return 0;
}