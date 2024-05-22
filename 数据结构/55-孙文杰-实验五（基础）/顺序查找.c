#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#define MaxSize 110

typedef struct SeqList {
    int *data;
    int length, maxSize;
}SeqList;

bool initSeqList(SeqList *L) {
	L->data = (int*)malloc(MaxSize * sizeof (int));
	if(L->data == NULL) return false;
	L->length = 0;
	L->maxSize = MaxSize;
	return true;
}

bool insertSeqList(SeqList *L, int e) {
	if(L->length + 1 == L->maxSize) {
		printf("The SeqList is full!\n");
		return false;
	}
	L->data[L->length++] = e;
	return true;
}

bool querySeqList(SeqList *L, int value, int *pos) {
	for(int i = 0; i < L->length; ++ i) {
		if(L->data[i] == value) {
			*pos = i + 1;
			return true;
		}
	}
	return false;
}

int main() {
    SeqList L;
    initSeqList(&L);
		printf("Please enter n:\n");
		int n;
		scanf("%d", &n);
		printf("Please enter n(1 <= n <= 100) integers:\n");
		for(int i = 1; i <= n; ++ i) {
			int e;
			scanf("%d", &e);
			insertSeqList(&L, e);
		}
		printf("Please enter the integer you want to query:\n");
		int ans, pos; scanf("%d", &ans);
		bool flag = querySeqList(&L, ans, &pos);
		if(!flag) {
			printf("The integer you want to query does not exist.\n");
		} else {
			printf("The position of the integer you want to query is the %dth\n", pos);
		}
    return 0;
}