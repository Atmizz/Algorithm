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
#define DEB std :: cout << "ok" << '\n';
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
// const int N = ;
void solve() {
	int n; i64 x;
	std :: cin >> n >> x;
	std :: vector <i64> d(n*2+1), sum(n*2+1), pre(n*2+1);
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> d[i];
		d[i+n] = d[i];
	}
	int m = n << 1;
	for(int i = 1; i <= m; ++ i) {
		pre[i] = pre[i-1] + d[i];
		sum[i] = sum[i-1] + d[i] * (d[i] + 1) / 2;
		// std :: cout << d[i] << " \n"[i == m];
	}
	i64 ans = 0;
	for(int i = 1; i <= m; ++ i) {
		if(pre[i] < x) {
			continue ;
		}
		int pos = std :: lower_bound(pre.begin(), pre.end(), pre[i] - x) - pre.begin();
		i64 res = d[pos] - (x - pre[i] + pre[pos]) + 1;
		i64 tmp = res == 0 ? 0 : (res + d[pos]) * (d[pos] - res + 1) / 2;
		ans = max(ans, tmp + sum[i] - sum[pos]);
		// std :: cout << i << ' ' << pos << ' ' << res << nl;
		// std :: cout << i << ' ' << ans << nl;
	}
	std :: cout << ans;
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