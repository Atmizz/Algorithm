#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define int long long
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
const int N = 22;
std :: vector <PII> adj[N];
int g[N][N];
void solve() {
	int n, m, k, shabu, ldz;
	std :: cin >> n >> m >> k >> shabu >> ldz;
	for(int i = 0; i < n; ++ i) {
		for(int j = 0; j < n; ++ j) {
			g[i][j] = INF;
		}
	}
	for(int i = 1; i <= m; ++ i) {
		int u, v, w;
		std :: cin >> u >> v >> w;
		if(u == v) {
			continue ;
		}
		u --; v --;
		g[u][v] = g[v][u] = min(g[u][v], w);
	}
	// for(int h = 0; h < n; ++ h) {
	// 	for(int i = 0; i < n; ++ i) {
	// 		if(i == h) {
	// 			continue ;
	// 		}
	// 		for(int j = 0; j < n; ++ j) {
	// 			if(j == i || j == h) {
	// 				continue ;
	// 			}
	// 			g[i][j] = min(g[i][j], g[i][h] + g[h][j]);
	// 		}
	// 	}
	// }
	for(int i = 0; i < n; ++ i) {
		for(int j = 0; j < n; ++ j) {
			if(g[i][j] != INF) {
				adj[i].pb({j, g[i][j]});
			}
		}
	}
	for(int i = 0; i < n; ++ i) {
		std :: sort(adj[i].begin(), adj[i].end(), [&](PII a, PII b) {
			return a.second < b.second;
		});
	}
	std :: vector <int> s(k+1), bw(k+1), bq(k+1);
	for(int i = 1; i <= k; ++ i) {
		std :: cin >> s[i] >> bw[i] >> bq[i];
	}

	std :: vector <i64> dp(1 << n, LLONG_MAX / 2);
	dp[1] = 0;
	for(int _ = 1; _ < 1 << n; ++ _) {
		for(int j = 0; j < n; ++ j) {
			if(_ >> j & 1) {
				for(auto &[v, w] : adj[j]) {
					if(_ >> v & 1) {
						dp[_] = min(dp[_], dp[_^(1<<j)] + w);
						break;
					}
				}
			}
		}
	}
	i64 road = dp[(1<<n)-1] * 2;
	std :: cout << road << nl;
	if(road > shabu) {
		std :: cout << "Shub, go work overtime!";
		return ;
	}
	shabu -= road;
	std :: vector <i64> f(shabu+1);
	for(int i = 1; i <= k; ++ i) {
		if(s[i] * bw[i] >= shabu) {
			for(int j = bw[i]; j <= shabu; ++ j) {
				f[j] = max(f[j], f[j-bw[i]] + bq[i]);
			}
		} else {
			for(int h = 1; s[i]; h <<= 1) {
				int x = min(h, s[i]);
				for(int j = shabu; j >= x * bw[i]; -- j) {
					f[j] = max(f[j], f[j-x*bw[i]] + x * bq[i]);
				}
				s[i] -= x;
			}
		}
	}
	i64 ans = 0;
	for(int i = 0; i <= shabu; ++ i) {
		ans = max(ans, f[shabu]);
	}
	std :: cout << ans << nl;
	std :: cout << (ans > ldz ? "YES" : "NO");
}
signed main() {
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