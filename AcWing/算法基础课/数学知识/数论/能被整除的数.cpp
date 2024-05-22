#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;

void solve() {
	int n, m;
	std :: cin >> n >> m;
	std :: vector <int> p(m);
	int ans = 0;
	for(int i = 0; i < m; ++ i) std :: cin >> p[i];
	for(int i = 1; i < 1 << m; ++ i) {
		i64 t = 1;
		int cnt = 0;
		for(int j = 0; j < m; ++ j)
			if(i >> j & 1) {
				cnt ++;
				t *= p[j];
				if(t > n) {
					t = -1;
					break;
				}
			}
		// deb(t);
		if(t != -1) {
			if(cnt & 1) ans += (i64) n / t;
			else ans -= (i64) n / t;
		}
	}
	std :: cout << ans;
}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}