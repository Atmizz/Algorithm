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
const int N = 11;
int n, k;
i64 dp[N][1<<N][1<<N], num[1<<N], m, st[1<<N];
// dp_i,j,k
// 表示第i行j这个状态而且用了k个国王的方案数
void solve() {
	std :: cin >> n >> k;
	for(int i = 0; i < 1 << n; ++ i) {
		if((i & i << 1) || (i & i >> 1)) {
			continue;
		}
		int cnt = 0;
		st[++m] = i;
		for(int j = 0; j < n; ++ j) {
			cnt += i >> j & 1;
		}
		num[m] = cnt;
	}
	// deb(m);
	for(int i = 1; i <= m; ++ i) {
		dp[1][i][num[i]] = 1;
	}
	for(int i = 2; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			for(int h = 1; h <= m; ++ h) {
				if((st[j] >> 1 & st[h]) || (st[j] << 1 & st[h]) || (st[j] & st[h])) {
					continue;
				}
				for(int o = k; o >= num[j]; -- o) {
					dp[i][j][o] += dp[i-1][h][o-num[j]];
				}
			}
		}
	}
	i64 ans = 0;
	for(int i = 1; i <= m; ++ i) {
		ans += dp[n][i][k];
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