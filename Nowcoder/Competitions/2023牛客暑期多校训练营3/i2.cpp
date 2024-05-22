#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 5e5 + 200;

i64 a[N];
int f[N][22], dep[N], jump[N][22], col[N][60];
std :: vector <int> adj[N];

void dfs(int u, int fa) {
	f[u][0] = fa; dep[u] = dep[fa] + 1;
	int up = -1;
	for(int i = 0; i < 60; ++ i) {
		col[u][i] = col[fa][i];
		if((a[u] >> i & 1) && col[u][i] == -1)
			col[u][i] = u;
		if(~a[u] >> i & 1)
			col[u][i] = -1;
		if(up == -1 || (col[u][i] != -1 && dep[up] > dep[col[u][i]]))
			up = col[u][i];
	}

	jump[u][0] = up;

	for(int i = 1; dep[u] - (1 << i) >= 0; ++ i)
		f[u][i] = f[f[u][i-1]][i-1];
	for(int i = 0; i <= 20; ++ i)
		if(jump[u][i] != -1) {
			jump[u][i+1] = jump[jump[u][i]][i];
		}
	for(auto v : adj[u])
		if(v != fa) dfs(v, u);
}

int query(int x, int y) {
	if(dep[x] < dep[y]) std :: swap(x, y);
	for(int i = 21; i >= 0; -- i)
		if(dep[f[x][i]] >= dep[y]) x = f[x][i];
	if(x == y) return x;
	for(int i = 21; i >= 0; -- i)
		if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}

void solve() {
	int n, q;
	std :: cin >> n >> q;
	memset(col, -1, sizeof col);
	memset(jump, -1, sizeof jump);
	for(int i = 1; i <= n; ++ i) std :: cin >> a[i];
	for(int i = 1; i < n; ++ i) {
		int u, v; std :: cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	auto work = [&](auto self, int x, int y) -> int {
		int L = query(x, y);
		int ans = dep[x] + dep[y] - dep[L] * 2;
		if(x == L) std :: swap(x, y);
		if(x == L) return 0;
		if(y == L) {
			for(int i = 21; i >= 0; -- i)
				if(jump[x][i] != -1 && dep[jump[x][i]] > dep[L]) {
					ans += 1 << i; x = jump[x][i];
					}
			if(a[x] & a[f[x][0]])
				return ans;
			return -1;
		}
		for(int i = 21; i >= 0; -- i)
			if(jump[x][i] != -1 && dep[jump[x][i]] > dep[L])
				ans += 1 << i, x = jump[x][i];
		for(int i = 21; i >= 0; -- i)
			if(jump[y][i] != -1 && dep[jump[y][i]] > dep[L])
				ans += 1 << i, y = jump[y][i];
		if(jump[x][0] == -1 || jump[y][0] == -1) return -1;
		if(dep[jump[x][0]] > dep[L] || dep[jump[y][0]] > dep[L]) return -1;
		bool flag = false;
		for(int i = 0; i < 60; ++ i)
			if(col[x][i] != -1 && col[y][i] != -1) {
				if(dep[col[x][i]] <= dep[L] && dep[col[y][i]] <= dep[L])
					flag = true;
			}
		return ans + (flag != true);
	};
	while(q --) {
		int x, y;
		std :: cin >> x >> y;
		std :: cout << work(work, x, y) << endl;
	}
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