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
const int N = 1050;
int n, m, v[N], w[N];
std :: bitset <N> dp[2][N];
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> v[i] >> w[i];
	}
	for(int i = 0; i < 1 << 10; ++ i) {
		dp[0][i] = dp[1][i] = 0;
	}
	dp[0][0][0] = 1;
	for(int i = 1, x = 1; i <= n; ++ i, x ^= 1) {
		for(int j = 0; j < 1 << 10; ++ j) {
			dp[x][j] = (dp[x^1][j^w[i]] << v[i]) | dp[x^1][j];
		} 
	}
	int ans = -1;
	for(int i = 0; i < 1 << 10; ++ i) {
		if(dp[n&1][i][m]) {
			ans = i;
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
	int _ = 1;
	std :: cin >> _; 
	while(_ --) solve();
	return 0;
}