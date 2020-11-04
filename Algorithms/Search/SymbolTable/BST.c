#include <stdlib.h>
#include <string.h>
#include "Type.h"

typedef struct node {
	int N;
	struct node *left;
	struct node *right;
	KeyType *key;
	ValType *val;
} node;

node *NewNode(char *key, int val, int N) {
	KeyType k = {.KeyVal=key};
	ValType v = {.ValVal=val};
	node *n = (node *) calloc(1, sizeof(node));
	n->key = (struct KeyType *) calloc(1, sizeof(struct KeyType));
	n->val = (struct ValType *) calloc(1, sizeof(struct ValType));
	*n->key = k;
	*n->val = v;
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
		return 0;
	}
	int cmp = strcmp(n->key->KeyVal, key);
	if (cmp > 0) { get(n->left, key); }
	else if (cmp < 0) { get(n->right, key); }
	return n->val->ValVal;
}

int Get(char *key) {
	return get(root, key);
}

node *put(node *x, char *key, int val) {
	if (x == NULL) {
		return NewNode(key, val, 1);
	}
	int cmp = strcmp(x->key->KeyVal, key);
	if (cmp < 0)      { x->right = put(x->right, key, val); }
	else if (cmp > 0) { x->left = put(x->left, key, val); }
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
		return Select(x->left, k);
	} else if (x->left->N == k) {
		return x;
	} else {
		return Select(x->right, k - x->left->N - 1);
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
	return x;
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
	return x;
}

node *DelMax() {
	return delMax(root);
}

node *delete(node *x, char *key) {
	if (x == NULL) {
		return NULL;
	}
	int cmp = strcmp(x->key->KeyVal, key);
	if (cmp > 0)              { x->left = delete(x->left, key); }
	else if (cmp < 0)         { x->right = delete(x->right, key); }
	else                      {
		if (x->left == NULL)  { return x->right; }
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
	printf("%s, %d\n", x->key->KeyVal, x->val->ValVal);
	print(x->right);
}

void Print() {
	print(root);
}

struct KeyQueue {
	int len;
	int cap;
	struct KeyType *Queue;
};

struct KeyQueue *NewKeyList(int cap) {
	struct KeyQueue *k = (struct KeyQueue *) calloc(1, sizeof(struct KeyQueue));
	k->Queue = (struct KeyType *) calloc(cap, sizeof(struct KeyType));
	k->cap = cap;
	return k;
}

void Enlarge(struct KeyQueue *k) {
	k->Queue = realloc(k->Queue, k->cap*2 * sizeof(KeyType));
	k->cap = k->cap*2;
}

void Shrink(struct KeyQueue *k) {
	k->Queue = realloc(k->Queue, (k->cap/2)*sizeof(KeyType));
	k->cap = k->cap/2;
}

void Enqueue(struct KeyQueue *k, char *key) {
	if (k->len*2 >= k->cap) {
		Enlarge(k);
	}
	k->Queue[++k->len].KeyVal = strdup(key);
}

KeyType DeQueue(struct KeyQueue *k) {
	if (k->len/4 <= k->cap) {
		Shrink(k);
	}
	return k->Queue[k->len--];
}

void keys(node *x, struct KeyQueue *q, KeyType lo, KeyType hi) {
	if (x == NULL) {
		return;
	}
	int cmpLo = strcmp(x->key->KeyVal, lo.KeyVal);
	int cmpHi = strcmp(x->key->KeyVal, hi.KeyVal);
	if (cmpLo > 0)                { keys(x->left, q, lo, hi); }
	if (cmpLo <= 0 && cmpHi == 0) { Enqueue(q, x->key->KeyVal); }
	if (cmpHi < 0)                { keys(x->right, q, lo, hi); }
}

KeyType *Keys(KeyType lo, KeyType hi) {
	struct KeyQueue *q = NewKeyList(10);
	keys(root, q, lo, hi);
	return q->Queue;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		return -1;
	}
	for (int i = 1; i < argc; i++)
	{
		Put(argv[i], i);
	}
	Print();
	return 0;
}
