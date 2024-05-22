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
const int Mod = 998244353;
const int N = 220;
std :: mt19937 rd(114514);
int n, m, dp[N][N][N];
// dp[i][j][k]
// 表示第 i 条线段时，第 j 条线段右端点之前都覆盖 2 次，第 k 条线段右端点
// 前都至少覆盖一次的方案数。
// 最终答案就是都覆盖至少两次的方案总数。
void solve() {
	std :: cin >> n >> m;
	std :: vector <PII> line(m+1);
	for(int i = 1; i <= m; ++ i) {
		auto &[l, r] = line[i];
		std :: cin >> l >> r;
	}
	std :: sort(line.begin(), line.end());
	dp[0][0][0] = 1;
	for(int i = 1; i <= m; ++ i) {
		for(int j = 0; j < i; ++ j) {
			for(int k = 0; k < i; ++ k) {
				dp[i][j][k] += dp[i-1][j][k];
				dp[i][j][k] %= Mod;
				if(line[i].first <= line[j].second + 1) {
					if(line[i].second < line[j].second) {
						dp[i][j][k] += dp[i-1][j][k];
						dp[i][j][k] %= Mod;
					} else {
						if(line[i].second < line[k].second) {
							dp[i][i][k] += dp[i-1][j][k];
							dp[i][i][k] %= Mod;
						} else {
							dp[i][k][i] += dp[i-1][j][k];
							dp[i][k][i] %= Mod;
						}
					}
				}
			}
		}
	}
	i64 ans = 0;
	for(int i = 1; i <= m; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			if(line[i].second >= n) {
				ans += dp[m][i][j];
				ans %= Mod;
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