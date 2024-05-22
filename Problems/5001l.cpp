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
	int u, dis;
	friend bool operator < (Node a, Node b) {
		return a.dis > b.dis;
	}
};
struct Edge {
	int to, net, dis;
}e[MaxN << 1];
int n, m, k, cnt, ans = -INF, head[MaxN << 1], dis[MaxN], D[MaxN], u[MaxN], v[MaxN], w[MaxN];
void Insert(int u, int v, int w) {
	e[++cnt] = {v, head[u], w};
	head[u] = cnt;
}
void Dijstra() {
	memset(dis, 0x3f, sizeof dis); dis[k] = 0;
	std :: priority_queue <Node> q; q.push({k, 0});
	while(!q.empty()) {
		int u = q.top().u, d = q.top().dis; q.pop();
		if(dis[u] != d) continue;
		for(int i = head[u]; i; i = e[i].net) {
			int v = e[i].to;
			if(dis[v] > dis[u] + e[i].dis) dis[v] = dis[u] + e[i].dis, q.push({v, dis[v]});
		}
	}
}
int main() {
	n = read(), m = read(), k = read();
	for(int i = 1; i <= m; ++ i) {
		u[i] = read(), v[i] = read(), w[i] = read();
		Insert(u[i], v[i], w[i]);
	} Dijstra();
	for(int i = 1; i <= n; ++ i) D[i] = dis[i];
	memset(head, 0, sizeof head), cnt = 0;
	for(int i = 1; i <= m; ++ i) Insert(v[i], u[i], w[i]);
	Dijstra();
	for(int i = 1; i <= n; ++ i)
		ans = max(ans, D[i] + dis[i]);
	printf("%d", ans);
}