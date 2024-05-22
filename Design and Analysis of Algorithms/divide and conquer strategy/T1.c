#include <stdio.h>
const int N = 110;

struct Student {
	char major[N];
	char id[N];
	char name[N];
	int cntTree;
}stu[N];
int n, m, cnt;

int main() {
	printf("软件专业的学生数量：\n");
	scanf("%d", &n);
	printf("软件专业的学生信息，按顺序输入学号、姓名、植树数量：\n");
	for(int i = 1; i <= n; ++ i) {
		stu[++cnt].major = "软件工程";
	}
	return 0;
}