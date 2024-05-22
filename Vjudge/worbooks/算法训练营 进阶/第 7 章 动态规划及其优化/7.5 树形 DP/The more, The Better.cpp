#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 220;
int dp[N][N], sz[N], val[N];
std :: vector <int> e[N];
void dfs(int u, int m) {
	// deb(u);
	dp[u][1] = val[u];
	for(int v : e[u]) {
		dfs(v, m-1);
		for(int j = m; j > 1; -- j)
			for(int k = 0; k < j; ++ k)
				dp[u][j] = std :: max(dp[u][j], dp[u][j-k] + dp[v][k]);
	}
}
void solve() {
	int n, m;
	while(1) {
		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0) return ;
		memset(dp, 0, sizeof dp);
		for(int i = 0; i <= n; ++ i)
			e[i].clear();
		for(int i = 1; i <= n; ++ i) {
			int a, b; scanf("%d %d", &a, &b);
			val[i] = b;
			e[a].push_back(i);
		}
		 dfs(0, m + 1);
		std :: cout << dp[0][m+1] << endl;
	}
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