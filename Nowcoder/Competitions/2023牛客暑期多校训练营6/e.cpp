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

void solve() {
	int n, q;
	std :: cin >> n >> q;
	std :: vector <i64> a(n+1), sum(n+1);
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	for(int i = 1; i <= n; ++ i) {
		sum[i] = sum[i-1] + a[i];
	}
	while(q --) {
		int l, r, k, cnt = 0;
		std :: cin >> l >> r >> k;
		for(int i = l; i <= r; ++ i)
			if((sum[i] - sum[l-1]) % 2 == 0) cnt ++;
		std :: cout << ((cnt >= k && (sum[r] - sum[l-1]) % 2 == 0) ? "YES\n" : "NO\n");
	}
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