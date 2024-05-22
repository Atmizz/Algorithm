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
const int N = 1e5 + 20;
struct DijsktraAlgorithm {
	struct Node {
		int x;
		i64 dis;
		friend bool operator < (Node a, Node b) {
			return a.dis > b.dis;
		}
	};
	struct Edge {
		int to, net;
		i64 dis;
	}e[N<<1];
	i64 dis[N];
	int cnt, head[N];
	inline void insert(int u, int v, i64 w) {
		e[++cnt] = {v, head[u], w};
		head[u] = cnt;
	}
	void Dijsktra(int st) {
		memset(dis, 0x3f, sizeof dis);
		std :: priority_queue <Node> q;
		dis[st] = 0; q.push({st, 0});
		while((int) q.size()) {
			auto [u, d] = q.top(); q.pop();
			if(d != dis[u]) {
				continue ;
			}
			for(int i = head[u]; i; i = e[i].net) {
				int v = e[i].to;
				if(dis[v] > dis[u] + e[i].dis) {
					dis[v] = dis[u] + e[i].dis;
					q.push({v, dis[v]});
				}
			}
		}
	}
}Dij;
void solve() {
	int n, m, st;
	std :: cin >> n >> m >> st;
	for(int i = 1; i <= m; ++ i) {
		int u, v; i64 w;
		std :: cin >> u >> v >> w;
		Dij.insert(u, v, w);
	}
	Dij.Dijsktra(st);
	for(int i = 1; i <= n; ++ i) {
		std :: cout << Dij.dis[i] << ' ';
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	//std :: cin >> _; 
	while(_ --) solve();
	return 0;
}