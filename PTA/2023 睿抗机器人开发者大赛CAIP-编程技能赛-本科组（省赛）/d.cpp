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
const int N = 2e3 + 20;
std :: vector <int> adj[N*2+1];
void solve() {
	int n, cnt = 0;
	std :: cin >> n;
	int m = n * 2;
	std :: map <std :: string, int> mp;
	std :: map <int, std :: string> pm;
	for(int i = 1; i <= n; ++ i) {
		std :: string s1, s2;
		char a1, a2;
		std :: cin >> s1 >> a1 >> s2 >> a2;
		if(!mp.count(s1)) {
			mp[s1] = ++ cnt;
			pm[cnt] = s1;
		}
		if(!mp.count(s2)) {
			mp[s2] = ++ cnt;
			pm[cnt] = s2;
		}
		adj[mp[s1]+(a1-48)*m].pb(mp[s2]+(a2-48)*m);
	}
	std :: stack <std :: string> st;
	int num = INT_MAX, res = INT_MAX;
	std :: vector <int> pre(m*2+1);
	auto dfs = [&](auto dfs, int ori, int u, int step) -> int {
		if(abs(ori - u) == m) {
			res = min(res, step);
			return 1;
		}
		for(auto &v : adj[u]) {
			if(dfs(dfs, ori, v, step + 1) == 1) {
				pre[v] = u;
				return 1;
			}
		}
		return 0;
	};
	std :: string start, end;
	for(int i = 1; i <= m * 2; ++ i) {
		if(sz(adj[i])) {
			pre[i] = 0;
			pre[0] = -1;
			res = INT_MAX;
			int r = dfs(dfs, i, i, 1);
			// std :: cout << i << ' ' << r << nl;
			if(r == 1) {
				if(res < num) {
					num = res;
					while(sz(st)) st.pop();
					int u = i <= m ? i + m : i - m;
					int resu = u;
					while(pre[u] != -1) {
						int v = u > m ? u - m : u;
						std :: string l = pm[v] + " " + (u <= m ? "0" : "1");
						if(abs(v - i) != 0 && abs(v - i) != m) {
							st.push(l);
						}
						if(resu == u) {
							end = l;
						}
						if(i == u) {
							start = l;
						}
						st.push(l);
						u = pre[u];
					}
				}
			}
		}
	}
	while(sz(st)) {
		std :: cout << st.top() << ' ';
		st.pop();
	}
	std :: cout << "= " << start << ' ' << end;
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