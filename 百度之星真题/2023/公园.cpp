#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define sz(x) (int)x.size()
#define mk std :: make_pair
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << '\n';
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
typedef unsigned long long ull;
template <class T>
T max(T a, T b) {
	return a > b ? a : b;
}
template <class T>
T min(T a, T b) {
	return a < b ? a : b;
}
template <class T>
T abs(T a) {
	return a < 0 ? -a : a;
}
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 4e4 + 20;
int te, fe, s, t, f, n, m;
std :: vector <int> adj[N];
void solve() {
	std :: cin >> te >> fe >> s;
	std :: cin >> t >> f >> n >> m;
	if(t == f && t == n) {
		std :: cout << 0;
		return ;
	}
	for(int i = 0; i < m; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	std :: vector dis(N + 1, std :: vector <int> (3, -1));
	int ok = 0;
	auto bfs = [&](int st, int op) -> void {
		dis[st][op] = 0;
		std :: queue <int> q;
		q.push(st);
		while(sz(q)) {
			int u = q.front(); q.pop();
			if(op == 2 && (u == t || u == f)) {
				ok ++;
			}
			for(auto &v : adj[u]) {
				if(dis[v][op] != -1) {
					continue ;
				}
				dis[v][op] = dis[u][op] + 1;
				q.push(v);
			}
		}
	};
	bfs(t, 0); bfs(f, 1); bfs(n, 2);
	int ans = INT_MAX;
	if(ok != 2) {
		std :: cout << -1;
		return ;
	}
	for(int i = 1; i <= n; ++ i) {
		if(dis[i][0] < 0 || dis[i][1] < 0 || dis[i][2] < 0) {
			continue ;
		}
		ans = std :: min(ans, dis[i][0] * te + dis[i][1] * fe + dis[i][2] * (te + fe - s));
	}
	std :: cout << ans;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	//std :: cin >> _; 
	while(_ --) solve();
	return 0;
}