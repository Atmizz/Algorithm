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
const int N = 1e5 + 20;
int pa[N*3], n, m, ans;
// 1~N 本体 N+1~2N 食物 2N+1~3N 天敌
int find(int x) {
	return x == pa[x] ? pa[x] : pa[x] = find(pa[x]);
}
void unite(int x, int y) {
	pa[y] = x;
}
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= n * 3; ++ i) pa[i] = i;
	while(m --) {
		int opt, x, y;
		std :: cin >> opt >> x >> y;
		if(x > n || y > n) {
			ans ++; continue;
		}
		if(opt == 1) {
			 int x1 = find(x), x2 = find(x+n), x3 = find(x+n*2);
			 int y1 = find(y), y2 = find(y+n), y3 = find(y+n*2);
			 if(x1 == y2 || x2 == y1) {
			 	ans ++; continue;
			 }
			 unite(x1, y1); unite(x2, y2); unite(x3, y3);
		} else {
			int x1 = find(x), x2 = find(x+n), x3 = find(x+n*2);
			int y1 = find(y), y2 = find(y+n), y3 = find(y+n*2);
			if(x1 == y1 || y2 == x1) {
				ans ++; continue;
			}
			unite(x2, y1); unite(x3, y2); unite(x1, y3);
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
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}