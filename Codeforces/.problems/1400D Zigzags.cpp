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
const int N = 3030;
int n, a[N], cnt[N][N];
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	i64 ans = 0;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) {
			cnt[i][j] = cnt[i-1][j];
		}
		cnt[i][a[i]] ++;
	}
	for(int j = 2; j < n; ++ j) {
		for(int k = j + 1; k < n; ++ k) {
			ans += cnt[j-1][a[k]] * (cnt[n][a[j]] - cnt[k][a[j]]);
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