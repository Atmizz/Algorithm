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
int n, x, a[N];
bool flag[N];
void solve() {
	std :: cin >> n >> x;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		flag[i] = 1;
	}
	int ans = -1;
	for(int j = 30; j >= 0; -- j) {
		int cnt = 0;
		bool ok = 1;
		if(x & (1 << j)) {
			for(int i = 1; i <= n; ++ i) {
				if(a[i] & (1 << j)) {
					ok = !ok;
				}
				if(ok && flag[i]) {
					cnt ++;
				}
			}
			if(ok) {
				ans = std :: max(ans, cnt);
			}
		} else {
			for(int i = 1; i <= n; ++ i) {
				if(a[i] & (1 << j)) {
					ok = !ok;
				}
				if(!ok) {
					flag[i] = 0;
				}
			}
			if(!ok) {
				std :: cout << ans << '\n';
				return ;
			}
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; ++ i) {
		cnt += flag[i] == 1;
	}
	ans = std :: max(ans, cnt);
	std :: cout << ans << '\n';
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}