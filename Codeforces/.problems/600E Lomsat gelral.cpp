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
const int N = 1e5 + 20;
int n, col[N], cnt, head[N], num[N], sz[N], son[N];
i64 ans[N], sum, maxx;
struct Edge {
	int to, net;
}e[N<<1];
inline void Insert(int u, int v) {
	e[++cnt] = {v, head[u]};
	head[u] = cnt;
}
void dfsSon(int u, int fa) {
	sz[u] = 1;
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(v == fa) continue;
		dfsSon(v, u); sz[u] += sz[v];
		if(sz[v] > sz[son[u]]) son[u] = v;
	}
}
void count(int u, int fa, int pson, int val) {
	int c = col[u];
	num[c] += val;
	if(num[c] > maxx) maxx = num[c], sum = c;
	else if(num[c] == maxx) sum += c;
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(v == fa || v == pson) continue;
		count(v, u, pson, val);
	}
}
void dfs(int u, int fa, bool keep) {
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(v == fa || v == son[u]) continue;
		dfs(v, u, 0);
	}
	if(son[u]) dfs(son[u], u, 1);
	count(u, fa, son[u], 1);
	ans[u] = sum;
	if(!keep) {
		count(u, fa, 0, -1);
		sum = maxx = 0;
	}
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> col[i];
	for(int i = 1; i < n; ++ i) {
		int u, v; std :: cin >> u >> v;
		Insert(u, v); Insert(v, u);
	}
	dfsSon(1, 1); dfs(1, 1, 1);
	for(int i = 1; i <= n; ++ i)
		std :: cout << ans[i] << ' ';
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