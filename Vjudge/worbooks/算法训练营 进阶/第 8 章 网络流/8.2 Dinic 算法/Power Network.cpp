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
#define DEB std :: cout << "ok" << endl;
typedef long long i64;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 110;
int n, m, np, nc, head[N*N*2+N*4], cnt, dep[N];
struct Node {
	int to, net, flow;
}e[N*N*2+N*4];
void init() {
	cnt = -1;
	memset(head, -1, sizeof head);
}
inline void Insert(int u, int v, int w) {
	e[++cnt].to = v;
	e[cnt].net = head[u];
	e[cnt].flow = w;
	head[u] = cnt;
}
bool dinic(int s, int t) {
	for(int i = s; i <= t; ++ i)
		dep[i] = 0;
	std :: queue <int> q;
	dep[s] = 1; q.push(s);
	while(q.size()) {
		int u = q.front(); q.pop();
		for(int i = head[u]; ~i; i = e[i].net) {
			int v = e[i].to;
			if(dep[v] == 0 && e[i].flow > 0) {
//				deb(u); deb(v); deb(e[i].flow);
				dep[v] = dep[u] + 1; q.push(v);
				if(v == t) return 1;
			}
		}
	}
	return 0;
}
int dfs(int u, int t, int FLOW) {
	if(u == t) return FLOW;
	int res = FLOW;
	for(int i = head[u]; ~i; i = e[i].net) {
		int v = e[i].to;
		if(dep[v] == dep[u] + 1 && e[i].flow > 0) {
			int k = dfs(v, t, std :: min(res, e[i].flow));
			res -= k; e[i].flow -= k; e[i^1].flow += k;
			if(res == 0) break;
		}
	}
	return FLOW - res;
}
void solve() {
	while(~scanf("%d %d %d %d", &n, &np, &nc, &m)) {
		int s = 0, t = n + 1; init();
		for(int i = 1; i <= m; ++ i) {
			int u, v, w; char ch;
			std :: cin >> ch >> u >> ch >> v >> ch >> w;
			u ++; v ++;
			Insert(u, v, w);
			Insert(v, u, 0);
		}
		for(int i = 1; i <= np; ++ i) {
			int u, v; char ch;
			std :: cin >> ch >> u >> ch >> v;
			u ++;
			Insert(s, u, v);
			Insert(u, s, 0);
		}
		for(int i = 1; i <= nc; ++ i) {
			int u, v; char ch;
			std :: cin >> ch >> u >> ch >> v;
			u ++;
			Insert(u, t, v);
			Insert(t, u, 0);
		}
		
		int maxflow = 0;
		while(dinic(s, t)) 
			maxflow += dfs(s, t, INF);
		std :: cout << maxflow << endl;
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
