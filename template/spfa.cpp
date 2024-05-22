#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << endl;
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
typedef unsigned long long ull;
template <class T>
T max(T a, T b) {
	return a > b ? a : b;
}
template <class T>
T min(T a, T b) {
	return a < b ? a : b;
}
template <class T>
T abs(T a) {
	return a < 0 ? -a : a;
}
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 3e3 + 20;
struct spfaAlgorithm {
	struct Edge {
		int to, net;
		i64 dis;
	}e[N<<1];
	int cnt, n, head[N], vis[N], num[N];
	i64 dis[N];
	void init() {
		cnt = 0;
		std :: fill(head + 1, head + 1 + n, 0);
		std :: fill(vis + 1, vis + 1 + n, 0);
		std :: fill(num + 1, num + 1 + n, 0);
	}
	void insert(int u, int v, i64 w) {
		e[++cnt] = {v, head[u], w};
		head[u] = cnt;
	}
	bool HaveNegativeLoop(int st) {
		std :: queue <int> q;
		q.push(st);
		std :: fill(dis + 1, dis + 1 + n, INF);
		vis[st] = 1; dis[st] = 0;
		while((int) q.size()) {
			int u = q.front(); q.pop();
			vis[u] = 0; num[u] ++;
			if(num[u] > n) {
				return true;
			}
			for(int i = head[u]; i; i = e[i].net) {
				int v = e[i].to;
				if(dis[v] > dis[u] + e[i].dis) {
					dis[v] = dis[u] + e[i].dis;
					if(!vis[v]) {
						q.push(v); vis[v] = 1;
					}
				}
			}
		}
		return false;
	}
}SPFA;
void solve() {
	int m = 0;
	std :: cin >> SPFA.n >> m;
	SPFA.init();
	for(int i = 1; i <= m; ++ i) {
		int u, v; i64 w;
		std :: cin >> u >> v >> w;
		SPFA.insert(u, v, w);
		if(w >= 0) {
			SPFA.insert(v, u, w);
		}
	}
	std :: cout << (SPFA.HaveNegativeLoop(1) ? "YES\n" : "NO\n");
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	std :: cin >> _; 
	while(_ --) solve();
	return 0;
}