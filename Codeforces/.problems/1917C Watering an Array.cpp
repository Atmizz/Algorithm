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
const int Mod = 1e9 + 7;
const int N = 2020;
const int M = 1e5 + 20;
int n, k, d, a[N], b[M];
void solve() {
	std :: cin >> n >> k >> d;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	for(int i = 1; i <= k; ++ i) {
		std :: cin >> b[i];
	}
	int ans = 0;
	for(int i = 0; i <= std :: min(d-1, n*2); ++ i) {
		int cnt = 0;
		for(int j = 1; j <= n; ++ j) {
			cnt += (a[j] == j);
		}
		ans = std :: max(ans, cnt + (d - i - 1) / 2);
		for(int j = 1; j <= b[i%k+1]; ++ j) {
			a[j] ++;
		}
	}
	std :: cout << ans << '\n';
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