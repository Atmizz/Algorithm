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
	int n, m;
	std :: cin >> n >> m;
	std :: string str;
	std :: cin >> str;

	std :: vector <int> l(n), r(n);
	int ll = 0, rr = n-1;

	int i = 0;
	while(str[i] == '1') l[i] = 0, ++ i;
	if(str[0] == '1') ll = i;
	for(; i < n; ++ i) {
		if(i > 0 && str[i] == '0' && str[i-1] == '1') ll = i;
		l[i] = ll;
	}

	i = n - 1;
	while(str[i] == '0') r[i] = n - 1, -- i;
	if(str[n-1] == '0') rr = i;
	for(; i >= 0; -- i) {
		if(i < n - 1 && str[i] == '1' && str[i+1] == '0') rr = i;
		r[i] = rr;
	}

	std :: map <pi, bool> mmp;
	int ans = 0;
	for(int i = 1; i <= m; ++ i) {
		int x, y;
		std :: cin >> x >> y;
		x --; y --;
		if(l[x] == l[y] && r[x] == r[y]) {
			if(mmp[{-1, -1}] == false) ans ++;
			mmp[{-1, -1}] = true;
			continue;
		}
		if(x > 0) if(str[x-1] == '0') x = l[x];
		if(y < n - 1) if(str[y+1] == '1') y = r[y];

		if(mmp[{x, y}] == false) ans ++;
		mmp[{x, y}] = true;
	}
	std :: cout << ans << endl;
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