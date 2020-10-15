#include <stdio.h>
#include <time.h>

clock_t current;

void Start() {
    extern clock_t current;
    current = clock(); 
}

long during() {
    if (current == 0) {
        fprintf(stderr, "You should start the clock first\n");
        return -1;
    }

    return (clock() - current) * 1000 / CLOCKS_PER_SEC;
}

int main() {
    printf("現在是： %d\n", current);
    Start();
    printf("現在是： %d\n", current*1000/CLOCKS_PER_SEC);
    int i = 0;
    while (i < 100000000) {
        i += 1;
    }
    printf("Duration: %fs\n", during()%1000);
    return 0;
}