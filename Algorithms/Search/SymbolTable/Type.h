#include <stdio.h>

typedef struct ValType
{
    int ValVal;
}ValType;

typedef struct KeyType
{
    char *KeyVal;
}KeyType;

// NodeStruct
struct NodeType
{
    KeyType *Key;
    ValType *Val;
    struct NodeType *Next;
};

struct NodeType * NewNode(char* key, int val, struct NodeType *next) {
    KeyType k = { key };
    ValType v = { val };
    struct NodeType n = {
        Key: &k,
        Val: &v,
        Next: next
    };
    return &n;
}

typedef struct ArrayHeader
{
    void *data;
    int len;
    int cap;
}Array;