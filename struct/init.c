#include <stdlib.h>
#include <stdio.h>

struct textType
{
	char* text;
};

struct TestS
{
	int val;
	struct textType* text;
	struct TestS* ts;	
};

struct TestS* init(char* key, int val) {
	struct TestS* a = (struct TestS*)calloc(1, sizeof(struct TestS));
	a->val = val;
	a->text = (struct textType*)calloc(1, sizeof(struct textType));
	a->text->text = key;
	a->ts = (struct TestS*)calloc(1, sizeof(struct TestS));
	return a;
}

int main() {
	struct TestS* a = init("abc", 222);
	printf("%s %d %p\n", a->text->text,a->val, a->ts);
	return 0;
}
