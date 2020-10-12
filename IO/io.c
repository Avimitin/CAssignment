#include <stdio.h>

int main() {
    char i[100];
    int j;

    printf("输入一个数字和一个字符。");
    scanf("%d %s", &j, i);

    printf("\n你输入了数字：%d和字符%s\n", j, i);
    return 0;
}