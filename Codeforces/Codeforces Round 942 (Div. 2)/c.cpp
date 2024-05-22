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
	int n;
	i64 k;
	std :: cin >> n >> k;
	std :: vector <i64> a(n+1);
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	auto check = [&](i64 x) -> bool {
		i64 res = 0;
		for(int i = 1; i <= n; ++ i) {
			if(a[i] < x) {
				res += x - a[i];
			}
			if(res > k) {
				return false;
			}
		}
		return true;
	};
	i64 l = 0, r = 1e18, maxx = 0;
	while(l <= r) {
		i64 mid = (l + r) / 2;
		if(check(mid)) {
			l = mid + 1;
			maxx = mid;
		} else {
			r = mid - 1;
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; ++ i) {
		if(maxx > a[i]) {
			k -= maxx - a[i];
		}
		a[i] = max(0LL, a[i] - maxx);
		cnt += (a[i] > 0);
	}
	i64 ans = maxx * n - (n - 1) + cnt + k;
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