#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e5 + 200;
int m[N], dp[N];
void solve() {
	int n;
	memset(m, 0, sizeof m);
	memset(dp, 0, sizeof dp);
	std :: cin >> n;
	std :: vector <int> a(n);
	for(int i = 0; i < n; ++ i) std :: cin >> a[i], m[a[i]] ++;
	std :: sort(a.begin(), a.end());
	int len = std :: unique(a.begin(), a.end()) - a.begin();
	for(int i = 0; i < len; ++ i)
		dp[a[i]] = m[a[i]];
	for(int i = len - 1; i >= 0; -- i) {
		for(int j = 1; j <= sqrt(a[i]); ++ j)
			if(a[i] % j == 0 && a[i] != j) {
				// deb(j); deb(dp[j]); deb(dp[a[i]] + m[j]);
				dp[j] = std :: max(dp[j], dp[a[i]] + m[j]);
				if(j * j != a[i] && j != 1) {
					int x = a[i] / j;
					dp[x] = std :: max(dp[x], dp[a[i]] + m[x]);
				}
			}
	}
	int ans = 0;
	for(int i = 0; i < len; ++ i)
		ans = std :: max(ans, dp[a[i]]);
	std :: cout << n - ans << endl;
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