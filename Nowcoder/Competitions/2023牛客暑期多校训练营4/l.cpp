#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;

void solve() {
	int n, m, q;
	i64 ans = 0;
	std :: cin >> n >> m >> q;
	std :: vector s(q, std :: vector <std :: string> (2));
	std :: vector <int> a(q);
	for(int i = 0; i < q; ++ i)
		std :: cin >> s[i][0] >> a[i] >> s[i][1];
	std :: vector <int> row(n+1, -1), col(m+1, -1);
	int r = 0, c = 0, r_ = 0, c_ = 0;
	for(int i = q - 1; i >= 0; -- i) {
		if(s[i][0] == "row" && s[i][1] == "off") {
			if(row[a[i]] != -1) continue;
			row[a[i]] = 0; r_ ++;
		} else if(s[i][0] == "row" && s[i][1] == "on") {
			if(row[a[i]] != -1) continue;
			row[a[i]] = 1; r ++; ans += (i64) m - c - c_;
		} else if(s[i][0] == "column" && s[i][1] == "off") {
			if(col[a[i]] != -1) continue;
			col[a[i]] = 0; c_ ++;
		} else {
			if(col[a[i]] != -1) continue;
			col[a[i]] = 1; c ++; ans += (i64) n - r - r_;
		}
	}
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