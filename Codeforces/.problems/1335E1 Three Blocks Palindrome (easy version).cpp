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
int n, a[N], sum[N][27];
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		for(int j = 1; j <= 26; ++ j) {
			sum[i][j] = sum[i-1][j];
		}
		sum[i][a[i]] ++;
	}
	int ans = 1;
	for(int i = 1; i <= n; ++ i) {
		for(int j = i + 1; j <= n; ++ j) {
			if(a[i] != a[j]) {
				continue ;
			}
			int x = a[i];
			if(sum[i][x] != sum[n][x] - sum[j-1][x]) {
				continue;
			}
			for(int k = 1; k <= 26; ++ k) {
				ans = std :: max(ans, sum[i][x] + sum[n][x] - sum[j-1][x] + sum[j-1][k] - sum[i][k]);
			}
			// std :: cout << i << ' ' << j  << ' ' << ans << '\n';
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