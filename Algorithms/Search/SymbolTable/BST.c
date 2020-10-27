#include <stdlib.h>
#include <string.h>
#include "Type.h"

typedef struct node {
	int N;
	node *left;
	node *right;
	KeyType *key;
	ValType *val;
}node;

node * NewNode(char *key, int val, int N) {
	KeyType *k = {key};
	ValType *v = {val};
	node *n = {k, v, N};
	return n;
}

node *root;

int size(node *n) {
	if (n == NULL) {
		return 0;
	}else {
		return n->N;
	}
}

int Size() {
	return size(root);
}

int Get(char *key) {
	get(root, key);
}

int get(node *n, char *key) {
	if (n == NULL) {
		return NULL;
    }
    int cmp = strcmp(n->key->KeyVal, key);
	if (cmp > 0) {getVal(n->left, key);}
	else if (cmp < 0) {getVal(n->right, key);}
	else return n->val->ValVal; 
}

void Put(char *key, int val) {
	root = put(root, key, val);
}

node * put(node *x, char *key, int val) {
	if (x == NULL) {
		NewNode(key, val, 1);
	}
	int cmp = strcmp(x->key->KeyVal, key);
	if (cmp < 0) {put(x->right, key, val);}
	else if (cmp > 0) {put(x->left, key, val);}
	else x->val->ValVal = val;
	// x's left size plus right size plus itself.
	x->N = size(x->left) + size(x->right) + 1;
	return x;
}

// Delete min using circulation
node * DelMinCir() {
	if (root->left == NULL) {
		return root;
	}
	node *x = root;
	while (x->left != NULL) {
		x=x->left;
	}
	return x;
}

node * DelMinRec(node *x) {
	if (x->left == NULL) {
		return x;
	} else {
		return DelMinRec(x);
	}
}

char * Min() {
	return DelMinRec(root)->key->KeyVal;
}

node * Floor(node *x, char *key) {
	if (x == NULL) {
		return x;
	}
	int cmp = strcmp(key, x->key->KeyVal);
	if (cmp < 0) {
		Floor(x->left, key);
	} else if (cmp > 0) {
		Floor(x->right, key);
	} else {
		return x;
	}
}