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
const int N = 1e5 + 20;
int dp[N], n, t;
std :: vector <int> e[N];
void dfs(int u) {
	if(!e[u].size()) {
		dp[u] = 1;
		return ;
	}
	int m = std :: ceil(e[u].size() * 1.00 * t / 100);
	// deb(m);
	std :: priority_queue<int, std :: vector <int>, std :: greater <int> > q;
	for(int v : e[u]) dfs(v);
	for(int v : e[u]) q.push(dp[v]);
	for(int i = 1; i <= m; ++ i)
		dp[u] += q.top(), q.pop();
}
void solve() {
	while(1) {
		std :: cin >> n >> t;
		if(n == 0) return ;
		for(int i = 0; i <= n; ++ i)
			e[i].clear();
		for(int i = 0; i <= n; ++ i)
			dp[i] = 0;
		for(int i = 1; i <= n; ++ i) {
			int x; std :: cin >> x;
			e[x].push_back(i);
		}
		dfs(0);
		std :: cout << dp[0] << endl;
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