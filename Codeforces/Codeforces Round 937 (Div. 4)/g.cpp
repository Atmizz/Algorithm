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
const int N = 20;
struct Node {
	int a, b;
}v[N];
void solve() {
	int n;
	std :: cin >> n;
	std :: map <std :: string, int> mp;
	int cnt = 0;
	for(int i = 0; i < n; ++ i) {
		std :: string s, t;
		std :: cin >> s >> t;
		if(!mp.count(s)) {
			mp[s] = ++ cnt;
		}
		if(!mp.count(t)) {
			mp[t] = ++ cnt;
		}
		v[i].a = mp[s];
		v[i].b = mp[t];
	}
	std :: vector <int> adj[n+1];
	for(int i = 0; i < n; ++ i) {
		for(int j = i+1; j < n; ++ j) {
			if(v[i].a == v[j].a || v[i].b == v[j].b) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	// for(int i = 0; i < n; ++ i) {
	// 	std :: cout << v[i].a << ' ' << v[i].b << '\n';
	// }
	std :: vector dp(1<<n, std :: vector <int> (n));
	for(int i = 0; i < n; ++ i) {
		dp[1<<i][i] = 1;
	}
	for(int _ = 1; _ < 1 << n; ++ _) {
		for(int i = 0; i < n; ++ i) {
			if(!(_>>i&1)) {
				continue ;
			}
			for(int j = 0; j < n; ++ j) {
				if(i == j || !(_>>j&1)) {
					continue ;
				}
				if(v[i].a != v[j].a && v[i].b != v[j].b) {
					continue ;
				}
				// deb(_);
				// std :: cout << i << ' ' << j << '\n';
				dp[_][i] = std :: max(dp[_][i], dp[_^(1<<i)][j] + 1);
				// deb((_^(1<<j)))
				// deb(dp[_^(1<<j)][j])
				// deb(dp[_][i]);
			}
		}
	}
	int ans = 0;
	for(int _ = 1; _ < 1 << n; ++ _) {
		for(int j = 0; j < n; ++ j) {
			ans = std :: max(ans, dp[_][j]);
		}
	}
	std :: cout << n - ans << '\n';
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