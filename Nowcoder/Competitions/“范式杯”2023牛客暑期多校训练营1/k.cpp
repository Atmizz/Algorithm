#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
#define int long long
typedef long long ll;
inline int read() {
	int s = 0, f = 1; char ch = gc;
	for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
	for(; ch >= '0' && ch <= '9'; ch = gc)
		s = (s << 1) + (s << 3) + (ch ^ 48);
	return s * f;
}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 2e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, k, u[MaxN], v[MaxN], mk[MaxN], dis[MaxN], head[MaxN<<1], cnt, ans, fa[MaxN];
bool vis[MaxN];
struct Edge {
	int to, net;
}e[MaxN<<1];
std :: vector <int> son[MaxN];
namespace Dij {
	struct Node {
		int x, dis;
		friend bool operator < (Node a, Node b) {
			return a.dis > b.dis;
		}
	};
	void dij() {
		dis[1] = 0;
		std :: priority_queue <Node> q;
		q.push({1, 0}); dis[1] = 0;
		while(q.size()) {
			int u = q.top().x, d = q.top().dis; q.pop();
			if(d != dis[u]) continue;
			for(int i = head[u]; i; i = e[i].net) {
				int v = e[i].to;
				if(dis[v] > dis[u] + 1) {
					dis[v] = dis[u] + 1, mk[v] = u;
					q.push({v, dis[v]});
				}
			}
		}
	}
}
void Insert(int u, int v) {
	e[++cnt] = {v, head[u]};
	head[u] = cnt;
}
void dfs(int u) {
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(mk[v] == u) son[u].push_back(v), dfs(v);
	}
}
void solve() {
	n = read(); m = read(), k = read();
	for(int i = 1; i <= m; i ++) u[i] = read(), v[i] = read(), Insert(u[i], v[i]), Insert(v[i], u[i]);
	for(int i = 1; i <= n; ++ i) dis[i] = 0x3f3f3f3f;
	Dij :: dij();
	for(int i = 1; i <= n; ++ i)
		if(dis[i] <= 3) ans ++;
	dfs(1);
	for(int i = 1; i <= m; ++ i) {
		if(mk[u[i]] == v[i] || mk[v[i]] == u[i]) continue;
		if(dis[u[i]] == 0x3f3f3f3f) continue;
		ans += (k * 2 - dis[u[i]] - dis[v[i]]);
		if(son[u[i]].size() == 0) vis[u[i]] = 1;
		if(son[v[i]].size() == 0) vis[v[i]] = 1;
	}
	for(int i = 1; i <= n; ++ i)
		if(son[i].size() == 0 && !vis[i] && dis[i] <= k) ans += (k - dis[i]);
	printf("%lld", ans);
}
signed main() {
	solve();
	return 0;
}
