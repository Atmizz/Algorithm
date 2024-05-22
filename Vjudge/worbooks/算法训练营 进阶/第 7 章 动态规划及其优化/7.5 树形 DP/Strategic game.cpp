#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <stack>
#include <cmath>
#include <bitset>
#include <complex>
#include <cstdlib>
#include <set>
#include <cstring>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
typedef long long i64;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1550;
int n, dp[N][2];
std :: vector <int> e[N];
void dfs(int u, int fa) {
	dp[u][0] = 0; dp[u][1] = 1;
	for(int i = 0; i < e[u].size(); ++ i) {
		int v = e[u][i];
		if(v == fa) continue;
		dfs(v, u);
		dp[u][0] += dp[v][1];
		dp[u][1] += std :: min(dp[v][1], dp[v][0]);
	}
}
void solve() {
	while(~scanf("%d", &n)) {
		for(int i = 0; i < n; ++ i)
			e[i].clear();
		for(int i = 0; i < n; ++ i) {
			int u, m;
			scanf("%d:(%d)", &u, &m);
			for(int j = 1; j <= m; ++ j) {
				int v; scanf("%d", &v);
				e[u].push_back(v);
				e[v].push_back(u);
			}
		}
		dfs(0, 0);
		printf("%d\n", std :: min(dp[0][0], dp[0][1]));
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = 1;
	//scanf("%d", &T); 
	while(T --) solve();
	return 0;
}
