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
	i64 n, p, w, d;
	std :: cin >> n >> p >> w >> d;
	// x + y <= n
	// wx + dy = p
	// wx + wd - wd + dy = p
	// w(x + d) + d(y - w) = p
	// w(x + kd) + d(y - kw) = p
	// y - kw < w
	// x' = x + kd, y' = y - kw
	// wx' + dy' = p (y' < w)
	for(i64 y = 0; y < w; ++ y) {
		if((p - d * y) % w == 0 && p >= d * y) {
			i64 x = (p - d * y) / w;
			if(x + y <= n) {
				std :: cout << x << ' ' << y << ' ' << n - x - y << nl;
				return ;
			}
		}
	}
	std :: cout << -1;
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