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
	int n, k;
	std :: cin >> n >> k;
	std :: vector<int> a(n), b(n);
	for(int i = 0; i < n; ++ i) {
		std :: cin >> a[i];
	}
	for(int &x : b) {
		std :: cin >> x;
	}
	auto check = [&](int x) {
		int res = k;
		for(int i = 0; i < n; ++ i) {
			if(x <= b[i] / a[i]) {
				continue;
			}
			if(res + b[i] < 1LL * x * a[i]) {
				return false;
			} else {
				res -= (1LL * x * a[i] - b[i]);
			}
		}
		return true;
	};
	int l = 0, r = 2e9, ans;
	while(l <= r) {
		i64 mid = (1LL * l + r) >> 1;
		// std :: cout << l << ' ' << r << '\n';
		if(check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	std :: cout << ans;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}