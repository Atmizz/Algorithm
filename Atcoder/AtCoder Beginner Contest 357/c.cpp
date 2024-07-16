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
int n;
std :: string s = ".#";
char g[N][N];
void dfs(int x_1, int y_1, int x_2, int y_2, int x) {
	if(x_1 == x_2 && y_1 == y_2) {
		g[x_1][y_1] = s[x];
		return ;
	}
	int len = (x_2 - x_1 + 1) / 3;
	dfs(x_1, y_1, x_1 + len - 1, y_1 + len - 1, x);

	dfs(x_1, y_1 + len, x_1 + len - 1, y_1 + len * 2 - 1, x);

	dfs(x_1, y_1 + len * 2, x_1 + len - 1, y_1 + len * 3 - 1, x);

	dfs(x_1 + len, y_1, x_1 + len * 2 - 1, y_1 + len - 1, x);

	dfs(x_1 + len, y_1 + len, x_1 + len * 2 - 1, y_1 + len * 2 - 1, 0);
	
	dfs(x_1 + len, y_1 + len * 2, x_1 + len * 2 - 1, y_1 + len * 3 - 1, x);

	dfs(x_1 + len * 2, y_1, x_1 + len * 3 - 1, y_1 + len - 1, x);

	dfs(x_1 + len * 2, y_1 + len, x_1 + len * 3 - 1, y_1 + len * 2 - 1, x);

	dfs(x_1 + len * 2, y_1 + len * 2, x_1 + len * 3 - 1, y_1 + len * 3 - 1, x);

}
void solve() {
	std :: cin >> n;
	if(n == 1) {
		std :: cout << "###\n#.#\n###";
		return ;
	}
	int m = 1;
	for(int i = 1; i <= n; ++ i) {
		m *= 3;
	}
	dfs(1, 1, m, m, 1);
	for(int i = 1; i <= m; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			std :: cout << g[i][j];
		}
		std :: cout << '\n';
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