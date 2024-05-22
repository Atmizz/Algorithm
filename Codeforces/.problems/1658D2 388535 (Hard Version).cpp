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
void solve() {
	int n, l, r, res = 0;
	std :: cin >> l >> r;
	n = r - l + 1;
	std :: vector <int> a(n), b(n);
	for(int i = 0; i < n; ++ i) {
		std :: cin >> a[i];
	}
	for(auto x : a) {
		if(x == 0) {
			std :: cout << r << '\n';
			return ;
		}
	}
	for(int i = 0; i < n; ++ i) {
		b[i] = l + i;
	}
	for(int i = 0; i < 17; ++ i) {
		int cnt0 = 0, cnt1 = 0;
		for(auto x : b) {
			cnt0 += (!((x >> i) & 1));
			cnt1 += ((x >> i) & 1);
		}
		int c0 = 0, c1 = 0;
		for(auto x : a) {
			c0 += (!((x >> i) & 1));
			c1 += ((x >> i) & 1);
		}
		// std :: cout << cnt0 << ' ' << cnt1 << '\n';
		// std :: cout << c0 << ' ' << c1 << '\n';
		if((c1 - c0) * (cnt1 - cnt0) < 0) {
			res += (1 << i);
		}
	}
	std :: cout << res << '\n';
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