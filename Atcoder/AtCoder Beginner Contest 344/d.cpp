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
const int N = 110;
int n, dp[N][N];
std :: string t;
void solve() {
	std :: cin >> t;
	for(int i = 0; i < N; ++ i) {
		for(int j = 0; j < N; ++ j) {
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		int x;
		std :: cin >> x;
		for(int j = 1; j <= x; ++ j) {
			std :: string s;
			std :: cin >> s;
			for(int k = 0; k < t.size(); ++ k) {
				bool flag = 1;
				for(int h = 0; h < s.size(); ++ h) {
					if(t[k+h] != s[h]) {
						flag = 0;
						break;
					}
				}
				for(int h = 0; h < i; ++ h) {
					if(k > 0 && dp[k-1][h] && flag) {
						dp[k+s.size()-1][i] = std :: min(dp[k-1][h] + 1, dp[k+s.size()-1][i]);
					} else if(k == 0 && flag) {
						dp[k+s.size()-1][i] = 1;
					}
				}
			}
		}
	}
	int ans = INF;
	for(int i = 1; i <= n; ++ i) {
		ans = std :: min(ans, dp[t.size()-1][i]);
	}
	std :: cout << (ans != INF ? ans : -1);
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