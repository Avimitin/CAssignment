#include <stdio.h>

struct config{
    int token;
    char username[50]; 
};

struct config a = {
    1234, 
    "avimitin"
};

int main() {
    printf("config's token:%d,config's username:%s\n", a.token, a.username);
    struct config *p = &a;
    p->token = 456789;
    printf("config's token:%d,config's username:%s\n", p->token, p->username);
    return 0;
}
