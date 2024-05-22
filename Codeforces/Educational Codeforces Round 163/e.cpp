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
	int ans = n / k + (n % k != 0);
	for(int i = 1; i <= n / k; ++ i) {
		for(int j = k / 2 + 1; j <= k; ++ j) {
			std :: cout << (i - 1) * k + j << ' ';
		}
		for(int j = 1; j <= k / 2; ++ j) {
			std :: cout << (i - 1) * k + j << ' ';
		}
	}
	if(n % k) {
		int r = n % k;
		for(int j = r / 2 + 1; j <= r; ++ j) {
			std :: cout << n / k * k + j << ' ';
		}
		for(int j = 1; j <= r / 2; ++ j) {
			std :: cout << n / k * k + j << ' ';
		}
	}
	std :: cout << '\n';
	std :: cout << ans << '\n';
	for(int i = 1; i <= n / k; ++ i) {
		for(int j = 1; j <= k; ++ j) {
			std :: cout << i << ' ';
		}
	}
	if(n % k) {
		for(int i = n / k * k + 1; i <= n; ++ i) {
			std :: cout << n / k + 1 << ' ';
		}
	}
	std :: cout << '\n';
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