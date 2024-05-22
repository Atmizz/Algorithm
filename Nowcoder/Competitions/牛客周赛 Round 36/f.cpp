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
const int N = 1e5 + 20;
int sum[6][N], n, q;
inline int lowbit(int x) {
	return x & -x;
}
void add(int x, int k, int y) {
	for(; x <= n; x += lowbit(x)) {
		sum[k][x] += y;
	}
}
int query(int x, int k) {
	int s = 0;
	for(; x; x -= lowbit(x)) {
		s += sum[k][x];
	}
	return s;
}
std :: string str;
void solve() {
	std :: cin >> n >> q;
	std :: cin >> str;
	std :: string res[] = {"red", "rde", "der", "dre", "edr", "erd"};
	for(int i = 0; i < 6; ++ i) {
		for(int j = 0; j < n; ++ j) {
			add(j + 1, i, (str[j] != res[i][j%3]));
		}
	}
	while(q --) {
		int opt, l, r;
		char y;
		std :: cin >> opt;
		if(opt == 1) {
			std :: cin >> l >> y;
			for(int i = 0; i < 6; ++ i) {
				if(res[i][(l-1)%3] != str[l-1]) {
					add(l, i, -1);
				}
				if(y != res[i][(l-1)%3]) {
					add(l, i, 1);
				}
			}
			str[l-1] = y;
		} else {
			std :: cin >> l >> r;
			int ans = INF;
			for(int i = 0; i < 6; ++ i) {
				ans = std :: min(ans, query(r, i) - query(l-1, i));
			}
			std :: cout << ans << '\n';
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