#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 550;
int a[N][N], n, m, cnt;
i64 sum[N][N], K;
void solve() {
	std :: cin >> n >> m >> K;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			std :: cin >> a[i][j];
			sum[i][j] = sum[i-1][j] + a[i][j];
			// std :: cout << sum[i][j] << " \n"[j == m];
		}
	}
	i64 ans = 0;
	for(int i = 1; i <= n; ++ i) {
		for(int j = i; j <= n; ++ j) {
			i64 res = 0;
			for(int l = 1, r = 1; r <= m; ++ r) {
				res += sum[j][r] - sum[i-1][r];
				while(l <= r && res > K) {
					res -= sum[j][l] - sum[i-1][l];
					l ++;
				}
				ans += r - l + 1;
			}
		}
	}
	std :: cout << ans;
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