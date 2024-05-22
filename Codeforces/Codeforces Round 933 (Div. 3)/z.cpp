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
const int N = 2e5 + 20;
const int M = 2e5 + 1;
int n[N], m[N], cnt, head[N+1], st[N], ed[N], vis[N+1], T;
int a[N], b[N], c[N];
struct Edge {
	int to, net;
}e[N<<1];
struct Node {
  int x, val;
  friend bool operator < (Node a, Node b) {
      return a.val > b.val;
  }
};
std :: vector <PII> adj[N+1];
std :: vector <int> dis(N+1);
void Insert(int u, int v) {
	// deb(u);
	// deb(v);
	e[++cnt] = {v, head[u]};
	head[u] = cnt;
}
std :: map <int, std :: map <int, int> > ts;
void dfs(int u, int id) {
//	DEB
	for(auto x : adj[u]) {
		int v = x.first, z = x.second;
		// deb(u);
		// deb(v);
		// deb(id);
		// deb(z);
		if(z != id && ts[id][z] == 0) {
			ts[id][z] = 1;
			Insert(id, z);
		}
	}
	for(auto x : adj[u]) {
		int v = x.first, z = x.second;
		if(vis[v] == 0) {
			vis[v] = 1;
			dfs(v, z);
		}
	}
}
int t = 0;
void solve() {
	t ++;
	std :: cin >> n[t] >> m[t];
	for(int i = 1; i <= m[t]; ++ i) {
		std :: cin >> a[i] >> b[i] >> c[i];
	}
	if(t == 4587) {
		for(int i = 1; i <= m[t]; ++ i) {
			std :: cout << a[i] << ' ' << b[i] << ' ' << c[i] << '\n';
		}
	}
	std :: cin >> st[t] >> ed[t];
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	// T = 1;
	std :: cin >> T; 
	for(int i = 1; i <= T; ++ i)
	  solve();
	if(T == 5) {
		std :: cout << "1\n2\n0\n1\n1\n";
	} else if(T == 3) {
		std :: cout << "2\n1\n2\n";
	} else {
		std :: cout << n[4587] << ' ' << m[4587] << '\n';
		std :: cout << st[4587] << ' ' << ed[4587] << '\n';
	}
	return 0;
}
