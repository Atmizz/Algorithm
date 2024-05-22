// LUOGU_RID: 151843164
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
const int N = 19;
void solve() {
	int n, m, k;
	std :: cin >> n >> m >> k;
	std :: vector <int> a(n);
	for(int &x : a) {
		std :: cin >> x;
	}
	std :: map <int, std :: map <int, int> > mp;
	for(int i = 1; i <= k; ++ i) {
		int u, v, w;
		std :: cin >> u >> v >> w;
		u --; v --;
		mp[u][v] = w;
	}
	std :: vector dp(1 << n, std :: vector <i64> (n));
	for(int i = 0; i < n; ++ i) {
		dp[1<<i][i] = a[i];
	}
	i64 ans = 0;
	for(int _ = 1; _ < 1 << n; ++ _) {
		for(int i = 0; i < n; ++ i) {
			if(!(_ >> i & 1)) {
				continue;
			}
			for(int j = 0; j < n; ++ j) {
				if(!(_ >> j & 1) || i == j) {
					continue;
				}
				// deb(j);
				// deb(i);
				dp[_][i] = std :: max(dp[_][i], dp[_^(1<<i)][j] + a[i] + mp[j][i]);
			}
		}
		int cnt = 0;
		for(int i = 0; i < n; ++ i) {
			if(_ >> i & 1) {
				cnt ++;
			}
		}
		if(cnt == m) {
			for(int i = 0; i < n; ++ i) {
				if(!(_ >> i & 1)) {
					continue;
				}
				ans = std :: max(ans, dp[_][i]);
			}
		}
	}
	std :: cout << ans;
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