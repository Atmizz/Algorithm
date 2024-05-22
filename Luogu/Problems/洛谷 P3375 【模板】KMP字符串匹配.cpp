#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
inline int read() {
	int s = 0, f = 1; char ch = gc;
	for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
	for(; ch >= '0' && ch <= '9'; ch = gc)
		s = (s << 1) + (s << 3) + (ch ^ 48);
	return s * f;
}
inline int abs(int a) {return a < 0 ? -a : a;}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 1e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
char s1[MaxN], s2[MaxN];
int len1, len2, Next[MaxN];
std :: vector <int> ans;
void getNext() {
	int i = 0, j = -1; Next[0] = -1;
	while(i < len2) {
		if(j == -1 || s2[i] == s2[j]) i ++, j ++, Next[i] = j;
		else j = Next[j];
	}
}
void doKmp() {
	int i = 0, j = 0;
	while(i < len1) {
		if(j == -1 || s1[i] == s2[j]) i ++, j ++;
		else j = Next[j];
		if(j == len2) ans.push_back(i - len2 + 1);
	}
}
void doPrint() {
	for(auto i : ans)
		printf("%d\n", i);
	for(int i = 1; i <= len2; ++ i)
		printf("%d ", Next[i]);
}
int main() {
	scanf("%s", s1); scanf("%s", s2);
	len1 = strlen(s1); len2 = strlen(s2);
	getNext(); doKmp(); doPrint();
	return 0;
}