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
const int N = 1010;
int n, m, q, deg[N][N][4];
int ans[N][N][4];
// 表示i，j这个位置射出的方向
char g[N][N];
// 0上 1下 2左 3右
int xx[4] = {-1, 1, 0, 0};
int yy[4] = {0, 0, -1, 1};
void dfs(int i, int j, int k, int st) {
	if(i < 1 || i > n || j < 1 || j > m) {
		return ;
	}
	ans[i][j][k] = st;
	char ch = g[i][j];
	if(ch == '-') {
		if(k == 0) {
			dfs(i - 1, j, 1, st + 1);
		} else if(k == 1) {
			dfs(i + 1, j, 0, st + 1);
		} else if(k == 2) {
			dfs(i, j + 1, 2, st);
		} else {
			dfs(i, j - 1, 3, st);
		}
	} else if(ch == '|') {
		if(k == 0) {
			dfs(i + 1, j, 0, st);
		} else if(k == 1) {
			dfs(i - 1, j, 1, st);
		} else if(k == 2) {
			dfs(i, j - 1, 3, st + 1);
		} else {
			dfs(i, j + 1, 2, st + 1);
		}
	} else if(ch == '/') {
		if(k == 0) {
			dfs(i, j - 1, 3, st + 1);
		} else if(k == 1) {
			dfs(i, j + 1, 2, st + 1);
		} else if(k == 2) {
			dfs(i - 1, j, 1, st + 1);
		} else {
			dfs(i + 1, j, 0, st + 1);
		}
	} else { // '\'
		if(k == 0) {
			dfs(i, j + 1, 2, st + 1);
		} else if(k == 1) {
			dfs(i, j - 1, 3, st + 1);
		} else if(k == 2) {
			dfs(i + 1, j, 0, st + 1);
		} else {
			dfs(i - 1, j, 1, st + 1);
		}
	}
}
int cnt;
void dfs2(int i, int j, int k) {
	// std :: cout << i << ' ' << j << ' ' << k << nl;
	if(i < 1 || i > n || j < 1 || j > m) {
		return ;
	}
	if(ans[i][j][k] == 1) {
		return ;
	}
	ans[i][j][k] = 1;
	cnt ++;
	char ch = g[i][j];
	if(ch == '-') {
		if(k == 0) {
			dfs2(i - 1, j, 1);
		} else if(k == 1) {
			dfs2(i + 1, j, 0);
		} else if(k == 2) {
			dfs2(i, j + 1, 2);
		} else {
			dfs2(i, j - 1, 3);
		}
	} else if(ch == '|') {
		if(k == 0) {
			dfs2(i + 1, j, 0);
		} else if(k == 1) {
			dfs2(i - 1, j, 1);
		} else if(k == 2) {
			dfs2(i, j - 1, 3);
		} else {
			dfs2(i, j + 1, 2);
		}
	} else if(ch == '/') {
		if(k == 0) {
			dfs2(i, j - 1, 3);
		} else if(k == 1) {
			dfs2(i, j + 1, 2);
		} else if(k == 2) {
			dfs2(i - 1, j, 1);
		} else {
			dfs2(i + 1, j, 0);
		}
	} else { // '\'
		if(k == 0) {
			dfs2(i, j + 1, 2);
		} else if(k == 1) {
			dfs2(i, j - 1, 3);
		} else if(k == 2) {
			dfs2(i + 1, j, 0);
		} else {
			dfs2(i - 1, j, 1);
		}
	}
	ans[i][j][k] = cnt;
}
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			std :: cin >> g[i][j];
		}
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			for(int k = 0; k < 4; ++ k) {
				ans[i][j][k] = -1;
				int x = i + xx[k];
				int y = j + yy[k];
				if(x < 1 || x > n || y < 1 || y > m) {
					ans[i][j][k] = 0;
					continue ;
				}
				deg[i][j][k] = 1;
			}
		}
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			for(int k = 0; k < 4; ++ k) {
				if(!deg[i][j][k]) {
					dfs(i, j, k, 0);
				}
			}
		}
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			for(int k = 0; k < 4; ++ k) {
				std :: cout << i << ' ' << j << ' ' << k << ' ' << ans[i][j][k] << ' ' << deg[i][j][k] << nl;
			}
		}
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			for(int k = 0; k < 4; ++ k) {
				if(ans[i][j][k] == -1) {
					cnt = 0;
					dfs2(i, j, k);
				}
			}
		}
	}
	std :: cin >> q;
	while(q --) {
		int x, y, z;
		std :: string s;
		std :: cin >> x >> y >> s;
		if(s == "above") {
			z = 0;
		} else if(s == "below") {
			z = 1;
		} else if(s == "left") {
			z = 2;
		} else {
			z = 3;
		}
		std :: cout << ans[x][y][z] << nl;
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