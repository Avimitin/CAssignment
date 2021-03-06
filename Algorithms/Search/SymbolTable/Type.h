#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ValType
{
    int ValVal;
}ValType;

typedef struct KeyType
{
    char *KeyVal;
}KeyType;

// NodeStruct
typedef struct NodeType
{
    KeyType *Key;
    ValType *Val;
    struct NodeType *Next;
}NodeType;

struct NodeType * NewNodeType(char* key, int val, struct NodeType *next) {
    NodeType* n = (NodeType*)calloc(1, sizeof(NodeType));
    n->Key = (KeyType*)calloc(1, sizeof(KeyType));
    n->Val = (ValType*)calloc(1, sizeof(ValType));
    n->Key->KeyVal = strdup(key);
    n->Val->ValVal = val;
    n->Next = next;
    return n;
}

typedef struct ArrayHeader
{
    void *data;
    int len;
    int cap;
}Array;
