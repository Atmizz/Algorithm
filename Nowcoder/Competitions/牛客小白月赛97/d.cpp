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
const int N = 15;
int a[N][N], b[N][N];
int n, m, p;
int mp[11][11][10001];
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};
void solve() {
	std :: cin >> n >> m >> p;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			std :: cin >> a[i][j];
			a[i][j] %= (p - 1);
		}
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			std :: cin >> b[i][j];
		}
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			for(int k = 0; k <= p; ++ k) {
				mp[i][j][k] = -1;
			}
		}
	}
	std :: queue < std :: array <int, 4> > q;
	q.push({1, 1, a[1][1], 0});
	while(sz(q)) {
		auto [x, y, val, step] = q.front(); q.pop();
		if(x == n && y == m && val == 0) {
			std :: cout << step << nl;
			return ;
		}
		for(int i = 0; i < 4; ++ i) {
			int dx = x + xx[i];
			int dy = y + yy[i];
			int t = (val + a[dx][dy]) % (p - 1);
			if(dx < 1 || dx > n || dy < 1 || dy > m) {
				continue ;
			}
			if(mp[dx][dy][t] == -1 || step + 1 < mp[dx][dy][t]) {
				q.push({dx, dy, t, step + 1});
				mp[dx][dy][t] = step + 1;
			}
		}
	}
	std :: cout << -1;
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