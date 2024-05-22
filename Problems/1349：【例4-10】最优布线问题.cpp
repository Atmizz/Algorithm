#include <bits/stdc++.h>
#define gc getchar()
typedef long long ll;
inline int read() {
	int s = 0, f = 1; char ch = gc;
	for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
	for(; ch >= '0' && ch <= '9'; ch = gc)
		s = (s << 1) + (s << 3) + (ch ^ 48);
	return s * f;
}
inline int max(int a, int b) {return a > b ? a : b;}
inline int min(int a, int b) {return a < b ? a : b;}
inline int abs(int a) {return a < 0 ? -a : a;}
const int MaxN = 2e5 + 300;
const int INF = 0x7fffffff;
const int Mod = 19260817;
struct Node {
	int u, v, w;
	friend bool operator < (Node a, Node b) {
		return a.w < b.w;
	}
}e[MaxN];
int n, pa[MaxN], Map[150][150], cnt;
int Find(int x) {
	return x == pa[x] ? pa[x] : pa[x] = Find(pa[x]);
}
int main() {
	n = read(); int k = 0, ans = 0;
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= n; ++ j)
			e[++cnt].u = i, e[cnt].v = j, e[cnt].w = read();
	for(int i = 1; i <= n; ++ i) pa[i] = i;
	std :: sort(e + 1, e + 1 + cnt);
	for(int i = 1; i <= cnt; ++ i) {
		int u = Find(e[i].u), v = Find(e[i].v);
		if(pa[u] == pa[v]) continue ;
		ans += e[i].w; k ++; pa[u] = v;
		if(k == n-1) break ;
	}
	printf("%d", ans);
}