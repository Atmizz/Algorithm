#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <stack>
#include <cmath>
#include <bitset>
#include <complex>
#include <cstdlib>
#include <set>
#include <cstring>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
typedef long long i64;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 110;
int n, m, k, match[N];
std :: vector <int> adj[N];
bool vis[N];
bool Xyl(int u) {
	for(int i = 0; i < adj[u].size(); ++ i) {
		int v = adj[u][i];
		if(!vis[v]) {
			vis[v] = 1;
			if(!match[v] || Xyl(match[v])) {
				match[v] = u;
				return true;
			}
		}
	}
	return false;
}
void solve() {
	while(1) {
		scanf("%d", &n);
		if(n == 0) return ;
		scanf("%d %d", &m, &k);
		for(int i = 1; i <= m; ++ i)
			match[i] = 0;
		for(int i = 1; i <= n; ++ i)
			adj[i].clear();
		for(int i = 1; i <= k; ++ i) {
			int u, v, w;
			scanf("%d %d %d", &w, &u, &v);
			u ++; v ++;
			if(u == 1 || v == 1) continue;
			adj[u].push_back(v);
		}
		int ans = 0;
		for(int i = 1; i <= n; ++ i) {
			for(int j = 1; j <= m; ++ j)
				vis[j] = 0;
			if(Xyl(i)) ans ++;
		}
		printf("%d\n", ans);
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = 1;
	//scanf("%d", &T); 
	while(T --) solve();
	return 0;
}