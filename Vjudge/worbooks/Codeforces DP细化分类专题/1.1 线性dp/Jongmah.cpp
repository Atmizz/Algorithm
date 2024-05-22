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
const int N = 1e6 + 20;

int dp[N][3][3][3];
void solve() {
	int n, m;
	std :: cin >> n >> m;
	std :: vector <int> cnt(N);
	for(int i = 0, x; i < n; ++ i)
		std :: cin >> x, cnt[x] ++;
	for(int i = 1; i <= m; ++ i)
		for(int j = 0; j < 3; ++ j)
			for(int k = 0; k < 3; ++ k)
				for(int l = 0; l < 3; ++ l) {
					if(cnt[i] < j + k + l) continue;
					for(int h = 0; h < 3; ++ h)
						dp[i][j][k][l] = std :: max(dp[i][j][k][l], dp[i-1][k][l][h] + j + (cnt[i] - j - k - l) / 3);
				}
	std :: cout << *std :: max_element(dp[m][0][0], dp[m][0][0] + 3);
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