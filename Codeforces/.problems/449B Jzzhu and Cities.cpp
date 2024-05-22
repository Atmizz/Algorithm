#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define sz(x) (int)x.size()
#define mk std :: make_pair
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << '\n';
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
const int N = 4e5 + 20;
int n, m, k;
struct DijsktraAlgorithm {
	struct Node {
		int x;
		i64 dis;
		friend bool operator < (Node a, Node b) {
			return a.dis > b.dis;
		}
	};
	std :: vector <PIL> adj[N];
	i64 dis[N];
	inline void insert(int u, int v, i64 w) {
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}
	void Dijsktra(int st) {
		for(int i = 1; i <= n; ++ i) {
			dis[i] = LLONG_MAX / 2;
		}
		std :: priority_queue <Node> q;
		dis[st] = 0; q.push({st, 0});
		while((int) q.size()) {
			auto [u, d] = q.top(); q.pop();
			if(d != dis[u]) {
				continue ;
			}
			for(auto [v, w] : adj[u]) {
				if(dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
					q.push({v, dis[v]});
				}
			}
		}
	}
	int check(int s, int w) {
		int cnt = 0;
		std :: priority_queue <Node> q;
		// std :: cout << w << " " << dis[s] << nl;
		if(w < dis[s]) {
			cnt ++;
			dis[s] = w;
		}
		q.push({s, w});
		while((int) q.size()) {
			auto [u, d] = q.top(); q.pop();
			if(d != dis[u]) {
				continue ;
			}
			for(auto [v, w] : adj[u]) {
				if(dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
					q.push({v, dis[v]});
					cnt ++;
				}
			}
		}
		if(cnt > 0) {
			adj[1].pb({s, w});
			adj[s].pb({1, w});
		}
		return cnt;
	}
}Dij;
void solve() {
	std :: cin >> n >> m >> k;
	for(int i = 1; i <= m; ++ i) {
		int u, v, w;
		std :: cin >> u >> v >> w;
		Dij.insert(u, v, w);
		Dij.insert(v, u, w);
	}
	Dij.Dijsktra(1);
	int ans = 0;
	std :: map <int, i64> route;
	for(int i = 1; i <= k; ++ i) {
		int v; i64 w;
		std :: cin >> v >> w;
		if(!route.count(v)) {
			route[v] = w;
		} else {
			route[v] = min(route[v], w);
			ans ++;
		}
	}
	std :: vector <PIL> rt;
	for(auto [v, w] : route) {
		rt.pb({v, w});
	}
	std :: sort(rt.begin(), rt.end(), [&](PIL a, PIL b){
		return a.second < b.second;
	});
	for(auto [v, w] : rt) {
		// std :: cout << v << ' ' << w << ' ' << Dij.dis[v] << nl;
		if(w > Dij.dis[v]) {
			ans ++;
			continue ;
		}
		if(Dij.check(v, w) == 0) {
			ans ++;
		}
	}
	std :: cout << ans;
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