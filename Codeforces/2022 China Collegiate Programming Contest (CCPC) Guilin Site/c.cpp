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
const int N = 1e5 + 20;
i64 n, m, sum[N];
i64 quickMi(i64 a, i64 b) {
	i64 res = 1;
	while(b) {
		if(b & 1) res = res * a % Mod;
		a = a * a % Mod; b >>= 1;
	} return res;
}
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		int a; std :: cin >> a;
		sum[i] = (sum[i-1] + a) % Mod;
	}
	i64 ans1 = (sum[n] * quickMi(2, m-1) % Mod) * (n * quickMi(2, m) % Mod + 1) % Mod;
	i64 ans2 = 0, res = sum[n], x = n;
	for(int i = 1; i <= n; ++ i)
		ans2 = (ans2 + sum[i]) % Mod;
	for(int i = 1; i <= m; ++ i) {
		ans2 = (ans2 * 2 % Mod + res * x % Mod) % Mod;
		res = res * 2 % Mod; x = x * 2 % Mod;
	}
	std :: cout << std :: max(ans1, ans2);
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