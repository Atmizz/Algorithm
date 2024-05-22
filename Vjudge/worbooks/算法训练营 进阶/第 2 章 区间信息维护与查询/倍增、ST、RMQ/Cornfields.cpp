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
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 280;
int b, n, k, minn[N*N][22], maxx[N*N][22], a[N*N], K;
int query(int x, int y) {
	int MAXX = -INF, MINN = INF;
	for(int i = x; i < x + b; ++ i) {
		int l = (i - 1) * n + y, r = l + b - 1;
		MAXX = std :: max(MAXX, std :: max(maxx[l][K], maxx[r-(1<<K)+1][K]));
		MINN = std :: min(MINN, std :: min(minn[l][K], minn[r-(1<<K)+1][K]));
	}
	return MAXX - MINN;
}
void solve() {
	scanf("%d %d %d", &n, &b, &k);
	while(1 << K <= b) K ++; K --;
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= n; ++ j)
			scanf("%d", &a[(i-1)*n+j]);
	for(int i = 1; i <= n * n; ++ i)
		minn[i][0] = maxx[i][0] = a[i];
	for(int j = 1; j <= 21; ++ j)
		for(int i = 1; i + (1 << j) - 1 <= n * n; ++ i) {
			minn[i][j] = std :: min(minn[i][j-1], minn[i+(1<<(j-1))][j-1]);
			maxx[i][j] = std :: max(maxx[i][j-1], maxx[i+(1<<(j-1))][j-1]);
		}
	while(k --) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", query(x, y));
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = 1;
	//scanf("%d", &T); 
	while(T --) solve();
	return 0;
}