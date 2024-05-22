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

void solve() {
	int n, k, d;
	std :: cin >> n >> k >> d;
	std :: vector dp(101, std :: vector <int> (101));
	for(int i = 1; i <= 100; ++ i) dp[0][i] = 1;
	for(int i = 1; i <= 100; ++ i)
		for(int j = 1; j <= 100; ++ j)
			for(int h = 1; h <= j; ++ h)
				if(i >= h)
					dp[i][j] = (dp[i][j] + dp[i-h][j]) % Mod;
	std :: cout << (dp[n][k] - dp[n][d-1] + Mod) % Mod << endl;
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