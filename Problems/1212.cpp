#include <bits/stdc++.h>
#define gc getchar()
typedef unsigned long long ll;
inline int read() {
	int s = 0, f = 1; char ch = gc;
	for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = - 1;
	for(; ch >= '0' && ch <= '9'; ch = gc) s = (s << 3) + (s << 1) + (ch ^ 48);
	return s * f;
}
inline int abs(int a) { return a < 0 ? -a : a;}
inline int max(int a, int b) { return a > b ? a : b;}
inline int min(int a, int b) { return a < b ? a : b;}
const int MaxN = 1e6 + 200;
const int mod = 1e9 + 7;
const int INF = 0x7fffffff;
int n, m, Flag[30], ans = 1;
char ch[30][30];
void dfs(int x, int y, int Now) {
	ans = max(ans, Now + 1);
	if((!Flag[ch[x+1][y] - 'A']) && x + 1 <= n)  Flag[ch[x+1][y] - 'A'] = 1, dfs(x+1, y, Now+1), Flag[ch[x+1][y] - 'A'] = 0;
	if((!Flag[ch[x-1][y] - 'A']) && x - 1 > 0)  Flag[ch[x-1][y] - 'A'] = 1, dfs(x-1, y, Now+1), Flag[ch[x-1][y] - 'A'] = 0;
	if((!Flag[ch[x][y+1] - 'A']) && y + 1 <= m)  Flag[ch[x][y+1] - 'A'] = 1, dfs(x, y+1, Now+1), Flag[ch[x][y+1] - 'A'] = 0;
	if((!Flag[ch[x][y-1] - 'A']) && y - 1 > 0)  Flag[ch[x][y-1] - 'A'] = 1, dfs(x, y-1, Now+1), Flag[ch[x][y-1] - 'A'] = 0;
}
int main() {
	n = read(); m = read();
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= m; ++ j)
			std :: cin >> ch[i][j];
	Flag[ch[1][1] - 'A'] = 1;
	if(!Flag[ch[2][1] - 'A']) Flag[ch[2][1] - 'A'] = 1, dfs(2, 1, 1), Flag[ch[2][1] - 'A'] = 0;
	if(!Flag[ch[1][2] - 'A']) Flag[ch[1][2] - 'A'] = 1, dfs(1, 2, 1), Flag[ch[1][2] - 'A'] = 0;
	printf("%d", ans);
}