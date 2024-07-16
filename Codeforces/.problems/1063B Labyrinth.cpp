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
const int N = 2020;
struct Node {
	int x, y, r, c;
};
int R[N][N], C[N][N];
void solve() {
	int n, m, r, c, x, y;
	std :: cin >> n >> m >> x >> y >> r >> c;
	std :: vector g(n+1, std :: vector <char> (m+1));
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			std :: cin >> g[i][j];
			R[i][j] = C[i][j] = -1;
		}
	}
	std :: queue <Node> q;
	q.push({x, y, r, c});
	R[x][y] = r;
	C[x][y] = c;
	int xx[4] = {1, -1, 0, 0};
	int yy[4] = {0, 0, 1, -1};
	int ans = 0;
	while(sz(q)) {
		auto [sx, sy, sr, sc] = q.front(); q.pop();
		if(sr != R[sx][sy] && sc != C[sx][sy]) {
			continue ;
		}
		// std :: cout << sx << ' ' << sy << ' ' << sr << ' ' << sc << nl;
		if(g[sx][sy] == '.') {
			ans ++;
			// std :: cout << sx << ' ' << sy << ' ' << sr << ' ' << sc << nl;
			g[sx][sy] = '+';
		}
		for(int i = 0; i < 2; ++ i) {
			int dx = sx + xx[i];
			int dy = sy + yy[i];
			if(dx < 1 || dx > n || g[dx][dy] == '*') {
				continue ;
			}
			if(R[dx][dy] >= sr && C[dx][dy] >= sc) {
				continue ;
			}
			q.push({dx, dy, sr, sc});
			R[dx][dy] = sr;
			C[dx][dy] = sc;
		}
		for(int i = 2; i < 4; ++ i) {
			int dx = sx + xx[i];
			int dy = sy + yy[i];
			if(dy < 1 || dy > m || g[dx][dy] == '*') {
				continue ;
			}

			if(i == 2) {
				if(sc > 0) {
					if(R[dx][dy] >= sr && C[dx][dy] >= sc - 1) {
						continue ;
					}
					q.push({dx, dy, sr, sc - 1});
					R[dx][dy] = sr;
					C[dx][dy] = sc - 1;
				}
			} else {
				if(sr > 0) {
					if(R[dx][dy] >= sr - 1 && C[dx][dy] >= sc) {
						continue ;
					}
					q.push({dx, dy, sr - 1, sc});
					R[dx][dy] = sr - 1;
					C[dx][dy] = sc;
				}
			}
		}
	}
	// for(int i = 1; i <= n; ++ i) {
	// 	for(int j = 1; j <= m; ++ j) {
	// 		std :: cout << g[i][j] << " \n"[j == m];
	// 	}
	// }
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