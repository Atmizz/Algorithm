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
const int N = 1e5 + 20;
int sz[N], n, k, cnt;
std :: vector <int> adj[N];
void dfs(int u, int fa, int x) {
	sz[u] = 1;
	for(auto v : adj[u]) {
		if(v == fa) {
			continue ;
		}
		dfs(v, u, x);
		sz[u] += sz[v];
	}
	if(sz[u] >= x && u != 1 && cnt > 0) {
		sz[fa] -= sz[u];
		cnt --;
	}
}
bool query(int x) {
	cnt = k;
	dfs(1, 1, x);
	return (cnt == 0 && sz[1] >= x);
}
void solve() {
	std :: cin >> n >> k;
	for(int i = 1; i <= n; ++ i) {
		adj[i].clear();
	}

	for(int i = 1; i < n; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int l = 1, r = n, ans;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(query(mid)) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	std :: cout << ans << '\n';
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