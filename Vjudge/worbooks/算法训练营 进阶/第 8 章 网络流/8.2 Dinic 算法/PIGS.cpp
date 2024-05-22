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
const int N = 1120;
int n, m, val[N], cnt, dep[120], flow[120][120];
bool dinic(int s, int t) {
	for(int i = 0; i <= n + 1; ++ i)
		dep[i] = 0;
	std :: queue <int> q;
	dep[s] = 1; q.push(s);
	while(q.size()) {
		int u = q.front(); q.pop();
		// deb(u);
		for(int v = 1; v <= n + 1; ++ v) {
			if(dep[v] != 0 || flow[u][v] == 0) continue;
			dep[v] = dep[u] + 1; q.push(v);
			if(v == t) return 1;
		}
	}
	return 0;
}
int dfs(int u, int FLOW) {
	if(u == n + 1) return FLOW;
	int res = FLOW;
	for(int v = 1; v <= n + 1; ++ v) {
		if(dep[v] != dep[u] + 1 || flow[u][v] == 0) continue;
		int k = dfs(v, std :: min(FLOW, flow[u][v]));
		FLOW -= k; flow[u][v] -= k; flow[v][u] += k;
		if(!FLOW) break;
	}
	return res - FLOW;
}
void solve() {
	scanf("%d %d", &m, &n);
	for(int i = 1; i <= m; ++ i)
		scanf("%d", &val[i]);
	for(int i = 1; i <= n; ++ i) {
		int x, y, z; scanf("%d", &x);
		for(int j = 1; j <= x; ++ j) {
			scanf("%d", &y);
			// deb(i); deb(y); deb(val[y]);
			if(val[y] > 0) flow[0][i] += val[y], val[y] = -i;
			else if(val[y] < 0) flow[-val[y]][i] = INF;
		}
		scanf("%d", &z);
		flow[i][n+1] = z;
	}
	int maxflow = 0;
	while(dinic(0, n+1))
		maxflow += dfs(0, INF);
	printf("%d", maxflow);
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = 1;
	//scanf("%d", &T); 
	while(T --) solve();
	return 0;
}