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
const int N = 410;
char g[N][N];
int n, m;
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			std :: cin >> g[i][j];
		}
	}
	int ans = INF;
	for(int i = 1; i <= n; ++ i) {
		if(i + 4 > n) {
			break;
		}
		for(int j = 1; j <= m; ++ j) {
			if(j + 3 > m) {
				break;
			}
			int cnt = 0;
			for(int k = j + 1; k < j + 3; ++ k) {
				cnt += g[i][k] != '1';
			}
			for(int k = j + 1; k < j + 3; ++ k) {
				cnt += g[i+4][k] != '1';
			}
			for(int k = i + 1; k < i + 4; ++ k) {
				cnt += g[k][j] != '1';
			}
			for(int k = i + 1; k < i + 4; ++ k) {
				cnt += g[k][j+3] != '1';
			}
			for(int k = i + 1; k < i + 4; ++ k) {
				for(int h = j + 1; h < j + 3; ++ h) {
					cnt += g[k][h] != '0';
				}
			}
			ans = std :: min(ans, cnt);
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