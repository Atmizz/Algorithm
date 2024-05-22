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
char ch[25][25];
int n, m;
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= m; ++ j)
			std :: cin >> ch[i][j];
	std :: vector <int> pos[4];
	for(int j = 1; j <= m; ++ j)
		for(int i = 1; i <= n; ++ i)
			if(ch[i][j] == 'v') pos[0].push_back(j);
			else if(ch[i][j] == 'i') pos[1].push_back(j);
			else if(ch[i][j] == 'k') pos[2].push_back(j);
			else if(ch[i][j] == 'a') pos[3].push_back(j);
	int num = 0;
	for(int i = 0; i < 4; ++ i) {
		int p = std :: upper_bound(pos[i].begin(), pos[i].end(), num) - pos[i].begin();
		// deb(i); deb(pos[i].size());
		if(p == pos[i].size()) {
			std :: cout << "NO\n";
			return ;
		} num = pos[i][p];
	}
	std :: cout << "YES\n";
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