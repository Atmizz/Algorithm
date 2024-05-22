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
const int N = 5010;
int dp[N][N];

void solve() {
	std :: string s1, s2;
	std :: cin >> s1; s2 = s1;
	int n, q;
	n = s1.size();
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= i; ++ j)
			if(s1.substr(j-1, i-1) == s2.substr(n - j, n - i))
				dp[i][j] = 1;
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= n; ++ j)
			dp[i][j] += dp[i][j-1];
	std :: cin >> q;
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