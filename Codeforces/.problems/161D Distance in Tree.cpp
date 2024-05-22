#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 5e4 + 20;
int n, k, head[N], cnt, S, rt, sz[N], mx[N], d[N], ans;
bool vis[N];
struct Edge {
	int to, net;
}e[N<<1];
inline void Insert(int u, int v) {
	e[++cnt] = {v, head[u]};
	head[u] = cnt;
}
void getRoot(int u, int fa) {
	sz[u] = 1; mx[u] = 0;
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(v == fa || vis[v]) continue;
		getRoot(v, u);
		sz[u] += sz[v];
		mx[u] = std :: max(mx[u], sz[v]);
	}
	mx[u] = std :: max(mx[u], S - sz[u]);
	if(mx[u] < mx[rt]) rt = u;
}
void getDis(int u, int fa, int dis) {
	d[++d[0]] = dis;
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(v == fa || vis[v]) continue;
		getDis(v, u, dis + 1);
	}
}
int judge[N], res[N];
void calc(int u) {
	int p = 0;
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(vis[v]) continue;
		d[0] = 0; getDis(v, u, 1);
		for(int j = 1; j <= d[0]; ++ j)
			if(k >= d[j])
				ans += judge[k-d[j]];
		for(int j = 1; j <= d[0]; ++ j)
			res[++p] = d[j], judge[d[j]] ++;
	}
	for(int i = 1; i <= p; ++ i)
		judge[res[i]] = 0;
}
void devide(int u) {
	vis[u] = 1; calc(u);
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(vis[v]) continue;
		S = sz[v]; rt = 0;
		getRoot(v, u); devide(rt);
	}
}
void solve() {
	std :: cin >> n >> k;
	for(int i = 1; i < n; ++ i) {
		int u, v; std :: cin >> u >> v;
		Insert(u, v); Insert(v, u);
	}
	judge[0] = 1; mx[0] = S = n; getRoot(1, 1); devide(rt);
	std :: cout << ans;
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