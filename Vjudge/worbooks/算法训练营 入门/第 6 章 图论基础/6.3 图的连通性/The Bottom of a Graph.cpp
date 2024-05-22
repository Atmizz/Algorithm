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
const int N = 5050;
int n, m, head[N], cnt, dfn[N], low[N], dnf, id, bel[N], deg[N];
std :: vector <int> ans;
std :: stack <int> s;
struct Edge {
	int to, net;
}e[N*N];
void Insert(int u, int v) {
	e[++cnt].to = v;
	e[cnt].net = head[u];
	head[u] = cnt;
}
void init() {
	ans.clear();
	cnt = 0; id = 0; dnf = 0;
	for(int i = 0; i <= n; ++ i)
		head[i] = dfn[i] = low[i] = bel[i] = deg[i] = 0;
}
void tarjan(int u) {
	s.push(u); dfn[u] = low[u] = ++ dnf;
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(!dfn[v]) {
			tarjan(v);
			low[u] = std :: min(low[u], low[v]);
		} else if(!bel[v]) low[u] = std :: min(low[u], dfn[v]);
	}
	int num = 0;
	if(dfn[u] == low[u]) {
		id ++;
		while(!s.empty()) {
			int v = s.top(); s.pop();
			bel[v] = id;
			if(u == v) break;
		}
	}
}
void solve() {
	while(1) {
		scanf("%d", &n);
		if(n == 0) return ;
		scanf("%d", &m); init();
		for(int i = 1; i <= m; ++ i) {
			int u, v; scanf("%d %d", &u, &v);
			Insert(u, v);
		}
		for(int i = 1; i <= n; ++ i)
			if(!dfn[i]) tarjan(i);
		for(int u = 1; u <= n; ++ u)
			for(int i = head[u]; i; i = e[i].net) {
				int v = e[i].to;
				if(bel[u] != bel[v]) deg[bel[u]] ++;
			}
		for(int i = 1; i <= n; ++ i)
			if(deg[bel[i]] == 0)
				ans.push_back(i);
		std :: sort(ans.begin(), ans.end());
		if(!ans.empty())
			for(int i = 0; i < ans.size(); ++ i)
				printf("%d ", ans[i]);
		puts("");
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