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
int xx[4] = {-1, 1, 0, 0};
int yy[4] = {0, 0, -1, 1};
int ans[N][N][4];
int n, m, p;
char g[N][N];
std :: vector < std :: array <int, 3> > v;
int dfs(int x, int y, int k, int step) {
	if(x < 1 || x > n || y < 1 || y > m) {
		return 0;
	}
	int K;
	char p = g[x][y];
	if(k == 0 && p == '-') {
		
	}
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
			}
		}
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			for(int k = 0; k < 4; ++ k) {
				if(ans[i][j][k] == -1) {
					ans[i][j][k] = 0;
					ans[i][j][k] = dfs(i, j, k, 0);
				}
			}
		}
	}
	std :: cin >> p;
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