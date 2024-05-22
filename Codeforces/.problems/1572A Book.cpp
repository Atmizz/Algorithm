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
// const int N = ;
std :: mt19937 rd(114514);
void solve() {
	int n, cnt = 0, ans = 0;
	std :: cin >> n;
	std :: vector <int> adj[n+1], in(n+1), jda[n+1];
	for(int i = 1; i <= n; ++ i) {
		int k;
		std :: cin >> k;
		for(int j = 1; j <= k; ++ j) {
			int x;
			std :: cin >> x;
			adj[x].push_back(i);
			jda[i].push_back(x);
			in[i] ++;
		}
	}
	std :: queue <int> q;
	std :: vector <int> dp(n+1);
	for(int i = 1; i <= n; ++ i) {
		if(!in[i]) {
			dp[i] = 1;
			q.push(i);
		}
	}
	while(q.size()) {
		cnt ++;
		int u = q.front(); q.pop();
		for(auto v : adj[u]) {
			in[v] --;
			dp[v] = std :: max(dp[v], dp[u] + (u > v));
			if(in[v] == 0) {
				q.push(v);
			}
		}
	}
	for(int i = 1; i <= n; ++ i) {
		// std :: cout << i << ' ' << dp[i] << '\n';
		ans = std :: max(dp[i], ans);
	}
	if(cnt < n) {
		std :: cout << -1 << '\n';
		return ;
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