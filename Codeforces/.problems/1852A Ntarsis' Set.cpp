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
	int n, k;
	std :: cin >> n >> k;
	std :: vector <i64> a(n);
	for(i64 &x : a) {
		std :: cin >> x;
	}
	if(a[0] != 1) {
		std :: cout << 1 << nl;
		return ;
	}
	long long l = 2, r = 1e11, ans;
	auto check = [&](i64 x) {
		// deb(x);
		for(int i = 1; i <= k; ++ i) {
			if(a.back() < x) {
				x -= n;
				continue ;
			}
			auto pos = std :: lower_bound(a.begin(), a.end(), x);
			if(*pos > x) {
				pos --;
			}
			// std :: cout << x << ' ' << pos << nl;
			x -= (pos - a.begin() + 1);
			if(x <= 0) {
				return false;
			}
		}
		return true;
	};
	while(l <= r) {
		i64 mid = l + r >> 1;
		if(check(mid)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
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