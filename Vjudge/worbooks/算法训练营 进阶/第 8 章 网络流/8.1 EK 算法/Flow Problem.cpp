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
int n, m, pre[20];
int flow[220][220];
bool vis[20];
bool bfs(int s, int t) {
	for(int i = 0; i <= n; ++ i)
		vis[i] = 0;
	std :: queue <int> q;
	vis[s] = 1; q.push(s);
	while(q.size()) {
		int u = q.front(); q.pop();
		for(int i = 1; i <= n; ++ i) {
			if(vis[i] == 1 || flow[u][i] == 0) continue;
			if(flow[u][i] > 0) {
				vis[i] = 1; pre[i] = u; q.push(i);
				if(i == t) return 1;
			}
		}
	}
	return 0;
}
int ttt;
void solve() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= n; ++ j)
			flow[i][j] = 0;
	for(int i = 1; i <= m; ++ i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		flow[u][v] += w;
	}
	
	int maxflow = 0;
	int s = 1, t = n;
	
	while(bfs(s, t)) {
		int d = INF, v = t;
		while(v != s) {
			int i = pre[v];
			d = std :: min(d, flow[i][v]);
			v = i;
		}
		v = t;
		maxflow += d;
		while(v != s) {
			int i = pre[v];
			flow[i][v] -= d;
			flow[v][i] += d;
			v = i;
		}
	}
	std :: cout << "Case " << ++ttt << ": " << maxflow << endl;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = 1;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}
