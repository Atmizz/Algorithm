#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 110;
int dp[N][N][N<<1], n, m;
void solve() {
	std :: cin >> n >> m;
	dp[0][0][2] = 1;
	for(int i = 0; i <= n; ++ i) {
		for(int j = 0; j <= m; ++ j) {
			for(int k = 0; k <= m; ++ k) {
				dp[i+1][j][k*2] = (dp[i+1][j][k*2] + dp[i][j][k]) % Mod;
				if(k > 0) {
					dp[i][j+1][k-1] = (dp[i][j+1][k-1] + dp[i][j][k]) % Mod;
				}
			}
		}
	}
	std :: cout << dp[n][m-1][1];
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