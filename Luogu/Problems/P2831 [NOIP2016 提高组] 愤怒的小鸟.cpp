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
const int N = 19;
int n, m, dp[1<<N][N][N];
double x[N], y[N], a[N][N], b[N][N];
void solve() {
	std :: cin >> n >> m;
	for(int i = 0; i < n; ++ i) {
		std :: cin >> x[i] >> y[i];
	}
	for(int i = 0; i < n; ++ i) {
		for(int j = i + 1; j < n; ++ j) {
			a[i][j] = a[j][i] = (y[i] / x[i] - y[j] / x[j]) / (x[i] - x[j]);
			b[i][j] = b[j][i] = y[i] / x[i] - a[i][j] * x[i];
		}
	}
	for(int i = 0; i < n; ++ i) {
		dp[1<<i][i][i] = 1;
	}
	for(int i = 0; i < n; ++ i) {
		for(int j = 0; j < n; ++ j) {
			if(i != j) {
				if(a[i][j] < 0) {
					dp[(1<<i)^(1<<j)][i][j] = dp[(1<<i)^(1<<j)][j][i] = 1;
				} else {
					dp[(1<<i)^(1<<j)][i][j] = dp[(1<<i)^(1<<j)][j][i] = 2;
				}
			}
		}
	}
	for(int _ = 5;)
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