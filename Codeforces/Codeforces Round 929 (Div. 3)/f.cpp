#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
int get(int a, int b) {
	a %= b;
	while(a <= 0) {
		a += b;
	}
	return a;
}
struct Node {
	int x, y, t;
};
void solve() {
	int n, m;
	std :: cin >> n >> m;
	std :: vector g(n + 1, std :: vector <int> (m+1));
	std :: vector vis(n + 1, std :: vector <int> (m+1));
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			std :: cin >> g[i][j];
		}
	}
	std :: queue < Node > q;
	q.push({1, 1, 0});
	vis[1][1] = 1;
	while(q.size()) {
		auto [x, y, t] = q.front();
		// std :: cout << x << ' ' << y << '\n';
		q.pop();
		if(y == m) {
			// deb(t);
			int pos = get(t, n);
			std :: cout << t + std :: min(std :: abs(x - get(t, n)),
				std :: min(std :: abs(x + n - pos), std :: abs(n - x + pos))) << '\n';
			return ;
		}
		int dx = get(x + 2, n);
		if(g[get(x+1, n)][y] == 0 && g[dx][y] == 0 && vis[dx][y] == 0) {
			// DEB
			q.push({dx, y, t + 1});
			vis[dx][y] = 1;
		}
		dx = get(x + 1, n); 
		int dy = y + 1;
		// deb(dx); deb(dy);
		if(dy <= m && g[dx][dy] == 0 && vis[dx][dy] == 0) {
			q.push({dx, dy, t + 1});
			vis[dx][dy] = 1;
		}
	}
	std :: cout << -1 << '\n';
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}