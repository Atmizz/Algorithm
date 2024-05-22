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
#define DEB std :: cout << "ok" << endl;
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
const int N = 1010;
int dp[N][N][2], sum[N];
int n, v, d[N], w[N];
void solve() {
	while(std :: cin >> n >> v) {
		for(int i = 1; i <= n; ++ i) {
			std :: cin >> d[i] >> w[i];
			sum[i] = sum[i-1] + w[i];
		}
		memset(dp, INF, sizeof dp);
		dp[v][v][0] = dp[v][v][1] = 0;
		for(int len = 2; len <= n; ++ len) {
			for(int i = 1; i <= n; ++ i) {
				int j = i + len - 1;
				if(j > n) {
					break;
				}
				dp[i][j][0] = min(dp[i+1][j][0] + 1LL * (d[i+1] - d[i]) * (sum[n] - sum[j] + sum[i]), 
					dp[i+1][j][1] + 1LL * (d[j] - d[i]) * (sum[n] - sum[j] + sum[i]));
				dp[i][j][1] = min(dp[i][j-1][0] + 1LL * (d[j] - d[i]) * (sum[n] - sum[j-1] + sum[i-1]), 
					dp[i][j-1][1] + 1LL * (d[j] - d[j-1]) * (sum[n] - sum[j-1] + sum[i-1]));
			}
		}
		std :: cout << min(dp[1][n][0], dp[1][n][1]) << nl;
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