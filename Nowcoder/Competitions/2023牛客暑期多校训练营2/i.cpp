#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define pr pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;

void solve() {
	int n, m;
	std :: cin >> n >> m;
	std :: string str[2], ch[2];
	str[0] = "oooox", str[1] = "xxxxo";
	ch[0] = 'x', ch[1] = 'o';
	std :: vector < std :: string > g(n);
	if(n & 1) {
		int flag = 0, ff = 1;
		for(int i = 0; i < n - 1; ++ i, flag ^= 1, ff ^= 1) {
			while(g[i].size() + 5 <= m) g[i] += str[flag];
			while(g[i].size() < m) g[i] += ch[ff];
		} ff = 1;
		for(int i = 0; i < m; ++ i)
			g[n-1] += ch[ff^=1];
	} else {
		int flag = 0, ff = 1;
		for(int i = 0; i < n; ++ i, flag ^= 1, ff ^= 1) {
			while(g[i].size() + 5 <= m) g[i] += str[flag];
			while(g[i].size() < m) g[i] += ch[ff];
		}
	}
	for(int i = 0; i < n; ++ i)
		std :: cout << g[i] << endl;
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