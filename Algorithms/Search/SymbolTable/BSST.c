#include "Type.h"
#include <stdlib.h>
#include <string.h>

// Array that contain other pointers.
KeyType **keys;
ValType **vals;
int N;

void Init(int cap) {
	keys = (KeyType**)calloc(cap, sizeof(KeyType));
	vals = (ValType**)calloc(cap, sizeof(ValType));
	for (int i = 0; i < cap; i++) {
		keys[i] = (KeyType*)calloc(1, sizeof(KeyType));
		keys[i] -> KeyVal = (char*)calloc(50, sizeof(char));
		vals[i] = (ValType*)calloc(1, sizeof(ValType));
	}
}

int size() {
	return N;
}

int Rank(char * key) {
	int lo = 0, hi = N - 1;
	while(lo <= hi) {
		int mid = lo + (hi - lo)/2;
		if (strcmp(keys[mid]->KeyVal, key) < 0) {
			lo = mid + 1;
		} else if (strcmp(keys[mid]->KeyVal, key) > 0) {
			hi = mid - 1;
		} else {
			return mid;
		}
	}
	return lo;
}

ValType * Get(char * key) {
	int i = Rank(key);
	if (i <= N && strcmp(keys[i]->KeyVal, key) == 0) {
		return vals[i];
	}
	return NULL;
}

void Put(char * key, int val) {
	int i = Rank(key);
	if (i < N && strcmp(keys[i]->KeyVal, key) == 0) {
		vals[i]->ValVal = val;
		return;
	}

	for (int j = N; j > i; j--) {
		*keys[j] = *keys[j-1];
		*vals[j] = *vals[j-1];
	}
	keys[i] -> KeyVal = strdup(key);
	vals[i]->ValVal = val;
	N++;
}

void Show() {
	for (int i = 0; i < N; i++) {
		printf("key: %s, val: %d\n", keys[i]->KeyVal, vals[i]->ValVal);
	}
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        return -1;
    }
    Init(argc - 1);
    for (int i = 1; i < argc; i++)
    {   
        Put(argv[i], i);
    }
    Show();
    return 0;
}