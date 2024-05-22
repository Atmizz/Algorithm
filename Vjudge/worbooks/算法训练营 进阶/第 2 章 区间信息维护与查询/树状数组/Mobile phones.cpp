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
const int N = 1050;
int c[N][N], n;
int lowbit(int x) {
	return x & -x;
}
int sum(int x, int y) {
	int res = 0;
	for(int i = x; i; i -= lowbit(i))
		for(int j = y; j; j -= lowbit(j))
			res += c[i][j];
//	std :: cout << x << ' ' << y << endl;
//	deb(res);
	return res;
}
void modify(int x, int y, int a) {
	for(int i = x; i <= n; i += lowbit(i))
		for(int j = y; j <= n; j += lowbit(j))
			c[i][j] += a;
}
int query(int x1, int y1, int x2, int y2) {
	return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
}
void solve() {
	while(1) {
		int opt, x1, x2, y1, y2, s, x, y, a;
		scanf("%d", &opt);
		if(opt == 3) return ;
		if(opt == 0) {
			scanf("%d", &s); n = s;
			for(int i = 1; i <= s; ++ i) 
				for(int j = 1; j <= s; ++ j)
					c[i][j] = 0;
		} else if(opt == 1) {
			scanf("%d %d %d", &x, &y, &a);
			x ++; y ++;
			modify(x, y, a);
		} else {
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			x1 ++; y1 ++; x2 ++; y2 ++;
//			deb(x1); deb(x2); deb(y1); deb(y2);
			printf("%d\n", query(x1, y1, x2, y2));
		}
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
