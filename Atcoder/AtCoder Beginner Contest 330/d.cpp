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
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2020;
int n;
i64 h[N], l[N], ans;
std :: string s[N];
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> s[i], s[i] = ')' + s[i];
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= n; ++ j)
			if(s[i][j] == 'o') h[i] ++, l[j] ++;
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= n; ++ j)
			if(s[i][j] == 'o')
				ans += (h[i] - 1) * (l[j] - 1);
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