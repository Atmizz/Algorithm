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
void solve() {
	int n, k;
	std :: cin >> n >> k;
	int ok = 1, pos = -1;
	for(int i = 31; i >= 0; -- i) {
		if(k >> i & 1) {
			if(ok == 1) {
				ok = 0;
			}
			if(pos == -1) {
				pos = i;
			}
		} else {
			if(ok == 0) {
				ok = -1;
			}
		}
	}
	if(ok == 1 || n == 1) {
		std :: cout << k << ' ';
		for(int i = 1; i < n; ++ i) {
			std :: cout << 0 << ' ';
		}
		std :: cout << nl;
		return ;
	}
	int a = (1 << pos) - 1;
	std :: cout << a << ' ' << k - a << ' ';
	// std :: cout << (a | (k - a)) << ' ' << (3 | 1 | 1 | 32 | 2 | 12) << nl;
	// char s[10], t[10];
	// itoa((a | (k - a)), s, 2);
	// itoa((3 | 1 | 1 | 32 | 2 | 12), t, 2);
	// printf("%s %s\n", s, t);
	for(int i = 1; i <= n - 2; ++ i) {
		std :: cout << 0 << ' ';
	}
	std :: cout << nl;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	// std :: ios :: sync_with_stdio(false);
	// std :: cin.tie(0);
	// std :: cout.tie(0);
	int _ = 1;
	std :: cin >> _; 
	while(_ --) solve();
	return 0;
}