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
const int N = 1010;
int n, r, cnt, head[N], dfn[N], low[N], tot, ans, deg[N];
struct Edge {
	int to, net;
}e[N<<1];
void Insert(int u, int v) {
	e[++cnt].to = v;
	e[cnt].net = head[u];
	head[u] = cnt;
}
void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++ tot;
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(v == fa) continue;
		if(!dfn[v]) {
			tarjan(v, u);
			low[u] = std :: min(low[u], low[v]);
		} else
			low[u] = std :: min(low[u], dfn[v]);
	}
}
void solve() {
	scanf("%d %d", &n, &r);
	for(int i = 1; i <= r; ++ i) {
		int u, v;
		scanf("%d %d", &u, &v);
		Insert(u, v); Insert(v, u);
	}
	tarjan(1, 1);
	for(int u = 1; u <= n; ++ u)
		for(int i = head[u]; i; i = e[i].net) {
			int v = e[i].to;
			if(low[u] != low[v]) deg[low[u]] ++;
		}
	for(int i = 1; i <= n; ++ i)
		if(deg[i] == 1) ans ++;
	printf("%d", (ans + 1) >> 1);
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = 1;
	//scanf("%d", &T); 
	while(T --) solve();
	return 0;
}