#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
void solve() {
	i64 n, p, l, t;
	std :: cin >> n >> p >> l >> t;
	i64 x = n / 7 + (n % 7 != 0);
	i64 res = (x - (x & 1)) >> 1;
	i64 ans = 0;
	if(res * (t * 2 + l) >= p) {
		// deb(n);
		std :: cout << n - p / (t * 2 + l) - (p % (t * 2 + l) != 0) << '\n';
	} else {
		p -= res * (t * 2 + l);
		if(x & 1) p -= (t + l), res ++;
		if(p <= 0) {
			std :: cout << n - res << '\n';
		} else {
			std :: cout << n - (res + (p / l) + (p % l != 0)) << '\n';
		}
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}