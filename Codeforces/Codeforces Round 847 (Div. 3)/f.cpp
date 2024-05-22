#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x7f7f7f7f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e5 + 20;
int n, c[N], head[N], cnt, dis[N], minn;
struct Edge {
	int to, net;
}e[N<<1];
void Insert(int u, int v) {
	e[++cnt] = {v, head[u]};
	head[u] = cnt;
}
void BFS(int x) {
	std :: queue <int> q;
	q.push(x); dis[x] = 0;
	while(q.size()) {
		int u = q.front(); q.pop();
		if(dis[u] >= minn) break;
		for(int i = head[u]; i; i = e[i].net) {
			int v = e[i].to;
			if(dis[v] <= dis[u] + 1) continue;
			dis[v] = dis[u] + 1;
			q.push(v);
		}
	}
}
void init() {
	cnt = 0; minn = n;
	memset(head, 0, sizeof head);
	std :: fill(dis + 1, dis + 1 + n, n + 1);
}
void solve() {
	std :: cin >> n >> c[1]; init();
	for(int i = 2; i <= n; ++ i)
		std :: cin >> c[i];

	for(int i = 1; i < n; ++ i) {
		int u, v; std :: cin >> u >> v;
		Insert(u, v); Insert(v, u);
	}

	BFS(c[1]);

	for(int i = 2; i <= n; ++ i) {
		minn = std :: min(minn, dis[c[i]]);
		BFS(c[i]);
		std :: cout << minn << ' ';
	}
	std :: cout << "\n";
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}
