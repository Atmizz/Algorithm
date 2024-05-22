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
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 220;
int n, m, x, flow[N][N], dep[N];
bool dinic() {
	for(int i = 1; i <= n; ++ i)
		dep[i] = 0;
	std :: queue <int> q;
	q.push(1); dep[1] = 1;
	while(q.size()) {
		int u = q.front(); q.pop();
		if(u == n) return 1;
		for(int i = 1; i <= n; ++ i)
			if(dep[i] == 0 && flow[u][i] > 0)
				dep[i] = dep[u] + 1, q.push(i);
	}
	return 0;
}
int dfs(int u, int FLOW) {
	if(u == n) return FLOW;
	int res = FLOW;
	for(int i = 1; i <= n; ++ i) 
		if(dep[i] == dep[u] + 1 && flow[u][i] > 0) {
			int temp = dfs(i, std :: min(FLOW, flow[u][i]));
			FLOW -= temp; flow[u][i] -= temp;
		}
	return res - FLOW;
}
void solve() {
	std :: cin >> n >> m >> x;
	for(int i = 1; i <= m; ++ i) {
		int u, v, w;
		std :: cin >> u >> v >> w;
		flow[u][v] += w;
	}
	int maxflow = 0;
	while(dinic()) maxflow += dfs(1, INF);
	if(maxflow == 0) std :: cout << "Orz Ni Jinan Saint Cow!";
	else std :: cout << maxflow << ' ' << (x / maxflow + ((x % maxflow) ? 1 : 0));
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