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
const int N = 2e5 + 10;
i64 gcd(i64 a, i64 b) {
	return b ? gcd(b, a % b) : a;
}
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <i64> a(n), b(n+1);
	for(int i = 0; i < n; ++ i) std :: cin >> a[i];
	for(int i = n - 1; i >= 0; -- i)
		b[i] = gcd(b[i+1], a[i]);
	i64 ans = 0;
	for(int i = 0; i <= n - 1; ++ i)
		ans = gcd(ans, a[i] * b[i+1]);
	std :: cout << ans / b[0] << endl;
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