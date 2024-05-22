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
const int N = 220;
int f[N][1024];
void solve() {
	int n, m;
	std :: cin >> n >> m;
	std :: vector <int> a(n), b(m);
	for(int i = 0; i < n; ++ i)
		std :: cin >> a[i];
	for(int i = 0; i < m; ++ i)
		std :: cin >> b[i];
	f[0][0] = 1;
	for(int i = 0; i < n; ++ i)
		for(int j = 0; j < m; ++ j) {
			int r = a[i] & b[j];
			for(int k = 0; k < 1 << 9; ++ k)
				f[i+1][k | r] |= f[i][k];
		}
	for(int i = 0; i < 1 << 9; ++ i)
		if(f[n][i]) {
			std :: cout << i;
			return ;
		}
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