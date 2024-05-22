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
const int N = 3e5 + 20;
int n, a[N], k, sum[N];
void solve() {
	std :: cin >> n >> k;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	for(int i = 1; i <= n; ++ i) {
		sum[i] = sum[i-1] + a[i];
	}
	int L = -1, R = -1;
	auto check = [&](int len) {
		for(int i = 1; i <= n; ++ i) {
			int j = i + len - 1;
			if(j > n) {
				return false;
			}
			if(len - (sum[j] - sum[i-1]) <= k) {
				L = i, R = j;
				return true;
			}
		}
		return false;
	};
	int l = 0, r = n, ans;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	std :: cout << ans << '\n';
	for(int i = 1; i <= n; ++ i) {
		if(i >= L && i <= R) {
			std :: cout << 1 << ' ';
		} else {
			std :: cout << a[i] << ' ';
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
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}