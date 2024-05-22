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
	std :: string s1, s2;
	std :: cin >> s1 >> s2;
	int cnt = 0, ans = INF;
	for(int i = 0; i < n; ++ i) {
		if(s1[i] != s2[i]) {
			cnt ++;
		}
	}
	if(cnt == 0) {
		std :: cout << "0\n";
		return ;
	}
	ans = std :: min(ans, ((cnt & 1) ? (cnt * 2 - 1) : (cnt * 2)));
	std :: reverse(s1.begin(), s1.end());
	cnt = 0;
	for(int i = 0; i < n; ++ i) {
		if(s1[i] != s2[i]) {
			cnt ++;
		}
	}
	if(cnt == 0) {
		std :: cout << "2\n";
		return ;
	}
	ans = std :: min(ans, ((cnt & 1) ? (cnt * 2) : (cnt * 2 - 1)));
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