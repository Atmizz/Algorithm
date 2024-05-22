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
	int n;
	std :: cin >> n;
	std :: vector <int> a(n+2);
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	a[0] = a[1];
	a[n+1] = a[n];
	auto check = [=](int x, int y, int z) {
		return (x > y && y < z) || (x < y && y > z);
	};
	int sum = 0, ans = INF;
	for(int i = 2; i < n; ++ i) {
		if(check(a[i-1], a[i], a[i+1])) {
			sum ++;
		}
	}
	if(sum == 0) {
		std :: cout << 0 << '\n';
		return ;
	}
	for(int i = 2; i < n; ++ i) {
		ans = std :: min(ans, sum - 
			check(a[i-1], a[i], a[i+1]) -
			check(a[i-2], a[i-1], a[i]) -
			check(a[i], a[i+1], a[i+2]) +
			check(a[i-1], a[i+1], a[i+2]));
		ans = std :: min(ans, sum -
			check(a[i-1], a[i], a[i+1]) -
			check(a[i], a[i+1], a[i+2]) -
			check(a[i-2], a[i-1], a[i]) +
			check(a[i-2], a[i-1], a[i+1]));
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