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
	int n;
	std :: cin >> n;
	std :: vector <i64> a(n), cnt(60);
	for(auto &x : a) {
		std :: cin >> x;
		for(int j = 0; j < 60; ++ j) {
			cnt[j] += (x >> j & 1LL);
		}
	}
	i64 ans = 0;
	for(int i = 0; i < n; ++ i) {
		i64 res1 = 0;
		// for(int j = 0; j < n; ++ j) {
		// 	res1 += (a[i] & a[j]);
		// 	res1 %= Mod;
		// }
		for(int j = 0; j < 60; ++ j) {
			if(a[i] >> j & 1LL) {
				res1 = (res1 + ((1LL << j) % Mod) * cnt[j] % Mod) % Mod;
			}
		}
		i64 res2 = 0;
		// for(int j = 0; j < n; ++ j) {
		// 	res2 += (a[i] | a[j]);
		// 	res2 %= Mod;
		// }
		for(int j = 0; j < 60; ++ j) {
			if(a[i] >> j & 1LL) {
				res2 = (res2 + ((1LL << j) % Mod) * n % Mod) % Mod;
			} else {
				res2 = (res2 + ((1LL << j) % Mod) * cnt[j] % Mod) % Mod;
			}
		}
		ans += (res1 * res2 % Mod);
		ans %= Mod;
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