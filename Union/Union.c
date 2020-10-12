#include <stdio.h>
#include <string.h>

union Data
{
    /* data */
    int i;
    char b[10];
    float c;
};

int main() {
    union Data data;
    data.i = 13;
    printf("data.i = %d\n", data.i);
    union Data *d = &data;
    strcpy(data.b, "fUcKyOu");
    printf("data.b = %s\n", data.b);
    d -> c = 1.14;
    printf("data.c= %f\n", data.c);
    return 0;
}
