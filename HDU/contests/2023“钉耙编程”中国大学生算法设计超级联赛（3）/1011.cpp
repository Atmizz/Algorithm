#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;

void solve() {
	int n, Z;
	std :: cin >> n >> Z;
	std :: vector a(n+1, std :: vector <char> (n+1));
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= n; ++ j)
			std :: cin >> a[i][j];
	if(n * Z % 100) {
		std :: cout << "error\n";
		return ;
	}
	int N = n * Z / 100;
	if(N % n == 0) {
		for(int i = 1; i <= n; ++ i)
			for(int j = 1; j <= N / n; ++ j) {
				for(int k = 1; k <= n; ++ k) {
					for(int h = 1; h <= N / n; ++ h)
						std :: cout << a[i][k];
				}
					std :: cout << endl;
			}
	} else {
		bool flag = 1;
		std :: vector vis(n+1, std :: vector <bool> (n+1));
		std :: vector ans(N+1, std :: vector <char> (N+1));
		auto check = [&](auto self, int x, int y) -> void {
			int r = y;
			for(; r <= n; ++ r)
				if(a[x][r] != a[x][y]) {
					r --; break;
				}
			int l = x;
			for(; l <= n; ++ l)
				if(a[l][y] != a[x][y]) {
					l --; break;
				}
			if(l > n) l = n;
			if(r > n) r = n;
			// int L = r - y + 1;
			int L = std :: min(r - y + 1, l - x + 1);
			// deb(L);
			if((L * Z) % 100 != 0) {
				flag = 0;
				return ;
			}
			for(int i = x; i <= x + L - 1; ++ i)
				for(int j = y; j <= y + L - 1; ++ j)
					if(a[i][j] == a[x][y]) vis[i][j] = 1;
					else {
						flag = 0;
						return ;
					}
			for(int i = 1; i <= L * Z / 100; ++ i)
				for(int j = 1; j <= L * Z / 100; ++ j)
					ans[(x-1)*Z/100+i][(y-1)*Z/100+j] = a[x][y];
		};
		for(int i = 1; i <= n; ++ i) {
			for(int j = 1; j <= n; ++ j)
				if(!vis[i][j]) check(check, i, j);
			if(!flag) break;
		}
		if(!flag) {
			std :: cout << "error\n";
			return ;
		}
		for(int i = 1; i <= N; ++ i) {
			for(int j = 1; j <= N; ++ j)
				std :: cout << ans[i][j];
			std :: cout << endl;
		}
	}
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