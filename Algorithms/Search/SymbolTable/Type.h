#include <stdio.h>

struct ValType
{
    int ValVal;
};

struct KeyType
{
    char *KeyVal;
};

// NodeStruct
struct NodeType
{
    struct KeyType *Key;
    struct ValType *Val;
    struct NodeType *Next;
};

struct NodeType * NewNode(char* key, int val, NodeType *next) {
    struct KeyType k = { key };
    struct ValType v = { val };
    struct NodeType n = {
        Key: &k,
        Val: &v,
        Next: next
    };
    return &n;
}