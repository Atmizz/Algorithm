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
const int Mod = 998244353;
// const int N = ;
i64 gcd(i64 a, i64 b) {
	return b ? gcd(b, a % b) : a;
}
i64 quickMi(i64 a, i64 b) {
	i64 sum = 1;
	while(b) {
		if(b & 1LL) {
			sum = sum * a % Mod;
		}
		b >>= 1LL; a = a * a % Mod;
	}
	return sum;
}
void solve() {
	i64 a, b, c, d, x, y;
	std :: cin >> a >> b >> c >> d >> x >> y;
	i64 ans = 1LL;
	i64 g = gcd(x, y);
	for(int i = a; i <= b; ++ i) {
		if(i <= c) {
			ans = ans * quickMi(g, (d - c + 1) * i) % Mod;
		} else if(i >= d) {
			ans = ans * quickMi(g, (c + d) * (d - c + 1) / 2) % Mod;
		} else {
			ans = ans * quickMi(g, c * (i - c + 1)) % Mod * gcd(g, i * (d - i)) % Mod;
		}
		deb(ans);
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