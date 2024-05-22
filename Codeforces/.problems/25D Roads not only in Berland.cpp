// LUOGU_RID: 149577669
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
const int N = 1010;
int n, belonged[N], cnt, rt, flag;
std :: vector <int> adj[N], tree(N);
std :: vector <PII> edge;
std :: map <int, std :: map <int, int> > m;
void dfs(int u, int fa, int id) {
	belonged[u] = id;
	// deb(u);
	for(auto v : adj[u]) {
		if(v == fa) {
			continue;
		}
		if(belonged[v]) {
			flag = 1;
			if(!m[std :: min(u, v)][std :: max(v, u)]) {
				edge.push_back({u, v});
				m[std :: min(u, v)][std :: max(v, u)] = 1;
			}
		} else {
			dfs(v, u, id);
		}
	}
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i < n; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	for(int i = 1; i <= n; ++ i) {
		if(belonged[i]) {
			continue;
		}
		++cnt;
		tree[cnt] = i;
		flag = 0;
		dfs(i, i, cnt);
		if(!flag) {
			rt = i;
		}
	}
	std :: cout << cnt - 1 << '\n';
	int res = 0;
	for(int i = 1; i <= cnt; ++ i) {
		if(tree[i] == rt) {
			continue;
		}
		std :: cout << edge[res].first << ' ' << edge[res].second << ' ' << tree[i] << ' ' << rt << '\n';
		res ++;
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