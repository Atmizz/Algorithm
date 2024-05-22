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
const int N = 4e5 + 20;
i64 p[N];
i64 quickPower(i64 a, i64 b) {
	i64 sum = 1;
	while(b) {
		if(b & 1) {
			sum = sum * a % Mod;
		}
		a = a * a % Mod;
		b >>= 1;
	}
	return sum;
}
void solve() {
	std :: string s;
	std :: cin >> s;
	s = '0' + s + s;
	std :: map <char, int> val;
	val['a'] = 1;
	val['e'] = 2;
	val['h'] = 3;
	val['n'] = 4;
	i64 ans = 0;
	int n = sz(s) / 2;
	i64 R = 1;
	i64 q = quickPower(31, Mod - 2);
	q = quickPower(q, n - 1);
	p[0] = 1;
	for(int i = 1; i <= n; ++ i) {
		p[i] = p[i-1] * 31 % Mod;
	}
	i64 res = 0;
	for(int i = 1; i <= n << 1; ++ i) {
		if(i <= n) {
			res = res * 31 + val[s[i]];
		} else {
			res = (res - p[n-1] * val[s[i-n]] % Mod + Mod) % Mod * 31 % Mod + val[s[i]];
		}
		if(i >= n) {
			ans = max(ans, res);
		}
		// std :: cout << i << ' ' << i + n - 1 << nl;
		// std :: cout << n - i << nl;
		// deb((sum[i+n-1] - sum[i-1] + Mod) * q[n-i] % Mod)
		// std :: string r = s.substr(i, 5);
		// std :: cout << r << '\n';
		// i64 z = 0;
		// for(int j = 0; j <= 4; ++ j) {
		// 	z = (z * 31 % Mod + val[r[j]]) % Mod;
		// }
		// deb(z);
		// ans = max(ans, (sum[i+n-1] - sum[i-1] + Mod) % Mod * q[n-i] % Mod);
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