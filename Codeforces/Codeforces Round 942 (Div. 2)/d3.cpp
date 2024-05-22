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
#define DEB std :: cout << "ok" << std :: endl;
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
i64 gcd(i64 a, i64 b) {
	return b ? gcd(b, a % b) : a;
}
void solve() {
	int n, m;
	std :: cin >> n >> m;
	i64 ans = 0;
	for(int g = 1; g <= min(n, m); ++ g) {
		int cnt = 0;
		for(int k = 1; k < g; ++ k) {
			int Gcd = gcd(g, g - k);
			if(k / Gcd * g > m || k / Gcd * g > n) {
				continue ;
			}
			if(1LL * g * (g - k) <= 1LL * n * k && g * (g - k) / k >= g) {
				ans ++;
				cnt ++;
				if(g == 7) {
					std :: cout << (g * (g - k) / k) << nl;
					std :: cout << k << '\n';
				}
			}
		}
		std :: cout << g << ' ' << cnt << nl;
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