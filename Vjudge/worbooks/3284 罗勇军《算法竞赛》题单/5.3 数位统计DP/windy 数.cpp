#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
typedef struct LNode {
	int data;
	struct LNode *next;
}LNode, *LinkList;
void CreateList_L(LinkList &L, int n) {
	L = (LinkList)malloc(sizeof (LNode));
	L->next = NULL;
	for(int i = n; i >= 1; -- i) {
		LinkList p = (LinkList)malloc(sizeof (LNode));
		scanf("%d", &(p->data));
		p->next = L->next;
		L->next = p;
	}
}
int GetElem_L(LinkList L, int i, int &e) {
	LinkList p = L->next;
	int j = 1;
	while(p != NULL && j < i) {
		p = p->next;
		++ j;
	}
	if(!p || j > i) return ERROR;
	e = p->data;
	return OK;
}
void ClearList_L(LinkList &L) {
	LinkList p = L, temp = p;
	while(p->next != NULL) {
		temp = p->next;
		free(p);
		p = temp;
	}
}
int main() {
	int n;
	LinkList L;
	scanf("%d", &n);
	CreateList_L(L, n);
	for(int i = 1; i <= n; ++ i) {
		int e;
		GetElem_L(L, i, e);
		printf("%d\n", e);
	}
	ClearList_L(L);
	return 0;
}