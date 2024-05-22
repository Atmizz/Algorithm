#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
i64 gcd(i64 a, i64 b) {
	return b == 0 ? a : gcd(b, a % b);
}
void solve() {
	int n, m;
	std :: cin >> n >> m;
	std :: vector <i64> a(n), b(m);
	for(int i = 0; i < n; ++ i)
		std :: cin >> a[i];
	for(int i = 0; i < m; ++ i)
		std :: cin >> b[i];
	std :: sort(a.begin(), a.end());
	i64 g = 0;
	for(int i = 1; i < n; ++ i)
		g = gcd(g, a[i] - a[i-1]);
	for(int i = 0; i < m; ++ i)
		std :: cout << gcd(a[0] + b[i], g) << ' ';
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