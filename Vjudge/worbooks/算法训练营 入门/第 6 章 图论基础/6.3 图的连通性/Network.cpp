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
int n, m, head[N], cnt, dfn[N], low[N], tot, num;
bool st[N];
struct Edge {
	int to, net;
}e[N<<5];
void Insert(int u, int v) {
	e[++cnt].to = v;
	e[cnt].net = head[u];
	head[u] = cnt;
}
void init() {
	cnt = 0; tot = 0; num = 0;
	for(int i = 0; i <= n; ++ i)
		head[i] = 0;
	for(int i = 1; i <= n; ++ i)
		st[i] = dfn[i] = low[i] = 0;
}
void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++ tot;
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(v == fa) continue;
		if(!dfn[v]) {
			tarjan(v, u);
			low[u] = std :: min(low[u], low[v]);
			if(u == 1) num ++;
			else if(low[v] >= dfn[u])
				st[u] = 1;
		} else low[u] = std :: min(low[u], dfn[v]);
	}
}
void solve() {
	while(1) {
		scanf("%d", &n);
		if(n == 0) return ;
		init();
		while(1) {
			scanf("%d", &m);
			if(m == 0) break;
			while(getchar() != '\n') {
				int u; scanf("%d", &u);
				Insert(m, u); Insert(u, m);
			}
		}
		tarjan(1, 1);
		int ans = 0;
		if(num > 1) ans ++;
		for(int i = 1; i <= n; ++ i)
			if(st[i]) ans ++;
		printf("%d\n", ans);
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