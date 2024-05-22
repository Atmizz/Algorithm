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
int sum[N];
int calc(double a) {
	if(a - int(a) >= 0.5) {
		return int(a) + 1;
	} 
	return int(a);
}
void solve() {
	std :: string a;
	int n;
	std :: cin >> n >> a;
	a = '0' + a;
	int ans = -INF;
	for(int i = 1; i <= n; ++ i) {
		sum[i] = sum[i-1] + (a[i] == '1');
	}
	for(int i = 0; i <= n; ++ i) {
		int t1 = calc(1.00 * i / 2);
		int t2 = calc(1.00 * (n - i) / 2);
		if(i - sum[i] < t1 || sum[n] - sum[i] < t2) {
			continue;
		}
		if(std :: fabs(1.00 * n / 2 - i) < std :: fabs(1.00 * n / 2 - ans)) {
			ans = i;
		} else if(std :: fabs(1.00 * n / 2 - i) == std :: abs(1.00 * n / 2 - ans)) {
			ans = std :: min(ans, i);
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