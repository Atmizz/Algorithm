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
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 100;
int n, m, cnt, head[N], vis[N], u[N], v[N];
i64 k, ans = 1e15, w[N];
struct Edge {
	int to, net;
	i64 dis;
}e[N];
void Insert(int u, int v, i64 w) {
	e[++cnt] = {v, head[u], w};
	head[u] = cnt;
}
int pa[N];
int find(int x) {
	return x == pa[x] ? pa[x] : pa[x] = find(pa[x]);
}
void calc() {
	i64 res = 0;
	for(int i = 1; i <= n; ++ i)
		pa[i] = i;
	int cnt = 0;
	for(int i = 1; i <= m; ++ i)
		if(vis[i] == 1) {
			int x = find(u[i]), y = find(v[i]);
			if(x == y) return;
			pa[x] = y; res = (res + w[i]) % k; cnt ++;
		}
	ans = std :: min(ans, res);
}
void dfs(int x, int cnt) {
	if(cnt == n - 1) {
		calc();
		return ;
	}
	for(int i = x + 1; i <= m; ++ i) {
		vis[i] = 1; dfs(i, cnt + 1); vis[i] = 0;
	}
}
void solve() {
	std :: cin >> n >> m >> k;
	for(int i = 1; i <= m; ++ i) {
		std :: cin >> u[i] >> v[i] >> w[i];
		Insert(u[i], v[i], w[i]);
		Insert(v[i], u[i], w[i]);
	}
	for(int i = 1; i <= m; ++ i) {
		vis[i] = 1; dfs(i, 1); vis[i] = 0;
	}
	std :: cout << ans;
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