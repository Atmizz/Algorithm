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
	std :: vector <int> a(n+1);
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	auto check = [&](int x) -> bool {
		std :: vector <int> b(n+1), sum(n+1);
		for(int i = 1; i <= n; ++ i) {
			b[i] = (a[i] >= x ? 1 : -1);
			sum[i] = sum[i-1] + b[i];
		}
		int minn = 0;
		for(int i = k; i <= n; ++ i) {
			minn = min(minn, sum[i-k]);
			if(sum[i] - minn > 0) {
				return true;
			}
		}
		return false;
	};
	int l = 1, r = n, ans;
	while(l <= r) {
		int mid = l + r >> 1;
		if(check(mid)) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
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
	//std :: cin >> _; 
	while(_ --) solve();
	return 0;
}