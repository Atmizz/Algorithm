#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define pr pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;

i64 C_(i64 n) {
	return n * (n - 1) / 2;
}

void solve() {
	int n;
	std :: cin >> n;
	std :: map <i64, i64> r, c, c1, c2;
	std :: vector <i64> R, C, C1, C2;
	for(int i = 1; i <= n; ++ i) {
		i64 x, y;
		std :: cin >> x >> y;
		r[x] ++; c[y] ++; c1[y-x] ++; c2[x+y] ++;
		if(r[x] == 2) R.push_back(x);
		if(c[y] == 2) C.push_back(y);
		if(c1[y-x] == 2) C1.push_back(y-x);
		if(c2[y+x] == 2) C2.push_back(x+y);
	}
	i64 ans = 0;
	for(auto x : R) ans += C_(r[x]);
	for(auto x : C) ans += C_(c[x]);
	for(auto x : C1) ans += C_(c1[x]);
	for(auto x : C2) ans += C_(c2[x]);
	std :: cout << ans * 2 << endl;
}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}