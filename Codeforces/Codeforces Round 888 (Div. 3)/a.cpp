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
	int n, m, k, H;
	std :: cin >> n >> m >> k >> H;
	int ans = 0;
	for(int i = 1; i <= n; ++ i) {
		int x, t; std :: cin >> x;
		t = std :: abs(x - H);
		if(t == 0) continue;
		if(t % k == 0 && t / k < m) ans ++;
	}
	std :: cout << ans << endl;
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