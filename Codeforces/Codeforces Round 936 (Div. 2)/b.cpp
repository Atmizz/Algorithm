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
const i64 Mod = 1e9 + 7;
const int N = 2e5 + 20;
i64 n, k, a[N];
i64 qm(i64 b) {
	i64 a = 2, res = 1;
	while(b) {
		if(b & 1) {
			res = res * a % Mod;
		}
		b >>= 1; a = a * a % Mod;
	}
	return res % Mod;
}
void solve() {
	std :: cin >> n >> k;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	i64 maxSum = 0, res = 0;
	for(int i = 1; i <= n; ++ i) {
		res += a[i];
		maxSum = std :: max(res, maxSum);
		if(res < 0) {
			res = 0;
		}
	}
	maxSum %= Mod;
	i64 ans = 0;
	for(int i = 1; i <= n; ++ i) {
		ans = (ans + a[i] + Mod) % Mod;
	}
	ans = (ans - maxSum + Mod) % Mod;
	ans = (ans + qm(k) * maxSum % Mod + Mod) % Mod;
	std :: cout << (ans + Mod) % Mod<< '\n';
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