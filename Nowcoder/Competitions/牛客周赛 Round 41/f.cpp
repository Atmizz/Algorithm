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
std :: vector <int> adj[N], son[N];
void solve() {
	int n, l, r;
	std :: cin >> n >> l >> r;
	std :: string s;
	std :: cin >> s;
	s = '0' + s;
	std :: vector <int> ans(n+1);
	for(int i = 1; i < n; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	std :: vector <int> fa(n+1);
	std :: map <int, int> mp;
	auto dfs = [&](auto dfs, int u, int pa) -> void {
		fa[u] = pa;
		for(auto v : adj[u]) {
			if(v == pa) {
				continue ;
			}
			dfs(dfs, v, u);
		}
	};
	auto dfs1 = [&](auto dfs1, int u, int anc) -> void {
		son[anc].pb(u);
		mp[u] = 1;
		for(auto v : adj[u]) {
			if(v == fa[u] || s[v] == 'R') {
				continue ;
			}
			dfs1(dfs1, v, anc);
		}
	};
	dfs(dfs, 1, 0);
	for(int i = 1; i <= n; ++ i) {
		if(s[i] == 'R') {
			dfs1(dfs1, i, i);
		}
	}
	for(int i = 1; i <= n; ++ i) {
		if(!mp.count(i)) {
			ans[i] = r > -l ? r : l;
		}
		if(s[i] == 'R') {
			if(sz(son[i]) == 1) {
				continue ;
			}
			int cnt = sz(son[i]);
			i64 res = 0;
			for(auto idx : son[i]) {
				if(res > 0) {
					ans[idx] = l;
					res += l;
				} else {
					res += r;
					ans[idx] = r;
				}
			}
			if(res != 0) {
				for(auto idx : son[i]) {
					if(res * ans[idx] > 0) {
						ans[idx] -= res;
						break;
					}
				}
			}
		}
	}
	for(int i = 1; i <= n; ++ i) {
		std :: cout << ans[i] << ' ';
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