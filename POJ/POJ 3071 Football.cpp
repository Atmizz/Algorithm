#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <stack>
#include <cmath>
#include <bitset>
#include <complex>
#include <cstdlib>
#include <set>
#include <cstring>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
typedef long long i64;
const int INF = 0x3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1010;
double p[N][N], dp[10][N];
void solve(int m) {
	int n = 1 << m;
	for(int i = 0; i < n; ++ i)
		for(int j = 0; j < n; ++ j)
			std :: cin >> p[i][j];
	memset(dp, 0, sizeof dp);
	for(int i = 0; i < n; ++ i)
		dp[0][i] = 1;
	for(int k = 1; k <= m; ++ k)
		for(int i = 0; i < n; ++ i)
			for(int j = 0; j < n; ++ j)
				if(((i >> (k - 1)) ^ 1) == (j >> (k - 1)))
					dp[k][i] += dp[k-1][i] * dp[k-1][j] * p[i][j];
	double mx = 0;
	int ans;
	for(int i = 0; i < n; ++ i)
		if(mx < dp[m][i]) mx = dp[m][i], ans = i + 1;
	// deb(mx);
	std :: cout << ans << endl;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = 1;
	//scanf("%d", &T); 
	while(T) {
		int m;
		std :: cin >> m;
		if(m == -1) break;
		solve(m);
	}
	return 0;
}