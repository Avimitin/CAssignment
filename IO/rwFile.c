#include <stdio.h>

char * readFile(FILE *fp, char *filepath) {
    fp = fopen(filepath, "r");
    static char buff[255];
    fgets(buff, 255, (FILE*)fp);
    printf("%s\n", buff);
    fclose(fp);
    return buff;
}

void writeFile(FILE *fp, char *filepath) {
    fp = fopen(filepath, "w");
    printf("Writing data...");
    fputs("\nWriting some data\n", fp);
    fclose(fp);
}

int main() {
    FILE *fp = NULL;
    char *filepath = "/home/avimitin/CAssignment/IO/test.txt";
    char *lines = readFile(fp, filepath);
    printf("%s", lines);
    printf("\n");
    writeFile(fp, filepath);
    return 0;
}