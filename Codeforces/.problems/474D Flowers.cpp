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
const int N = 1e5 + 200;
void solve() {
	int t, k;
	std :: cin >> t >> k;
	std :: vector <i64> f(N), sum(N);
	f[0] = 1; sum[0] = 1;
	for(int i = 1; i < N; ++ i) {
		if(i >= k) f[i] = (f[i-1] + f[i-k]) % Mod;
		else f[i] = f[i-1] % Mod;
		sum[i] = (sum[i-1] + f[i]) % Mod;
	}
	while(t --) {
		int l, r;
		std :: cin >> l >> r;
		std :: cout << (sum[r] - sum[l-1] + Mod) % Mod << endl;
	}
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