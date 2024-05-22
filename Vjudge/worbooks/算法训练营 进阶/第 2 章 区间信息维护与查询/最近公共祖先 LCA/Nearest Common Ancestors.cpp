#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e4 + 20;
int n, f[N][22], cnt, head[N<<1], dep[N], deg[N];
struct Node {
	int to, net;
}e[N<<1];
inline void insert(int u, int v) {
	e[++cnt].to = v;
	e[cnt].net = head[u];
	head[u] = cnt;
}
void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1; f[u][0] = fa;
	for(int i = 1; dep[u] - (1 << i) >= 0; ++ i)
		f[u][i] = f[f[u][i-1]][i-1];
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(v == fa) continue;
		dfs(v, u);
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
	std :: cin >> n; cnt = 0;
	memset(head, 0, sizeof head);
	memset(deg, 0, sizeof deg);
	memset(e, 0, sizeof e);
	memset(f, 0, sizeof f);
	memset(dep, 0, sizeof dep);
	for(int i = 1; i < n; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		insert(u, v); insert(v, u); deg[v] ++;
	}
	for(int i = 1; i <= n; ++ i)
		if(!deg[i]) {
			dfs(i, i);
			break;
		}
	int s, t; 
	std :: cin >> s >> t;
	std :: cout << LCA(s, t) << endl;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}