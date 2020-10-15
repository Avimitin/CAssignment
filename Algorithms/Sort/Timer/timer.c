#include <time.h>
#include <stdio.h>

clock_t current;
extern void Start();
extern double During();

void Start() {
    current = clock();
}

double During() {
    clock_t now = clock();
    return (double)(now - current) / CLOCKS_PER_SEC;
}

