#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pr pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;

void solve() {
	int n, m;
	std :: cin >> n >> m;
	std :: vector <std :: vector <int> > adj(n);
	std :: vector <int> deg(n);
	for(int i = 1; i <= m; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		u --, v --;
		deg[v] ++;
		adj[u].push_back(v);
	}
	std :: vector <int> q;
	for(int i = 0; i < n; ++ i)
		if(!deg[i]) q.push_back(i);
	for(int i = 0; i < q.size(); ++ i) {
		int u = q[i];
		for(auto v : adj[u])
			if(!--deg[v]) q.push_back(v);
	}
	if(q.size() == n) {
		std :: cout << 1 << endl;
		for(int i = 0; i < n; ++ i)
			std :: cout << q[i] + 1 << " \n"[i == n - 1];
		return ;
	}
	std :: cout << 2 << endl;
	for(int i = 1; i <= n; ++ i)
		std :: cout << i << " \n"[i == n];
	for(int i = n; i >= 1; -- i)
		std :: cout << i << " \n"[i == 1];
}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}