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
const int N = 1e5 + 20;
struct ZFunction {
	std :: vector <int> run(std :: string &s) {
		int n = sz(s);
		if(s[0] != '_') {
			s = "_" + s;
		}
		std :: vector <int> z(n+1);
		z[1] = n;
		for(int i = 2, l = 0, r = 0; i <= n; ++ i) {
			if(i <= r) {
				z[i] = min(z[i-l+1], r-i+1);
			}
			while(s[z[i]+1] == s[i+z[i]]) {
				z[i] ++;
			}
			if(i + z[i] - 1 > r) {
				l = i;
				r = i + z[i] - 1;
			}
		}
		return z;
	}
}ZFunc;
void solve() {
	std :: string s;
	std :: cin >> s;
	int n = sz(s);
	std :: vector <int> c(n+2);
	std :: vector <int> z = ZFunc.run(s);
	for(int i = 1; i < sz(z); ++ i) {
		c[1] ++;
		c[z[i]+1] --;
	}
	for(int i = 1; i <= n; ++ i) {
		c[i] += c[i-1];
	}
	int ans = 0;
	std :: vector <PII> v;
	for(int i = n; i >= 1; -- i) {
		if(i + z[i] - 1 == n) {
			ans ++;
			v.pb({z[i], c[z[i]]});
		}
	}
	std :: cout << ans << nl;
	for(auto [a, b] : v) {
		std :: cout << a << ' ' << b << nl;
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