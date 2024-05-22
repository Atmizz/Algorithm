/*
O(n sqrt(n) log(n))
*/
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
const int N = 2e5 + 20;
int n, a[N], mp[N];
void solve() {
	std :: cin >> n;
	int ans = 1;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		mp[a[i]] ++;
		ans = std :: max(ans, mp[a[i]]);
	}
	std :: sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; ++ i) {
		int x = a[i];
		for(int j = 1; j <= sqrt(x); ++ j) {
			if(x % j) {
				continue ;
			}
			int y = x, cnt = 1;
			while(y % j == 0 && mp[y / j] && j > 1) {
				cnt ++;
				y /= j;
			}
			ans = std :: max(ans, cnt);
			if(j * j != x) {
				y = x;
				cnt = 1;
				while(y % (x / j) == 0 && mp[y/(x/j)]) {
					cnt ++;
					y /= (x / j);
				}
				ans = std :: max(ans, cnt);
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