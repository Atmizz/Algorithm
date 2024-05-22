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
int n, m, vis[N];
std :: vector <int> adj[N];
std :: map <int, std :: map <int, int> > mp;
bool flag = 0;
void dfs(int u, int mk) {
	if(flag == 1) {
		return ;
	}
	for(auto v : adj[u]) {
		if(mp[u][v] != -1 && mp[u][v] != mk) {
			flag = 1;
			return ;
		}
		if(mp[v][u] != -1 && mp[v][u] != mk ^ 1) {
			flag = 1;
			return ;
		}
		mp[u][v] = mk;
		mp[v][u] = mk^1;
		if(vis[v]) {
			continue ;
		}
		vis[v] = 1;
		dfs(v, mk^1);
	}
}
int u[N], v[N];
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= m; ++ i) {
		std :: cin >> u[i] >> v[i];
		adj[u[i]].push_back(v[i]);
		adj[v[i]].push_back(u[i]);
		mp[u[i]][v[i]] = mp[v[i]][u[i]] = -1;
	}
	for(int i = 1; i <= n; ++ i) {
		vis[i] = 0;
	}
	vis[1] = 1;
	dfs(1, 1);
	if(flag == 1) {
		std :: cout << "NO";
		return ;
	}
	std :: cout << "YES\n";
	for(int i = 1; i <= m; ++ i) {
		std :: cout << mp[u[i]][v[i]];
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