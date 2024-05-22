#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const i64 INF = 1e16;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e5 + 20;
int n, a[N];
i64 k, sum[N];
void solve() {
	std :: cin >> n >> k;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	std :: sort(a + 1, a + 1 + n);

	for(int i = 2; i <= n; ++ i)
		sum[i] = sum[i-1] + a[i];

	if(sum[n] + a[1] <= k) {
		std :: cout << 0 << endl;
		return ;
	}
	if(n == 1) {
		std :: cout << (a[1] > k ? (a[1] - k) : 0) << endl;
		return ;
	}

	if(n == 2) {
		if(a[1] * 2 <= k) std :: cout << 1 << endl;
		else std :: cout << std :: min(a[1] + a[2] - k, a[1] - (k >> 1) + 1) << endl;
		return ;
	}

	i64 ans = sum[n] + a[1] - k;
	for(int i = 2; i <= n; ++ i) {
		i64 res = k - sum[i], m = n - i + 1;
		if(res >= 0) {
			if(a[i] <= res / m) ans = std :: min(ans, m-1);
			else ans = std :: min(ans, a[1] - res / m + m - 1);
			continue;
		}
		res = - res;
		ans = std :: min(ans, res/m+1+a[1]+m-1);
	}
	std :: cout << ans << endl;
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