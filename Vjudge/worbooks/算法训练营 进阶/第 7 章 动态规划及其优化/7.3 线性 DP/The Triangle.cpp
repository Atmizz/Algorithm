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
typedef long long i64;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 110;
int f[N][N], n, a[N][N];
void solve() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= i; ++ j)
			scanf("%d", &a[i][j]);
	f[1][1] = a[1][1];
	for(int i = 2; i <= n; ++ i)
		for(int j = 1; j <= i; ++ j)
			f[i][j] = std :: max(f[i][j], std :: max(f[i-1][j], f[i-1][j-1]) + a[i][j]);
	int ans = 0;
	for(int i = 1; i <= n; ++ i)
		ans = std :: max(ans, f[n][i]);
	std :: cout << ans;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = 1;
	//scanf("%d", &T); 
	while(T --) solve();
	return 0;
}