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
std :: mt19937 rd(114514);
int n, m;
void solve() {
	std :: cin >> n >> m;
	std :: vector <int> st(m), ed(m);
	for(int i = 0; i < m; ++ i) {
		std :: cin >> st[i] >> ed[i];
	}
	int ans = 0;
	for(int _ = 0; _ < 1 << m; ++ _) {

		std :: vector <int> c(n+2);

		for(int i = 0; i < m; ++ i) {
			if((_ >> i & 1)) {
				c[st[i]] ++;
				c[ed[i]+1] --;
			}
		}

		bool ok = true;
		for(int i = 1; i <= n; ++ i) {
			c[i] += c[i-1];
			if(c[i] < 2) {
				ok = false;
				break;
			}
		}

		if(ok) {
			ans ++;
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