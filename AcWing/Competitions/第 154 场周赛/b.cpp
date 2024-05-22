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
// const int N = ;
void solve() {
	int n, m;
	std :: cin >> n >> m;
	std :: vector <int> adj[n+1], vis(n+1);
	for(int i = 1; i <= m; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i = 1; i <= n; ++ i) {
		if(!vis[i]) {
			int cnt = 0;
			i64 sum = 0;
			std :: queue <int> q;
			vis[i] = 1; q.push(i);
			while(sz(q)) {
				int u = q.front(); q.pop();
				cnt ++;
				sum += sz(adj[u]);
				for(auto v : adj[u]) {
					if(!vis[v]) {
						vis[v] = 1;
						q.push(v);
					}
				}
			}
			if(sum == 0) {
				continue ;
			}
			if(1LL * cnt * (cnt - 1) != sum) {
				// std :: cout << i << ' ' << cnt << ' ' << sum << nl;
				std :: cout << "NO";
				return ;
			}
		}
	}
	std :: cout << "YES";
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