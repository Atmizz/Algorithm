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
int a[N], f[N][N], n;
void solve() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i)
		scanf("%d", &a[i]);
	for(int len = 3; len <= n - 2; ++ len)
		for(int i = 1; i + len - 1 <= n; ++ i) {
			int j = i + len - 1;
			f[i][j] = INF;
			for(int k = i + 1; k < j; ++ k)
				f[i][j] = std :: min(f[i][j], f[i][k] + f[k+1][j] + a[i] * a[k] * a[j]);
			deb(f[i][j]);
		}
	std :: cout << f[2][n-1];
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = 1;
	//scanf("%d", &T); 
	while(T --) solve();
	return 0;
}