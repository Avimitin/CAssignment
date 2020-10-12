#include <stdio.h>

extern int i;
extern int j;
// extern 用来在另一个文件声明一个全局函数或者变量
// 在无法初始化该变量时在别的文件寻找这个变量或函数。
extern int x; 

int addtwonum() {
    x = 4;
    return i + j;
}