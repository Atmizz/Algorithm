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
#define DEB std :: cout << "ok" << endl;
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
const int N = 550;
char g[N][N];
int n, m;
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			std :: cin >> g[i][j];
		}
	}
	bool okRow1 = false, okRow2 = false, okCol1 = false, okCol2 = false;
	for(int i = 1; i <= m; ++ i) {
		if(g[1][i] == 'W') {
			okRow1 = true;
		}
		if(g[n][i] == 'W') {
			okRow2 = true;
		}
	}
	for(int i = 1; i <= n; ++ i) {
		if(g[i][1] == 'W') {
			okCol1 = true;
		}
		if(g[i][m] == 'W') {
			okCol2 = true;
		}
	}
	if(okCol1 && okCol2 && okRow1 && okRow2) {
		std :: cout << "YES\n";
		return ;
	}
	okRow1 = false, okRow2 = false, okCol1 = false, okCol2 = false;
	for(int i = 1; i <= m; ++ i) {
		if(g[1][i] == 'B') {
			okRow1 = true;
		}
		if(g[n][i] == 'B') {
			okRow2 = true;
		}
	}
	for(int i = 1; i <= n; ++ i) {
		if(g[i][1] == 'B') {
			okCol1 = true;
		}
		if(g[i][m] == 'B') {
			okCol2 = true;
		}
	}
	if(okCol1 && okCol2 && okRow1 && okRow2) {
		std :: cout << "YES\n";
		return ;
	}
	std :: cout << "NO\n";
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	std :: cin >> _; 
	while(_ --) solve();
	return 0;
}