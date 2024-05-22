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

std :: string s[101];
int n, m;
bool check(int x, int y) {
	if(x + 8 > n - 1) return false;
	if(y + 8 > m - 1) return false;
	for(int i = x; i < x + 3; ++ i)
		for(int j = y; j < y + 3; ++ j)
			if(s[i][j] != '#') return false;
	
	for(int i = x + 6; i <= x + 8; ++ i)
		for(int j = y + 6; j <= y + 8; ++ j)
			if(s[i][j] != '#') return false;
	  // deb(x); deb(y);
	for(int i = 0; i < 4; ++ i) {
		if(s[x+3][y+i] != '.') return false;
		if(s[x+i][y+3] != '.') return false;
		if(s[x+5][y+i+5] != '.') return false;
		// if(x == 0 && y == 9) std :: cout << "ok\n";
		if(s[x+i+5][y+5] != '.') return false;
	} return true;
}

void solve() {
	std :: cin >> n >> m;
	for(int i = 0; i < n; ++ i) std :: cin >> s[i];
	for(int i = 0; i < n; ++ i)
		for(int j = 0; j < m; ++ j)
			if(check(i, j)) std :: cout << i + 1 << ' ' << j + 1 << endl;
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