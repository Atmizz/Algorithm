#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 40010;
int T, F, TE, FE, S, n, m, cnt, head[N<<1], dis[N][3];
struct Edge {
	int to, net, dis;
	friend bool operator < (Edge a, Edge b) {
		return a.dis > b.dis;
	}
};
void solve() {
	std :: cin >> TE >> FE >> S;
	std :: cin >> T >> F >> n >> m;
	for(int i = 1; i <= m; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		Insert(u, v);
		Insert(v, u);
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