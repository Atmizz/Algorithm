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
const int N = 3e5 + 20;
int n, m, cnt, head[N], dfn[N], dnf, low[N], val[N], bel[N], id, num[N];
i64 fee;
struct Edge {
	int to, net;
}e[N<<4];
std :: stack <int> s;
void Insert(int u, int v) {
	e[++cnt] = {v, head[u]};
	head[u] = cnt;
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
		id ++; int minn = INF;
		std :: vector <int> res;
		while(s.size()) {
			int v = s.top(); s.pop();
			bel[v] = id; res.push_back(val[v]);
			minn = std :: min(minn, val[v]);
			if(v == u) break;
		}
		for(auto x : res)
			if(x == minn) num[id] ++;
		fee += minn;
	}
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> val[i];
	std :: cin >> m;
	for(int i = 1; i <= m; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		Insert(u, v);
	}
	for(int i = 1; i <= n; ++ i)
		if(!dfn[i]) tarjan(i);
	i64 ans = 1;
	for(int i = 1; i <= id; ++ i)
		ans = ans * num[i] % Mod;
	std :: cout << fee << ' ' << ans;
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