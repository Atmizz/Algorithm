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
const int N = 1050;
int n, m;
int xx[2] = {0, 1};
int yy[2] = {1, 0};
char g[N][N];
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			std :: cin >> g[i][j];
		}
	}
	std :: string ans = "";
	ans += g[1][1];
	std :: set <PII> a[n*m];
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			a[i+j].insert({i, j});
		}
	}
	for(int i = 3; i <= n; ++ i) {
		std :: set <PII> s;
		for(auto j : a[i]) {
			auto [x, y] = j;
			if(a[i-1].find({x-1, y}) != -1 || a[i-1].find({x, y-1}) != -1) {
				
			}
		}
	}
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