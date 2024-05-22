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
const int N = 1010;
const int M = 1e6 + 20;
i64 g[N][N], sum[N][N], n, m;
struct Node {
	int i, j;
	i64 square;
	friend bool operator < (Node a, Node b) {
		return a.square > b.square;
	}
}maxx[M];
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) {
			std :: cin >> g[i][j];
		}
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) {
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + g[i][j];
			// std :: cout << sum[i][j] << " \n"[j==n];
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; ++ i) {
		if(i + m - 1 > n) {
			break;
		}
		for(int j = 1; j <= n; ++ j) {
			if(j + m - 1 > n) {
				break;
			}
			int k = i + m - 1;
			int h = j + m - 1;
			maxx[++cnt] = {i, j, sum[k][h] - sum[i-1][h] - sum[k][j-1] + sum[i-1][j-1]};
		}
	}
	auto check = [&](int i1, int j1, int i2, int j2) -> bool {
		if(i1 >= i2 && j1 >= j2 && i1 <= i2 + m - 1 && j1 <= j2 + m - 1) {
			return false;
		}
		if(i1 >= i2 && j1 + m - 1 >= j2 && i1 <= i2 + m - 1 && j1 + m - 1 <= j2 + m - 1) {
			return false;
		}
		if(i1 + m - 1 >= i2 && j1 >= j2 && i1 + m - 1 <= i2 + m - 1 && j1 <= j2 + m - 1) {
			return false;
		}
		if(i1 + m - 1 >= i2 && j1 + m - 1 >= j2 && i1 + m - 1 <= i2 + m - 1 && j1 + m - 1 <= j2 + m - 1) {
			return false;
		}
		return true;
	};
	std :: sort(maxx + 1, maxx + 1 + cnt);
	// deb(cnt);
	i64 ans = 0;
	for(int i = 1; i <= n; ++ i) {
		int k = i + m - 1;
		if(k > n) {
			break;
		}
		for(int j = 1; j <= n; ++ j) {
			int h = j + m - 1;
			if(h > n) {
				break;
			}
			i64 res = sum[k][h] - sum[i-1][h] - sum[k][j-1] + sum[i-1][j-1];
			int cc = 1;
			for(int s = 1; s <= cnt; ++ s) {
				if(!check(i, j, maxx[s].i, maxx[s].j)) {
					continue;
				}
				for(int t = s + 1; t <= cnt; ++ t) {
					if(check(i, j, maxx[t].i, maxx[t].j) && check(maxx[s].i, maxx[s].j, maxx[t].i, maxx[t].j)) {
						// std :: cout << i << ' ' << j << '\n' << maxx[s].i << ' ' << maxx[s].j << '\n' << maxx[t].i << ' ' << maxx[t].j << '\n';
						// std :: cout << res << ' ' << maxx[s].square << ' ' << maxx[t].square << '\n';
						res += maxx[s].square + maxx[t].square;
						// std :: cout << res << '\n';
						ans = std :: max(ans, res);
						break;
					}
				}
				if(res != sum[k][h] - sum[i-1][h] - sum[k][j-1] + sum[i-1][h-1]) {
					break;
				}
			}
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