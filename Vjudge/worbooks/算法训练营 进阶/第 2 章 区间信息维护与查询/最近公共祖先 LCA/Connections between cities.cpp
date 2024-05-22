#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e4 + 20;
const int M = 1e6 + 20;
struct Node {
	int to, net, dis;
}e[N<<1];
struct Query {
	int to, net;
}q[M<<1];
int n, m, k, cnt, tot, head[N<<1], dep[N], pa[N], vis[N], d[N], ans[M], qhead[M<<1];
inline void insert(int u, int v, int w) {
	e[++cnt] = {v, head[u], w};
	head[u] = cnt;
}
int find(int x) {
	return x == pa[x] ? x : pa[x] = find(pa[x]);
}
void tarjan(int u, int rt) {
	vis[u] = rt;
	if(u == rt) d[u] = 0;
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(vis[v] == 0) {
			d[v] = d[u] + e[i].dis;
			tarjan(v, rt);
			pa[v] = u;
		}
	}
	for(int i = qhead[u]; i; i = q[i].net) {
		int v = q[i].to;
		if(vis[v] == rt)
			ans[(i + 1)>>1] = d[u] + d[v] - d[find(v)] * 2;
	}
}
inline void init() {
	cnt = 0; tot = 0;
	for(int i = 1; i <= n; ++ i) vis[i] = 0;
	for(int i = 1; i <= k; ++ i) ans[i] = -1;
	for(int i = 1; i <= n; ++ i) pa[i] = i;
	for(int i = 1; i <= n; ++ i) head[i] = 0;
	for(int i = 1; i <= n; ++ i) qhead[i] = 0;
}
void solve() {
	while(std :: cin >> n >> m >> k) {
		init();
		for(int i = 1; i <= m; ++ i) {
			int u, v, w;
			std :: cin >> u >> v >> w;
			insert(u, v, w);
			insert(v, u, w);
		}
		for(int i = 1; i <= k; ++ i) {
			int l, r;
			std :: cin >> l >> r;
			q[++tot] = {r, qhead[l]};
			qhead[l] = tot;
			q[++tot] = {l, qhead[r]};
			qhead[r] = tot;
		}
		for(int i = 1; i <= n; ++ i)
			if(!vis[i]) tarjan(i, i);
		for(int i = 1; i <= k; ++ i)
			if(ans[i] != -1)
				std :: cout << ans[i] << endl;
			else std :: cout << "Not connected\n";
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}
