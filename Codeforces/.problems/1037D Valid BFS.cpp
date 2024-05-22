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
int a[N], n, dep[N], cnt[N];
std :: vector <int> son[N], adj[N];
void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1;
	for(auto v : adj[u]) {
		if(v == fa) continue;
		dfs(v, u);
		son[u].push_back(v);
	}
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i < n; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	if(a[1] != 1) {
		std :: cout << "No";
		return ;
	}
	dfs(1, 1);
	for(int i = 1; i <= n; ++ i)
		if(dep[a[i]] < dep[a[i-1]]) {
			std :: cout << "No";
			return ;
		}
	for(int i = 1; i <= n; ++ i)
		std :: sort(son[i].begin(), son[i].end());
	for(int i = 1; i <= n; ++ i)
		cnt[i] = son[i].size();
	std :: queue <int> q;
	q.push(1);
	for(int i = 2; i <= n; ++ i) {
		int u = q.front();
		while(cnt[u] == 0) q.pop(), u = q.front();
		int p = std :: lower_bound(son[u].begin(), son[u].end(), a[i]) - son[u].begin();
		if(p == son[u].size() || son[u][p] != a[i]) {
			std :: cout << "No";
			return ;
		}
		q.push(a[i]);
		cnt[u] --;
	}
	std :: cout << "Yes";
}

int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
//	std :: cin >> T; 
	while(T --) solve();
	return 0;
}