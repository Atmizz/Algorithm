#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e7 + 20;
i64 sum[N<<1], a[N<<1], n, k;
i64 quickMi(i64 a, i64 b) {
	i64 res = 1;
	while(b) {
		if(b & 1) res = res * a % Mod;
		a = a * a % Mod; b >>= 1;
	} return res % Mod;
}
void solve() {
	std :: cin >> n >> k;
	for(int i = 1; i <= n << 1; ++ i)
		a[i] = quickMi(i, k) % Mod;
	for(int i = 1; i <= n << 1; ++ i)
		sum[i] = (sum[i-1] + a[i]) % Mod;
	i64 ans = 0;
	for(int i = 1; i <= n; ++ i)
		ans = (ans + sum[i+n] - sum[i] + Mod) % Mod;
	std :: cout << ans;
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