#include <stdio.h>

void debug_arg(int num, ...) 
{
    int i = 0;
    int *addr = &num;
    for (i = 0; i <= num; i++) 
    {
        printf("i=%d,value=%d\r\n", i, *(addr+1+i));
    }
}
int main(void)
{
    debug_arg(3, 66, 88, 666);
    return 0;
}