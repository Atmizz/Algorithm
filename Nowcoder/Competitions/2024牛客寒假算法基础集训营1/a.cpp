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
	std :: string str;
	std :: cin >> str;
	int D = 0, F = 0, S = 0, d = 0, f = 0, s = 0;
	for(int i = 0; i <= n; ++ i) {
		if(str[i] == 'D') {
			D = 1;
		} else if(str[i] == 'F' && D) {
			F = 1;
		} else if(str[i] == 'S' && F) {
			S = 1;
		} else if(str[i] == 'd') {
			d = 1;
		} else if(str[i] == 'f' && d) {
			f = 1;
		} else if(str[i] == 's' && f) {
			s = 1;
		}
	}
	std :: cout << ((D && F && S) ? 1 : 0) << ' ' << ((d && f && s) ? 1 : 0) << '\n';
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