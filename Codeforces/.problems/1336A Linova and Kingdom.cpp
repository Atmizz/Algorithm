#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e5 + 20;
std :: vector <int> adj[N];
int dep[N], sz[N];

void dfs(int u, int pa) {
	dep[u] = dep[pa] + 1; sz[u] = 1;
	for(auto v : adj[u]) {
		if(v == pa) continue;
		dfs(v, u); sz[u] += sz[v];
	}
}
void solve() {
	int n, k;
	std :: cin >> n >> k;
	for(int i = 1; i < n; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	std :: vector <int> a(n);
	for(int i = 1; i <= n; ++ i) {
		// deb(dep[i]); deb(sz[i]);
		a[i-1] = dep[i] - sz[i];
	}
	std :: sort(a.begin(), a.end());
	i64 ans = 0;
	for(int i = n - 1; i >= n - k; -- i)
		ans += a[i];
	std :: cout << ans << endl;
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