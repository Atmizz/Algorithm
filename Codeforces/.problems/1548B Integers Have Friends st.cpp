/*

复习ST表 - 可以处理静态数组

- 预处理 O(nlogn)
f[i][j] = op(f[i][j-1], f[i+(1<<j-1)][j-])

- 查询 O(1)
[l, r]
__lg(r - l + 1) = k;
op(f[l][k], f[r-(1<<k)+1][k])

*/

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
const int N = 2e5 + 20;
int n;
i64 a[N], b[N], f[N][20];
i64 gcd(i64 a, i64 b) {
	return !b ? a : gcd(b, a % b);
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	for(int i = 1; i < n; ++ i) {
		b[i] = std :: abs(a[i+1] - a[i]);
	}
	int m = n - 1;
	for(int i = 1; i <= m; ++ i) {
		f[i][0] = b[i];
	}
	for(int j = 1; j < 20; ++ j) {
		for(int i = 1; i + (1 << j) - 1 <= m; ++ i) {
			f[i][j] = gcd(f[i][j-1], f[i+(1<<j-1)][j-1]);
		}
	}
	auto check = [=](int len) -> bool {
		int k = std :: __lg(len);
		// deb(len);
		// deb(k)
		for(int i = 1; i <= m; ++ i) {
			int j = i + len - 1;
			if(j > m) {
				break;
			}
			if(gcd(f[i][k], f[j-(1<<k)+1][k]) > 1) {
				return true;
			}
		}
		return false;
	};
	int l = 1, r = m, ans = 1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		// std :: cout << l << ' ' << r << '\n';
		if(check(mid)) {
			ans = mid + 1;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	std :: cout << ans << '\n';
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