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
	int n, m;
	std :: cin >> n >> m;
	std :: vector <int> a;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) {
			a.pb(i+j);
		}
	}
	std :: sort(a.begin(), a.end());
	std :: vector <int> c(sz(a)+1);
	for(int i = 1; i <= m; ++ i) {
		int x, y, r;
		std :: cin >> x >> y >> r;
		int pos1 = std :: lower_bound(a.begin(), a.end(), max(x+y-r, 2)) - a.begin();
		int pos2 = std :: upper_bound(a.begin(), a.end(), min(x+y+r, n*2)) - a.begin();
		deb(a[pos1]);
		deb(a[pos2])
		c[pos1] ++;
		c[pos2] --;
	}
	int ans = 0;
	for(int i = 1; i <= sz(a); ++ i) {
		c[i] += c[i-1];
		deb(a[i]);
		ans += (c[i] & 1);
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
	// std :: cin >> _; 
	while(_ --) solve();
	return 0;
}