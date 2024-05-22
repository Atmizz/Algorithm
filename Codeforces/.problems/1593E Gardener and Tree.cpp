#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 4e5 + 20;
int head[N], deg[N], sum[N], dis[N], dep[N];
int n, k, cnt;
struct Edge {
	int to, net;
}e[N << 1];

inline void init() {
	cnt = 0;
	std :: fill(head, head + 1 + n, 0);
	std :: fill(deg, deg + 1 + n, 0);
	std :: fill(sum, sum + 1 + n, 0);
	std :: fill(dis, dis + 1 + n, 0);
	std :: fill(dep, dep + 1 + n, 0);
}

inline void Insert(int u, int v) {
	e[++cnt] = {v, head[u]};
	head[u] = cnt;
}

void dfs(int u) {
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(dis[v]) continue;
		dis[v] = dis[u] + 1;
		dfs(v);
	}
}

int calc(int u, int fa) {
	if(deg[u] == 1) {
		dep[u] = 1;
		sum[1] ++;
		return 1;
	}
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(v == fa) continue;
		dep[u] = std :: max(dep[u], calc(v, u) + 1);
	}
	sum[dep[u]] ++;
	return dep[u];
}

void solve() {
	std :: cin >> n >> k; init();
	for(int i = 1; i < n; ++ i) {
		int u, v; std :: cin >> u >> v;
		Insert(u, v); Insert(v, u);
		deg[u] ++; deg[v] ++;
	}

	dis[1] = 1; dfs(1);
	int v, maxx = 0;
	for(int i = 1; i <= n; ++ i)
		if(maxx < dis[i]) maxx = dis[i], v = i;

	std :: fill(dis + 1, dis + 1 + n, 0);
	dis[v] = 1; dfs(v); maxx = 0;
	for(int i = 1; i <= n; ++ i)
		if(maxx < dis[i]) maxx = dis[i], v = i;

	std :: vector <int> L;
	L.push_back(v);
	while(1) {
		bool flag = 0;
		for(int i = head[v]; i; i = e[i].net) {
			int x = e[i].to;
			if(dis[x] == dis[v] - 1) {
				L.push_back(x); v = x; flag = 1;
				break;
			}
		}
		if(!flag) break;
	}

	int m = L.size(), rt = 1, rt1 = 1, rt2 = n;
	if(m & 1) {
		rt = L[m>>1];
		calc(rt, rt);
		if(k >= dep[rt]) {
			std :: cout << 0 << '\n';
			return ;
		}
		for(int i = 1; i <= dep[rt]; ++ i)
			sum[i] = sum[i-1] + sum[i];
		std :: cout << n - sum[k] << '\n';
	} else {
		rt1 = L[(m>>1)-1], rt2 = L[m>>1];
		calc(rt1, rt2); calc(rt2, rt1);
		if(k >= dep[rt1]) {
			std :: cout << "0\n";
			return ;
		}
		for(int i = 1; i <= dep[rt1]; ++ i)
			sum[i] = sum[i-1] + sum[i];
		std :: cout << n - sum[k] << '\n';
	}
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