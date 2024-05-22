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
	int n = 8;
	char g[10][10];
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= n; ++ j)
			std :: cin >> g[i][j];
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= n; ++ j)
			if(g[i][j] != '.') {
				for(int k = i ; g[k][j] != '.' && k <= n; ++ k)
					std :: cout << g[k][j];
				std :: cout << endl;
				return ;
			}
	puts("");
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