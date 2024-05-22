#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
#define int long long
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 2e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e5 + 20;
int n, m, k, a[N], d[N], f[N];
void solve() {
	std :: cin >> n >> m >> k;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	for(int i = 1; i <= m; ++ i) {
		std :: cin >> d[i];
	}
	for(int i = 1; i <= k; ++ i) {
		std :: cin >> f[i];
	}
	std :: sort(f + 1, f + 1 + k);
	int maxx = 0, mx = 0, l, r;
	for(int i = 2; i <= n; ++ i) {
		if(a[i] - a[i-1] > maxx) {
			mx = maxx;
			maxx = a[i] - a[i-1];
			l = a[i-1], r = a[i];
		} else {
			mx = std :: max(mx, a[i] - a[i-1]);
		}
	} 
	f[k+1] = INF;
	int ans = maxx;
	for(int i = 1; i <= m; ++ i) {
		if(d[i] >= r) continue;
		int pos = std :: lower_bound(f + 1, f + 1 + k, (l + r - d[i] * 2) / 2) - f;
		for(int j = std :: max(1LL, pos - 1); j <= std :: min(k, pos + 1); ++ j) {
			int res = std :: max(d[i] + f[j] - l, r - d[i] - f[j]);
			ans = std :: min(res, ans);
		}
		// deb(d[i]);
		// deb(ans);
	}
	std :: cout << std :: max(ans, mx) << '\n';
}
signed main() {
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