#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 20;
void solve() {
	std :: string s1, s2;
	int n;
	std :: cin >> n;
	std :: cin >> s1 >> s2;
	if(s1 == s2) {
		std :: cout << 0 << endl;
		return ;
	}
	// solution1
	int cnt0 = 0, cnt1 = 0;
	for(int i = 0; i < n; ++ i)
		if(s1[i] == '0' && s2[i] == '0') cnt0 ++;
		else if(s1[i] == '1' && s2[i] == '1') cnt1 ++;
	int ans = INF;
	if(cnt1 == cnt0 + 1) ans = cnt0 * 2 + 1;
	// solution2
	cnt0 = 0; cnt1 = 0;
	for(int i = 0; i < n; ++ i)
		if(s1[i] == '1' && s2[i] == '0') cnt1 ++;
		else if(s1[i] == '0' && s2[i] == '1') cnt0 ++;
	if(cnt0 == cnt1 && cnt0 != 0) ans = std :: min(ans, cnt0 + cnt1);
	if(ans == INF) std :: cout << -1 << endl;
	else std :: cout << ans << endl;
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