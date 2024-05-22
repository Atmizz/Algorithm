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
const int N = 1e5 + 20;
std :: vector <int> adj[N];
std :: vector <int> dis(N);
void solve() {
	int x_0, y_0, x_1, y_1;
	std :: cin >> x_0 >> y_0 >> x_1 >> y_1;
	int n;
	std :: cin >> n;
	std :: map <int, std :: set <int> > line;
	for(int j = 1; j <= n; ++ j) {
		int row, l, r;
		std :: cin >> row >> l >> r;
		for(int i = l; i <= r; ++ i) {
			line[row].insert(i);
		}
	}
	int cnt = 0;
	std :: map <PII, int> mp;
	for(auto &[row, v] : line) {
		int lst = -1;
		for(auto &y : line[row]) {
			if(!mp.count({row, y})) {
				mp[{row, y}] = ++ cnt;
			}
			if(lst != -1) {
				if(lst == y - 1) {
					adj[cnt].pb(mp[{row, lst}]);
					adj[mp[{row, lst}]].pb(cnt);
				}
			}
			if(line.count(row-1)) {
				for(int i = y - 1; i <= y + 1; ++ i) {
					if(line[row-1].find(i) != line[i].end()) {
						adj[cnt].pb(mp[{row-1, i}]);
						adj[mp[{row-1, i}]].pb(cnt);
					}
				}
			}
			lst = y;
		}
	}
	for(int i = 1; i <= cnt; ++ i) {
		dis[i] = INF;
	}
	std :: queue <PII> q;
	q.push({mp[{x_0, y_0}], 0}); dis[mp[{x_0, y_0}]] = 0;
	while(sz(q)) {
		auto [u, step] = q.front(); q.pop();
		if(step != dis[u]) {
			continue ;
		}
		for(auto v : adj[u]) {
			if(dis[v] > step + 1) {
				dis[v] = step + 1;
				q.push({v, step + 1});
			}
		}
	}
	if(dis[mp[{x_1, y_1}]] == INF) {
		std :: cout << -1;
	} else {
		std :: cout << dis[mp[{x_1, y_1}]];
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