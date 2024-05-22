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
const int N = 3e5 + 20;
void solve() {
	int n, k;
	std :: cin >> n >> k;
	std :: vector <int> a(n+1);
	std :: vector <i64> sum(n+1);
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	std :: vector dp(n+1, std :: vector <i64> (k+1));
	for(int i = 1; i <= n; ++ i) {
		for(int len = 1; len <= k + 1; ++ len) {
			for(int j = max(1, i - len + 1); j <= i; ++ j) {
				int h = min(n, j + len - 1);
				i64 res = sum[h] - sum[j-1] - 1LL * (h - j + 1) * a[i];
				if(res < 0) {
					continue ;
				}
				for(int r = 0; r <= k; ++ r) {
					dp[h][r] = max(dp[h][r], dp[j-1][r]);
				}
				for(int r = 0; r <= k - len + 1; ++ r) {
					dp[h][r+len-1] = max(dp[h][r+len-1], dp[j-1][r] + res);
				}
			}
		}
	}
	std :: cout << sum[n] - dp[n][k] << nl;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	std :: cin >> _; 
	while(_ --) solve();
	return 0;
}