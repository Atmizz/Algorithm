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
typedef long long i64;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 20;
int f[N], n, m, g[N];
struct Node {
	int w, v;
	friend bool operator < (Node a, Node b) {
		return a.v < b.v;
	}
}t[110];
void solve() {
	while(scanf("%d %d", &n, &m) != EOF) {
		int maxa = 0;
		for(int i = 1; i <= n; ++ i)
			scanf("%d", &t[i].v), maxa = std :: max(maxa, t[i].v);
		for(int i = 1; i <= n; ++ i)
			scanf("%d", &t[i].w);
		int M = maxa * maxa;
		for(int i = 1; i <= M + m; ++ i)
			f[i] = g[i] = INF;

		for(int i = 1; i <= n; ++ i) {
			if(t[i].w * t[i].v >= M + m)
				for(int j = t[i].v; j <= M + m; ++ j)
					f[j] = std :: min(f[j], f[j-t[i].v] + 1);
			else 
				for(int k = 1; t[i].w; k <<= 1) {
					int x = std :: min(k, t[i].w);
					for(int j = M + m; j >= t[i].v * x; -- j)
						f[j] = std :: min(f[j], f[j-t[i].v*x] + x);
					t[i].w -= x;
				}
		}

		for(int i = 1; i <= n; ++ i)
			for(int j = t[i].v; j <= M; ++ j)
				g[j] = std :: min(g[j], g[j-t[i].v] + 1);

		int ans = f[m];
		for(int i = 1; i <= M; ++ i)
			ans = std :: min(ans, f[i+m] + g[i]);
		if(ans == INF)	ans = -1;
		std :: cout << ans << endl;
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