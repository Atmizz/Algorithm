#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define int long long
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
int n[3], h[3], c[3];
void solve() {
	std :: string str;
	std :: cin >> str;
	i64 m, o = INF;
	for(int i = 0; i < 3; ++ i)
		std :: cin >> h[i];
	for(int i = 0; i < 3; ++ i)
		std :: cin >> c[i];
	std :: cin >> m;

	for(int i = 0; i < str.size(); ++ i)
		if(str[i] == 'B') n[0] ++;
		else if(str[i] == 'S') n[1] ++;
		else if(str[i] == 'C') n[2] ++;

	for(int i = 0; i < 3; ++ i)
		if(n[i])
			o = std :: min(o, (i64)h[i] / n[i]);
	for(int i = 0; i < 3; ++ i)
		h[i] -= o * n[i];
	
	auto check = [&] (i64 x) -> bool {
		i64 mm = m;
		for(int i = 0; i < 3; ++ i)
			if(n[i] && h[i] < (x - o) * n[i])
				mm -= ((x - o) * n[i] - h[i]) * c[i];
		if(mm < 0) return false;
		return true;
	};

	i64 l = 0, r = 1e15, ans;
	while(l <= r) {
		i64 mid = (l + r) >> 1;
		if(check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	} std :: cout << ans;
}

signed main() {
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