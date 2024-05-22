#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;

void solve() {
	int n;
	std :: cin >> n;
	std :: vector <int> a(n+1), b(n+1);
	for(int i = 1; i <= n; ++ i) std :: cin >> a[i];
	for(int i = 1; i <= n; ++ i) b[i] = 1;
	for(int i = 1; i <= n; ++ i) {
		i64 ans = 0;
		for(int j = i; j <= n; ++ j)
			ans = (ans + b[j]) % Mod, std :: cout << j << ' ' << b[j] << endl;
		for(int j = i + 1; j <= n; ++ j)
			b[j] = (b[i] + b[j]) % Mod;
		std :: cout << ans << '\n';
	}
}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}