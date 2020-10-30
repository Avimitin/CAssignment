#include <stdlib.h>
#include <string.h>
#include "Type.h"

typedef struct node {
    int N;
    node *left;
    node *right;
    KeyType *key;
    ValType *val;
} node;

node *NewNode(char *key, int val, int N) {
    KeyType k = {.KeyVal=key};
    ValType v = {.ValVal=val};
    node *n = (node *) calloc(1, sizeof(node));
    n->key = (struct KeyType *) calloc(1, sizeof(struct KeyType));
    n->val = (struct ValType *) calloc(1, sizeof(struct ValType));
    n->key = k;
    n->val = v;
    return n;
}

node *root;

int size(node *n) {
    if (n == NULL) {
        return 0;
    } else {
        return n->N;
    }
}

int Size() {
    return size(root);
}

int get(node *n, char *key) {
    if (n == NULL) {
        return;
    }
    int cmp = strcmp(n->key->KeyVal, key);
    if (cmp > 0) { get(n->left, key); }
    else if (cmp < 0) { get(n->right, key); }
    else return n->val->ValVal;
}

int Get(char *key) {
    get(root, key);
}

node *put(node *x, char *key, int val) {
    if (x == NULL) {
        NewNode(key, val, 1);
    }
    int cmp = strcmp(x->key->KeyVal, key);
    if (cmp < 0) { put(x->right, key, val); }
    else if (cmp > 0) { put(x->left, key, val); }
    else x->val->ValVal = val;
    // x's left size plus right size plus itself.
    x->N = size(x->left) + size(x->right) + 1;
    return x;
}

void Put(char *key, int val) {
    root = put(root, key, val);
}

node *MinCir() {
    if (root->left == NULL) {
        return root;
    }
    node *x = root;
    while (x->left != NULL) {
        x = x->left;
    }
    return x;
}

node *MinRec(node *x) {
    if (x->left == NULL) {
        return x;
    } else {
        return MinRec(x);
    }
}

char *Min() {
    return MinRec(root)->key->KeyVal;
}

node *MaxRec(node *x) {
    if (x->right == NULL) {
        return x;
    } else {
        return MaxRec(x);
    }
}

char *Max() {
    return MaxRec(root)->key->KeyVal;
}

// if the given key is lower than given node, that the biggest node
// which is lower than given key MUST in the left child tree.
// Else only if there are node in the right child tree which is lower than given key.
// Else the target is the given root node.
node *floorNode(node *x, char *key) {
    if (x == NULL) {
        return NULL;
    }
    int cmp = strcmp(key, x->key->KeyVal);
    if (cmp == 0) {
        return x;
    }
    if (cmp < 0) {
        floorNode(x->left, key);
    }
    node *t = floorNode(x->right, key);
    if (t != NULL) { return t; }
    else return x;
}

node *Floor(char *key) {
    return floorNode(root, key);
}

// The target of ceiling is to get a node which is
// minimum but bigger than the given key.
node *ceiling(node *x, char *key) {
    if (x == NULL) { return x; }
    int cmp = strcmp(x->key->KeyVal, key);
    if (cmp == 0) {
        return x;
    }
    if (cmp > 0) {
        return ceiling(x->left, key);
    }
    node *t = ceiling(x->right, key);
    if (t != NULL) { return t; }
    else return x;
}

node *Select(node *x, int k) {
    if (x->left->N > k) {
        Select(x->left, k);
    } else if (x->left->N == k) {
        return x;
    } else {
        Select(x->right, k - t - 1);
    }
}

int rank(node *x, char *key) {
    if (x == NULL) {
        return 0;
    }
    int cmp = strcmp(x->key->KeyVal, key);
    if (cmp == 0) {
        return x->left->N;
    } else if (cmp > 0) {
        return rank(x->left, key);
    } else return x->left->N + 1 + rank(x->right, key);
}

int Rank(char *key) {
    return rank(root, key);
}

node *delMin(node *x) {
    while (x->left->left != NULL) {
        x->N = x->N - 1;
        x = x->left;
    }
    free(x->left);
    x->left = x->right;
    x->right = NULL;
}

node *DelMin() {
    return delMin(root);
}

node *delMax(node *x) {
    while (x->right->right != NULL) {
        x->N = x->N - 1;
        x = x->right;
    }
    free(x->right);
    x->right = x->left;
    x->left = NULL;
}

node *DelMax() {
    return delMax(root);
}

node *delete(node *x, char *key) {
    if (x == NULL) {
        return NULL;
    }
    int cmp = strcmp(x->key->KeyVal, key);
    if (cmp > 0) { x->left = delete(x->left, key); }
    else if (cmp < 0) { x->right = delete(x->right, key); }
    else {
        if (x->left == NULL) { return x->right; }
        if (x->right == NULL) { return x->left; }
        node *t = x;
        x = MinRec(t->right);
        x->right = delMin(t->right);
        x->left = t->left;
    }
    x->N = size(x->left) + size(x->right) + 1;
    return x;
}

void print(node *x) {
    if (x == NULL) {
        return;
    }
    print(x->left);
    printf("%s", x->key->KeyVal);
    print(x->right);
}

void Print() {
    print(root)
}

struct KeyList {
    int len;
    int cap;
    struct KeyType *KeyList;
};

struct KeyList *NewKeyList(int cap) {
    struct KeyList *k = (struct KeyList *) calloc(1, sizeof(struct KeyList));
    k->KeyList = (struct KeyType *) calloc(cap, sizof(struct KeyType));
    k->cap = cap;
}

void Enlarge(struct KeyList *k) {
    k->KeyList = realloc(k->KeyList, k->cap*2 * sizeof(KeyType));
    k->cap = k->cap*2;
}

void Enqueue(struct KeyList *k, char *key) {
    if (k->len*2 >= cap) {
        Enlarge(k);
    }
    k->KeyList[++k->len].KeyVal = strdup(key);

}