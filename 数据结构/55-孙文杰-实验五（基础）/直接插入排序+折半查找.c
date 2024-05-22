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

void insertSortSeqList(SeqList *L) {
	for(int i = 0; i < L->length; ++ i) {
		int j = i - 1;
		for(; j >= 0; -- j)
			if(L->data[j] < L->data[i]) break;
		if(j != i - 1) {
			int temp = L->data[i];
			for(int k = i; k > j + 1; -- k)
				L->data[k] = L->data[k-1];
			L->data[j+1] = temp;
		}
	}
}

void printSeqList(SeqList *L) {
	for(int i = 0; i < L->length; ++ i) {
		printf("%d ", L->data[i]);
	}
	printf("\n");
}

bool querySeqList(SeqList *L, int value, int *pos) {
	int l = 0, r = L->length - 1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(L->data[mid] == value) {
			*pos = mid + 1;
			return true;
		} else if(L->data[mid] < value) {
			l = mid + 1;
		} else {
			r = mid - 1;
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
		
		insertSortSeqList(&L);
		printf("The sorted SeqList:\n");
		printSeqList(&L);

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