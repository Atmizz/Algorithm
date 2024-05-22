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
	int n;
	std :: cin >> n;
	std :: string s;
	std :: cin >> s;
	std :: string a = "map", b = "pie", c = "mapie";
	int ans = 0;
	for(int i = 0; i < n - 2; ++ i) {
		int cnt = 0;
		if(i < n - 4) {
			for(int j = 0; j < 5; ++ j) {
				if(s[i+j] != c[j]) {
					cnt ++;
					break;
				}
			}
			if(cnt == 0) {
				continue;
			}
		}
		cnt = 0;
		for(int j = 0; j < 3; ++ j) {
			if(s[i+j] != a[j]) {
				cnt ++;
				break;
			}
		}
		for(int j = 0; j < 3; ++ j) {
			if(s[i+j] != b[j]) {
				cnt ++;
				break;
			}
		}
		ans += (cnt < 2);
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