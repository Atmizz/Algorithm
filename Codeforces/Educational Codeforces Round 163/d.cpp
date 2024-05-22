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
// const int N = ;
void solve() {
	std :: string str;
	std :: cin >> str;
	str = "0" + str;
	int ans = 0, n = str.length() - 1;
	for(int len = 1; len <= n; len ++) {
		int res = 0;
		for(int i = 1; i + len <= n; ++ i) {
			if(str[i] != str[i+len] && str[i] != '?' && str[i+len] != '?') {
				res = 0;
			} else {
				res ++;
				if(res == len) {
					ans = std :: max(ans, len * 2);
				}
			}
		}
	}
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