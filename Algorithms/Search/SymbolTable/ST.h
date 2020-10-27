#include "Type.h"
#include <string.h>
#include <stdlib.h>

NodeType *first;
int size;

// Put will put a new node if this is the new key for the whole
// node list. Else update value.
void Put(char *key, int val) {
    for (NodeType *n = first; n != NULL; n = n->Next) {
        if (strcmp(key, n->Key->KeyVal)) {
            n -> Val -> ValVal = val;
            return;
        }
        // Here will add all the new node to the front.
        first = NewNode(key, val, n);
        size++;
    }
}

// Get will return related value with given key. If the given key is not 
// exist, this will return null value.
int Get(char *key) {
    for (NodeType *n = first; n != NULL; n = n->Next) {
        if (strcmp(key, n->Key->KeyVal)) {
            return n -> Val -> ValVal;
        }
    }
    return NULL;
}

// Size will return how many key and value combination in list.
int Size() {
    return size;
}

// Delete will search the whole link list and delete the key and it's value.
// If key isn't exist this will return a NULL value.
ValType * Delete(char *key) {
    for (NodeType *current = first, *tmp = NULL; current != NULL; tmp = current, current = current->Next) {
        if (strcmp(current->Key->KeyVal, key) == 0) {
            ValType *item = current->Val;
            if (current == first) {
                first = current->Next;
            } else {
                tmp->Next = current->Next;
            }
            free(current);
            size--;
            return item;
        }
    }
    return NULL;
}

void Keys() {
    printf("SymbolTable:\n");
    for (NodeType *n = first; n != NULL; n= n->Next) {
        printf("Key: %s, Val: %d", n->Key->KeyVal, n->Val->ValVal);
    }
}
