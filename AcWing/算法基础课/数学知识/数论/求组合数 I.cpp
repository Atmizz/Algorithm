#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pr pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;
const int N = 2020;

int f[N][N];

void C() {
	for(int i = 0; i <= 2000; ++ i)
			for(int j = 0; j <= i; ++ j)
				if(!j) f[i][j] = 1;
				else f[i][j] = (f[i-1][j-1] + f[i-1][j]) % Mod;
}

void solve() {
	int n, m;
	std :: cin >> n >> m;
	std :: cout << f[n][m] << endl;
}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	C();
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}