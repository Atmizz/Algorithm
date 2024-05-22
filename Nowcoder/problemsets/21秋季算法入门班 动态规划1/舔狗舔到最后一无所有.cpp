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
const int N = 1e5 + 20;
i64 dp[N][3][3];
// dp[i][j][k] 表示i天吃j且昨天吃k
// dp[i][j][k] = \sigma dp[i-1][0..2][0..2(j!=)]
void pre() {
	for(int i = 0; i < 3; ++ i) {
		for(int j = 0; j < 3; ++ j) {
			dp[2][i][j] = 1;
		}
	}
	for(int i = 3; i < N; ++ i) {
		for(int j = 0; j < 3; ++ j) {
			for(int k = 0; k < 3; ++ k) {
				for(int h = 0; h < 3; ++ h) {
					if(j == k && k == h) {
						continue ;
					}
					dp[i][j][k] = (dp[i][j][k] + dp[i-1][k][h]) % Mod;
				}
			}
		}
	}
}
void solve() {
	int n;
	std :: cin >> n;
	if(n == 1) {
		std :: cout << 3 << nl;
		return ;
	}
	i64 ans = 0;
	for(int i = 0; i < 3; ++ i) {
		for(int j = 0; j < 3; ++ j) {
			ans = (ans + dp[n][i][j]) % Mod;
		}
	}
	std :: cout << ans << nl;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1; pre();
	std :: cin >> _; 
	while(_ --) solve();
	return 0;
}