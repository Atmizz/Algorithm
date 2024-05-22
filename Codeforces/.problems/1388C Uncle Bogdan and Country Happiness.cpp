#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e5 + 20;
int n, m, p[N], h[N], good[N], bad[N];
bool flag;
std :: vector <int> adj[N];
void dfs(int u, int pa) {
	if(!flag) {
		return ;
	}
	int gd = 0, bd = 0;
	for(auto v : adj[u]) {
		if(v == pa) {
			continue;
		}
		dfs(v, u);
		gd += good[v];
		bd += bad[v];
	}
	bd += p[u];
	if(gd - bd > h[u]) {
		flag = 0;
		return ;
	}
	if(gd - bd <= h[u]) {
		if((gd + bd - h[u]) % 2 != 0) {
			flag = 0;
			return ;
		}
		good[u] = (h[u] + gd + bd) / 2;
		bad[u] = (gd + bd - h[u]) / 2;
	}
	if(good[u] < 0 || bad[u] < 0) {
		flag = 0;
		return ;
	}
}
void solve() {
	std :: cin >> n >> m; flag = 1;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> p[i];
		adj[i].clear();
	}
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> h[i];
	}
	for(int i = 1; i < n; ++ i) {
		int x, y;
		std :: cin >> x >> y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}
	dfs(1, 0);
	if(good[1] + bad[1] != m) {
		flag = 0;
	}
	std :: cout << (flag ? "YES\n" : "NO\n");
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