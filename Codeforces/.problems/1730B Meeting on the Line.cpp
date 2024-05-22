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
const double Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 20;
int n;
double a[N], t[N], ans;
bool check(double x) {
	double l = 0, r = Range;
	for(int i = 1; i <= n; ++ i) {
		if(x <= t[i]) {
			l = std :: max(l, a[i]);
			r = std :: min(r, a[i]);
		} else {
			l = std :: max(l, a[i] - (x - t[i]));
			r = std :: min(r, a[i] + (x - t[i]));
		}
	}
	ans = l;
	return l <= r;
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	for(int i = 1; i <= n; ++ i)
		std :: cin >> t[i];
	double l = 0, r = Range;
	while(r - l >= eps) {
		double mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid;
	}
	printf("%.10lf\n", ans);
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