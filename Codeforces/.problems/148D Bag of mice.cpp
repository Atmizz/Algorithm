#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1010;
double dp[N][N];
int w, b;
void solve() {
	std :: cin >> w >> b;
	for(int i = 1; i <= w; ++ i)
		dp[i][0] = 1;
	for(int i = 1; i <= w; ++ i)
		for(int j = 1; j <= b; ++ j) {
			dp[i][j] += (double)i / (i + j);
			if(j >= 3)
				dp[i][j] += (double)j / (i + j) * (j - 1) / (i + j - 1) * (j - 2) / (i + j - 2) * dp[i][j-3];
			if(i >= 1 && j >= 2)
				dp[i][j] += (double)j / (i + j) * (j - 1) / (i + j - 1) * i / (i + j - 2) * dp[i-1][j-2];
		}
	printf("%.9lf", dp[w][b]);
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