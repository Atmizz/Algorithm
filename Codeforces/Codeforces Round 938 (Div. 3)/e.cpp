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
// const int N = ;
void solve() {
	int n;
	std :: cin >> n;
	std :: string s;
	std :: cin >> s;
	s = '0' + s;
	int ans = 1;
	for(int i = 2; i <= n; ++ i) {
		std :: string b = s;
		std :: vector <int> c(n*2+4);
		for(int j = 1; j <= n - i + 1; ++ j) {
			c[j] += c[j-1];
			if((b[j] == '0' && !(c[j] & 1)) || b[j] == '1' && (c[j] & 1)) {
				c[j] ++;
				c[j+i] --;
			}
		}
		bool ok = 1;
		for(int j = 1; j <= n; ++ j) {
			if(j > n - i + 1) {
				c[j] += c[j-1];
			}
			if((b[j] == '0' && !(c[j] & 1)) || b[j] == '1' && (c[j] & 1)) {
				ok = false;
				break;
			}
		}
		if(ok) {
			ans = i;
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