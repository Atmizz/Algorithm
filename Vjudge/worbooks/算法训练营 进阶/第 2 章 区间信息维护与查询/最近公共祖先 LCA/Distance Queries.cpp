#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define i64 long long
#define deb(x) std :: cout << #x << " = " << x << '\n';
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 4e4 + 20;
struct Node {
	int to, net;
	i64 dis;
}e[N<<1];
int n, m, k, cnt, head[N<<1], dep[N], f[N][22];
i64 d[N];
inline void insert(int u, int v, i64 w) {
	e[++cnt].to = v;
	e[cnt].net = head[u];
	e[cnt].dis = w;
	head[u] = cnt;
}
void dfs(int u, int fa) {
	f[u][0] = fa; dep[u] = dep[fa] + 1;
	for(int i = 1; dep[u] - (1 << i) >= 0; ++ i)
		f[u][i] = f[f[u][i-1]][i-1];
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(v == fa) continue;
		d[v] = d[u] + e[i].dis; dfs(v, u);
	}
}
int LCA(int x, int y) {
	if(dep[x] < dep[y]) std :: swap(x, y);
	for(int i = 21; i >= 0; -- i)
		if(dep[f[x][i]] >= dep[y]) x = f[x][i];
	if(x == y) return x;
	for(int i = 21; i >= 0; -- i)
		if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= m; ++ i) {
		int u, v; i64 w; char ch;
		std :: cin >> u >> v >> w >> ch;
		insert(u, v, w); insert(v, u, w);
	} dfs(1, 1);
	std :: cin >> k;
	while(k --) {
		int l, r;
		std :: cin >> l >> r;
		std :: cout << d[l] + d[r] - 2 * d[LCA(l, r)] << endl;
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