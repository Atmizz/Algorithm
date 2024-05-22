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
int n, cnt, head[N], dfn[N], low[N], dnf, bel[N], id, inDeg[N], outDeg[N];
struct Edge {
	int to, net;
}e[N*N];
std :: stack <int> s;
void Insert(int u, int v) {
	e[++cnt].to = v;
	e[cnt].net = head[u];
	head[u] = cnt;
}
namespace TAR {
	struct EDGE {
		int to, net;
	}E[N*N];
	int CNT, HEAD[N];
	bool vis[N];
	void Insert(int u, int v) {
		E[++CNT].to = v;
		E[CNT].net = HEAD[u];
		HEAD[u] = CNT;
	}
	void dfs(int u) {
		vis[u] = 1;
		for(int i = head[u]; i; i = e[i].net) {
			int v = e[i].to;
			if(vis[v]) continue;
			dfs(v);
		}
	}
}
void tarjan(int u) {
	s.push(u); dfn[u] = low[u] = ++ dnf;
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(!dfn[v]) {
			tarjan(v);
			low[u] = std :: min(low[u], low[v]);
		} else if(!bel[v])
			low[u] = std :: min(low[u], dfn[v]);
	}
	if(low[u] == dfn[u]) {
		id ++;
		while(s.size()) {
			int v = s.top(); s.pop();
			bel[v] = id;
			if(v == u) break;
		}
	}
}
void solve() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) {
		int v;
		while(1) {
			scanf("%d", &v);
			if(v == 0) break;
			Insert(i, v);
		}
	}
	for(int i = 1; i <= n; ++ i)
		if(!dfn[i]) tarjan(i);
	for(int u = 1; u <= n; ++ u)
		for(int i = head[u]; i; i = e[i].net) {
			int v = e[i].to;
			if(bel[u] != bel[v])
				TAR :: Insert(bel[u], bel[v]), inDeg[bel[v]] ++, outDeg[bel[u]] ++;
		}
	int ans = 0, p = 0, q = 0;
	for(int i = 1; i <= id; ++ i)
		if(!inDeg[i])
			ans ++;
	for(int i = 1; i <= id; ++ i) {
		if(!inDeg[i]) p ++;
		if(!outDeg[i]) q ++;
	}
	if(id == 1) p = q = 0;
	printf("%d\n%d", ans, std :: max(p, q));
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = 1;
	//scanf("%d", &T); 
	while(T --) solve();
	return 0;
}