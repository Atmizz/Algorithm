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
	i64 a, b, c, k;
	std :: cin >> a >> b >> c >> k;
	if(a == k || b == k || c == k) {
		std :: cout << 0 << nl;
		return ;
	}
	if(k > 2) {
		std :: cout << -1 << nl;
		return ;
	}
	if(k == 0) {
		std :: cout << 1 << nl;
	} else if(k == 1) {
		if(a == 0 || b == 0 || c == 0) {
			std :: cout << 1 << nl;
		} else {
			std :: cout << 2 << nl;
		}
	} else {
		if(a == 0 || b == 0 || c == 0) {
			if(a == 1 || b == 1 || c == 1) {
				std :: cout << 1 << nl;
			} else {
				std :: cout << 2 << nl;
			}
		} else if(a == 1 || b == 1 || c == 1) {
			std :: cout << 2 << nl;
		}else {
			std :: cout << 3 << nl;
		}
	}
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