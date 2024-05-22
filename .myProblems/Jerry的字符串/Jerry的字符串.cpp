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
const int N = 1010;
int dp[N][N], n;
std :: string str;
void solve() {
	std :: cin >> str;
	n = str.length();
	str = "0" + str;
	for(int i = 1; i <= n; ++ i) {
		dp[i][i] = 1;
	}
	for(int len = 2; len <= n; ++ len) {
		for(int i = 1; i <= n; ++ i) {
			int j = i + len - 1;
			if(j > n) {
				break;
			}
			if(str[i] == str[j]) {
				dp[i][j] = dp[i+1][j-1] + 2;
			} else {
				dp[i][j] = std :: max(dp[i+1][j], dp[i][j-1]);
			}
		}
	}
	std :: cout << dp[1][n];
}
int main() {
	// freopen("10.in", "r", stdin);
	// freopen("10.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}