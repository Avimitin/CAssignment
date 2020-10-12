#include <stdio.h>

#define VALUE1 123
#define VALUE2 "abc"

int main() {
    const int VALUE3 = 123;
    const char VALUE4[5] = "Hello";
    printf("VALUE1: %d, VALUE2: %s, VALUE3: %d, VALUE4: %s", VALUE1, VALUE2, VALUE3, VALUE4);
    return 0;
}