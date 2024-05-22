#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e5 + 20;
std :: string s;
int t[11][N];
void init() {
	for(int j = 0; j <= N - 20; ++ j)
		for(int i = 0; i <= 9; ++ i)
			if(i + j <= 9) t[i][j] = 1;
			else t[i][j] = (t[0][i+j-10] + t[1][i+j-10]) % Mod;
}
void solve() {
	int n, k, ans = 0;
	std :: cin >> n >> k;
	while(n) {
		ans = (ans + t[n%10][k]) % Mod;
		n /= 10;
	}
	std :: cout << ans << endl;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1; init();
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}
