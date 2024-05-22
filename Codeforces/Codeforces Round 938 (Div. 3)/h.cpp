#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 55;
int pow3[N], n, m, k;
char g[N][N];
struct tower {
	int x, y, p;
}a[N*N];
int get(int x1, int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
void solve() {
	std :: cin >> n >> m >> k;
	i64 ans = 0; int sum = 0;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			std :: cin >> g[i][j];
			sum += g[i][j] == '#';
		}
	}
	for(int i = 1; i <= k; ++ i) {
		std :: cin >> a[i].x >> a[i].y >> a[i].p;
	}
	for(int _ = 1; _ <= k; ++ _) {
		i64 res = 0;
		for(int p = 1; ; ++ p) {
			int cnt = 0; i64 dmg = 0;
			for(int i = 1; i <= n; ++ i) {
				for(int j = 1; j <= m; ++ j) {
					if(get(a[_].x, a[_].y, i, j) <= p * p && g[i][j] == '#') {
						cnt ++;
					}
				}
			}
			dmg = 1LL * pow3[p] - a[_].p * cnt;
			deb(p);
			deb(cnt);
			deb(dmg);
			res = std :: min(res, dmg);
			// deb(cnt);
			if(cnt == sum) {
				break;
			}
		}
		deb(res);
		ans += res;
	}
	std :: cout << -ans << '\n';
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	pow3[0] = 1;
	for(int i = 1; ; ++ i) {
		pow3[i] = pow3[i-1] * 3;
		if(pow3[i] > 1250000) {
			break;
		}
	}
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}