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
	std :: string str;
	std :: cin >> str;
	int cnt0 = 0, cnt1 = 0, fg = 0;
	for(int i = 0; i < n; ++ i)
		if(str[i] == '0') cnt0 ++;
		else cnt1 ++;
	for(int i = 1; i < n; ++ i)
		if(str[i] != str[i-1])
			fg = 1;
	if(cnt0 > cnt1 || fg == 1) {
		std :: cout << "YES\n";
	} else std :: cout << "NO\n";
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