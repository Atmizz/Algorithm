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
const int N = 110;
int n, m, g[N], num[1200];
int dp[N][600][600];
/*
dp_ijk 表示第i行j状态，上一行状态为k时的最大阵地数。
*/
void solve() {
	std :: cin >> n >> m;
	// 预处理出地形状态
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			char x; std :: cin >> x;
			if(x == 'P') {
				g[i] += 1 << j - 1;
			}
		}
	}
	// 预处理出每一个状态的所需阵地数
	for(int i = 0; i < 1 << m; ++ i) {
		if((i << 1 & i) || (i << 2 & i)) {
			continue;
		}
		int cnt = 0;
		for(int j = 0; j < m; ++ j) {
			cnt += i >> j & 1;
		}
		num[i] = cnt;
	}
	// 预处理出每行的所有状态（结合地形）
	std :: vector <int> st[n+1];
	st[0].push_back(0);
	for(int i = 1; i <= n; ++ i) {
		for(int j = 0; j < 1 << m; ++ j) {
			if((j << 1 & j) || (j << 2 & j) || ((j & g[i]) != j)) {
				continue;
			}
			st[i].push_back(j);
		}
	}
	// 预处理第一行。
	for(int s : st[1]) {
		dp[1][s][0] = num[s];
	}
	// 开始dp
	for(int i = 2; i <= n; ++ i) {
		for(int s : st[i]) {
			for(int t : st[i-1]) {
				if(s & t) {
					continue;
				}
				for(int r : st[i-2]) {
					if((t & r) || (r & s)) {
						continue;
					}
					dp[i][s][t] = std :: max(dp[i][s][t], dp[i-1][t][r] + num[s]);
				}
			}
		}
	}
	int ans = 0;
	for(auto s : st[n]) {
		for(auto t : st[n-1]) {
			ans = std :: max(ans, dp[n][s][t]);
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