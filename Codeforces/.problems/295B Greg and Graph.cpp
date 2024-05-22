#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 550;
i64 d[N][N], n, ans[N], arr[N];
bool vis[N];
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= n; ++ j)
			std :: cin >> d[i][j];
	for(int i = 1; i <= n; ++ i)
		std :: cin >> arr[i];
	for(int h = n; h >= 1; -- h) {
		int k = arr[h]; vis[k] = 1;
		for(int i = 1; i <= n; ++ i)
			for(int j = 1; j <= n; ++ j)
				d[i][j] = std :: min(d[i][j], d[i][k] + d[k][j]);

		for(int i = 1; i <= n; ++ i)
			for(int j = 1; j <= n; ++ j)
				if(vis[i] == 1 && vis[j] == 1)
					ans[h] += d[i][j];

	}
	for(int i = 1; i <= n; ++ i)
		std :: cout << ans[i] << ' ';
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