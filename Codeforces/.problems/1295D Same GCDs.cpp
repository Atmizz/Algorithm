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
// const int N = ;
i64 gcd(i64 a, i64 b) {
	return !b ? a : gcd(b, a % b);
}
void solve() {
	i64 a, m;
	std :: cin >> a >> m;
	i64 d = gcd(a, m);
	std :: vector <i64> dvd;
	i64 t = m / d;
	for(i64 i = 2; i * i <= t; ++ i) {
		if(t % i == 0) {
			dvd.pb(i);
			while(t % i == 0) {
				t /= i;
			}
		}
	}
	if(t > 1) {
		dvd.pb(t);
	}
	i64 ans = (a + m - 1) / d - (a - 1) / d;
	// deb(ans);
	int n = sz(dvd);
	if(n == 0) {
		// gcd(m, m) !
		std :: cout << ans - 1 << nl;
		return ;
	}
	for(int _ = 1; _ < 1 << n; ++ _) {
		int cnt = 0;
		i64 res = 1;
		for(int i = 0; i < n; ++ i) {
			if(_ >> i & 1) {
				cnt ++;
				res *= dvd[i];
			}
		}
		i64 temp = (a + m - 1) / res / d - (a - 1) / res / d;
		ans -= ((cnt & 1) ? temp : (-1LL * temp));
		// std :: cout << cnt << ' ' << res << ' ' << temp << nl;
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