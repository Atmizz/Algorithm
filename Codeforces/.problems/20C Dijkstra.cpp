#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define int long long
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x7f7f7f7f7f7f7f7f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 20;
int n, m, head[N<<1], cnt, dis[N], pre[N];
struct Edge {
	int to, net, dis;
}e[N<<1];
struct Node {
	int x, dis;
	friend bool operator < (Node a, Node b) {
		return a.dis > b.dis;
	}
};
std :: priority_queue <Node> q;
void Insert(int u, int v, int w) {
	e[++cnt] = {v, head[u], w};
	head[u] = cnt;
}
void dijkstra() {
	std :: fill(dis + 2, dis + n + 1, INF);
	q.push({1, 0});
	while(q.size()) {
		int u = q.top().x, d = q.top().dis; q.pop();
		if(d != dis[u]) continue;
		for(int i = head[u]; i; i = e[i].net) {
			int v = e[i].to;
			if(dis[v] > dis[u] + e[i].dis) {
				dis[v] = dis[u] + e[i].dis; pre[v] = u;
				q.push({v, dis[v]});
			}
		}
	}
}
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= m; ++ i) {
		int u, v, w;
		std :: cin >> u >> v >> w;
		Insert(u, v, w);
		Insert(v, u, w);
	}
	dijkstra();
	if(pre[n] == 0) std :: cout << -1;
	else {
		int x = n;
		std :: vector <int> ans;
		while(x) {
			ans.push_back(x);
			x = pre[x];
		}
		for(int i = ans.size() - 1; i >= 0; -- i)
			std :: cout << ans[i] << ' ';
	}
}

signed main() {
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