#include "Type.h"
#include <stdlib.h>
#include <string.h>

Array *Keys;
Array *Vals;

void Init(int cap) {
    KeyType **keyArray = (KeyType**)calloc(cap, sizeof(KeyType));
    ValType **valArray = (ValType**)calloc(cap, sizeof(ValType));
    Keys = (Array*)calloc(1, sizeof(Array));
    Vals = (Array*)calloc(1, sizeof(Array));

    Keys->cap = cap;
    Keys->len = 0;
    Keys->data = &keyArray;

    Vals->cap = cap;
    Vals->len = 0;
    Vals->data = &valArray;
}

void resizeKeys() {
    if (Keys->len*2 >= Keys->cap) {
        Keys->data = (KeyType**)realloc(Keys->data, (Keys->cap*2) * sizeof(KeyType));
        return;
    }
    if (Keys->len/4 <= Keys->cap) {
        Keys->data = (KeyType**)realloc(Keys->data, (Keys->cap/4) * sizeof(KeyType));
    }
}

void resizeVals() {
    if (Vals->len*2 >= Vals->cap) {
        Vals->data = (ValType**)realloc(Vals->data, (Vals->cap*2) * sizeof(ValType));
        return;
    }
    if (Vals->len/4 <= Vals->cap) {
        Vals->data = (ValType**)realloc(Vals->data, (Vals->cap/4) * sizeof(ValType));
    }
}

KeyType * getKeyItem(int i) {
    return ((KeyType**)Keys->data)[i];
}

ValType * getValItem(int i) {
    return ((ValType**)Vals->data)[i];
}

int Size() {
    return Keys->len;
}

int Rank(char *key) {
    int lo=0, hi = Size()-1;
    while (lo <= hi) {
        int mid = lo + (hi-lo)/2;
        char *midKey = getKeyItem(mid)->KeyVal;
        int cmp = strcmp(midKey, key);
        if (cmp < 0) {lo = mid + 1;}
        else if (cmp > 0) { hi = mid - 1;}
        else return mid;
    }
    return lo;
}

ValType * Get(char *key) {
    if (Size() == 0) {
        return NULL;
    }
    int i = Rank(key);
    if (i < Size() && strcmp(getKeyItem(i)->KeyVal, key)==0) {
        return getValItem(i);
    }
    return NULL;
}

void Put(char *key, int val) {
    if (Keys->len+1 >= Keys->cap) {
        resizeKeys();
        resizeVals();
    }

    int i = Rank(key);
    if (i<Size() && strcmp(getKeyItem(i)->KeyVal, key)==0) {
        ValType * item = getValItem(i);
        item->ValVal = val;
    }

    for (int j = Size(); j > i; j--) {
        KeyType * key = getKeyItem(j);
        ValType * val = getValItem(j);
        key = getKeyItem(j-1);
        val = getValItem(j-1);
    }
    getKeyItem(i)->KeyVal = key;
    getValItem(i)->ValVal = val;
    Keys->len++;
    Vals->len++;
}

KeyType * Min() {
    return getKeyItem(0);
}

KeyType * Max() {
    return getKeyItem(Keys->len-1);
}

KeyType * Ceiling(char *key) {
    int i = Rank(key);
    return getKeyItem(i);
}

void Delete(char *key) {
    int i = Rank(key);
    if (i > Keys->len || strcmp(getKeyItem(i)->KeyVal, key) != 0) {
        return;
    }
    for (int j = i; j < Keys->len; j++) {
        KeyType *k = getKeyItem(j);
        k = getKeyItem(j+1);
        ValType *v = getValItem(j);
        v = getValItem(j+1);
    }
    Keys->len--;
    Vals->len--;
    resizeKeys();
    resizeVals();
}

void Show() {
    for (int i = 0; i < Keys->len; i++) {
        printf("Key: %s, Val: %d\n", getKeyItem(i)->KeyVal, getValItem(i)->ValVal);
    }
}
