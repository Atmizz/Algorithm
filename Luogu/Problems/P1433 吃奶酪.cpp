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
const int N = 16;
int n;
double dp[1<<N][N], x[N], y[N];
double getDis(double xx, double yx, double xy, double yy) {
	return sqrt((xx - xy) * (xx - xy) + (yx - yy) * (yx - yy));
}
void solve() {
	std :: cin >> n;
	for(int i = 0; i < n; ++ i) {
		std :: cin >> x[i] >> y[i];
	}
	for(int i = 0; i < 1 << n; ++ i) {
		for(int j = 0; j < n; ++ j) {
			dp[i][j] = INF;
		}
	}
	for(int _ = 0; _ < 1 << n; ++ _) {
		for(int i = 0; i < n; ++ i) {
			if((_ >> i) & 1) {
				if((_ & (1 << i)) == _) {
					dp[_][i] = getDis(0, 0, x[i], y[i]);
				} else {
					for(int j = 0; j < n; ++ j) {
						if(j == i || !(_ >> j & 1)) {
							continue;
						}
						dp[_][i] = std :: min(dp[_][i], dp[_-(1<<i)][j] + getDis(x[i], y[i], x[j], y[j]));
					}
				}
			}
		}
	}
	double ans = INF;
	for(int i = 0; i < n; ++ i) {
		ans = std :: min(ans, dp[(1<<n)-1][i]);
	}
	printf("%.2lf", ans);
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	// std :: ios :: sync_with_stdio(false);
	// std :: cin.tie(0);
	// std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}