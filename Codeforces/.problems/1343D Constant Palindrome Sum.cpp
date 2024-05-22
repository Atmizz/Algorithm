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
const int N = 2e5 + 20;
int n, k, a[N], diff[N<<1];
void solve() {
	std :: cin >> n >> k;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	for(int i = 2; i <= k << 1; ++ i)
		diff[i] = 0;
	int ans = INF;
	for(int i = 1; i <= n >> 1; ++ i) {
		int x = std :: min(a[i], a[n-i+1]);
		int y = std :: max(a[i], a[n-i+1]);
		// 2 [2, 2k]
		// 1 [x+1, y+k]
		// 0 [x+y,x+y]
		diff[2] += 2; diff[2*k+1] -= 2;
		diff[x+1] -= 1; diff[y+k+1] += 1;
		diff[x+y] -= 1; diff[x+y+1] += 1;
	}
	for(int i = 2; i <= k << 1; ++ i) {
		diff[i] += diff[i-1];
		ans = std :: min(ans, diff[i]);
	}
	std :: cout << ans << endl;
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