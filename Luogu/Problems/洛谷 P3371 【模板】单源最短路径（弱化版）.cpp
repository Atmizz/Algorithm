#include <bits/stdc++.h>
#define gc getchar()
#define ll long long
inline int read() {
	int s = 0, f = 1; char ch = gc;
	for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
	for(; ch >= '0' && ch <= '9'; ch = gc)
		s = (s << 1) + (s << 3) + (ch ^ 48);
	return s * f;
}
const int MaxN = 5e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
struct Edge {
    int to, net, dis;
}e[MaxN << 1];
int n, m, s, head[MaxN << 1], cnt, dis[MaxN];
bool vis[MaxN];
void Insert(int u, int v, int w) {
	e[++cnt] = {v, head[u], w};
	head[u] = cnt;
}
void Init() {
	n = read(); m = read(); s = read();
	for(int i = 1; i <= m; ++ i) {
		int u = read(), v = read(), w = read();
		Insert(u, v, w);
	}
}
void SPFA() {
	for(int i= 1; i <= n; ++ i) dis[i] = INF;
	std :: queue <int> q; dis[s] = 0; q.push(s); vis[s] = 1;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int i = head[u]; i; i = e[i].net)
			if(dis[e[i].to] > dis[u] + e[i].dis) {
				dis[e[i].to] = dis[u] + e[i].dis;
				q.push(e[i].to), vis[e[i].to] = 1;
			}
	}
}
void Print() {
	for(int i = 1; i <= n; ++ i)
		printf("%d ", dis[i]);
}
int main() {
	Init(); SPFA(); Print();
	return 0;
}