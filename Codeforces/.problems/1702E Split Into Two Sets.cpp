#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e5 + 20;
void solve() {
	int n; std :: cin >> n;
	std :: vector <bool> vis(n+1);
	std :: vector <int> x(n+1), y(n+1), adj[n+1];
	std :: map <int, int> cnt;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> x[i] >> y[i];
	for(int i = 1; i <= n; ++ i) {
		cnt[x[i]] ++; cnt[y[i]] ++;
		if(cnt[x[i]] > 2 || cnt[y[i]] > 2 || x[i] == y[i]) {
			std :: cout << "NO\n";
			return ;
		}
		adj[x[i]].push_back(y[i]);
		adj[y[i]].push_back(x[i]);
	}
	for(int i = 1; i <= n; ++ i) {
		if(vis[i] == 1) continue;
		int num = 0;
		std :: queue <int> q;
		q.push(i); vis[i] = 1;
		while(q.size()) {
			int u = q.front(); num ++; q.pop();
			for(auto v : adj[u])
				if(vis[v] == 0) q.push(v), vis[v] = 1;
		}
		// deb(num);
		if(num & 1) {
			std :: cout << "NO\n";
			return ;
		}
	}
	std :: cout << "YES\n";
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