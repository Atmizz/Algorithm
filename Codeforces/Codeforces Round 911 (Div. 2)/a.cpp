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
	int n; std :: cin >> n;
	std :: string str; std :: cin >> str;
	str = "0" + str;
	int ans = 0;
	for(int i = 1; i <= n;) {
		while(str[i] == '#' && i <= n) ++ i;
		int j = i, cnt = 0;
		while(str[j] == '.' && j <= n) cnt ++, ++ j;
		deb(cnt);
		if(cnt >= 2) ans += 2;
		else if(cnt == 1) ans ++;
		i = j;
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