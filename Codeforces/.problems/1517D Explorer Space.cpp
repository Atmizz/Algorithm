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
const int N = 3e5 + 20;
std :: vector <PII> adj[N];
int vis[N];
void solve() {
	int n, m, k;
	std :: cin >> n >> m >> k;
	std :: vector ans(n+1, std :: vector <int> (m+1));
	if(k & 1) {
		for(int i = 1; i <= n; ++ i) {
			for(int j = 1; j <= m; ++ j) {
				std :: cout << -1 << " \n"[j == m];
			}
		}
		return ;
	}
	auto get = [&](int x, int y) -> int {
		return (x - 1) * m + y;
	};
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j < m; ++ j) {
			int x;
			std :: cin >> x;
			int u = get(i, j);
			int v = get(i, j+1);
			adj[u].pb({v, x});
			adj[v].pb({u, x});
		}
	}
	for(int i = 1; i < n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			int x;
			std :: cin >> x;
			int u = get(i, j);
			int v = get(i+1, j);
			adj[u].pb({v, x});
			adj[v].pb({u, x});
		}
	}
	std :: vector dp(n*m+1, std :: vector <int> ((k >> 1) + 1, INF));
	int s = n * m;
	for(int i = 1; i <= s; ++ i) {
		dp[i][0] = 0;
	}
	for(int h = 0; h < k >> 1; ++ h) {
		for(int u = 1; u <= s; ++ u) {
			for(auto [v, w] : adj[u]) {
				dp[v][h+1] = min(dp[v][h+1], dp[u][h] + w);
			}
		}
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			int u = get(i, j);
			std :: cout << dp[u][k>>1] * 2 << " \n"[j == m];
		}
	}
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