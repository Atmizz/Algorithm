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
const int N = 1010;
int pa[N], sz[N];
int find(int x) {
	return x == pa[x] ? pa[x] : pa[x] = find(pa[x]);
}
void unite(int u, int v) {
	if(sz[u] > sz[v]) std :: swap(u, v);
	pa[u] = v; sz[v] += sz[u];
}
void solve() {
	while(1) {
		int n, m;
		std :: cin >> n;
		if(n == 0) return ;
		std :: cin >> m;
		int k = 0;
		for(int i = 1; i <= n; ++ i) pa[i] = i, sz[i] = 1;
		 for(int i = 1; i <= m; ++ i) {
		 	int u, v;
		 	std :: cin >> u >> v;
		 	u = find(u), v = find(v);
		 	if(u == v) continue;
		 	unite(u, v); k ++;
			if(k == n - 1) continue;
		 }
		std :: cout << n - 1 - k << endl;
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