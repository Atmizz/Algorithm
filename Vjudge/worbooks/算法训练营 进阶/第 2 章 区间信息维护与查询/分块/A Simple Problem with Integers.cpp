#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
const int N = 1e5 + 20;
i64 a[N], b[N], tot[N];
int block, n, m, blk[N];
void modify(int l, int r, i64 x) {
	for(int i = l; i <= std :: min(r, block * blk[l]); ++ i)
		a[i] += x, tot[blk[i]] += x;
	if(blk[l] != blk[r])
		for(int i = (blk[r] - 1) * block + 1; i <= r; ++ i)
			a[i] += x, tot[blk[i]] += x;
	for(int i = blk[l] + 1; i <= blk[r] - 1; ++ i)
		b[i] += x;
}
i64 query(int l, int r) {
	i64 res = 0;
	for(int i = l; i <= std :: min(r, block * blk[l]); ++ i)
		res += a[i] + b[blk[i]];
	if(blk[l] != blk[r])
		for(int i = (blk[r] - 1) * block + 1; i <= r; ++ i)
			res += a[i] + b[blk[i]];
	for(int i = blk[l] + 1; i <= blk[r] - 1; ++ i)
		res += tot[i] + b[i] * block;
	return res;
}
void solve() {
	scanf("%d %d", &n, &m);
	block = sqrt((double)n);
	for(int i = 1; i <= n; ++ i)
		blk[i] = (i - 1) / block + 1;
	for(int i = 1; i <= n; ++ i)
		scanf("%lld", &a[i]);
	for(int i = 1; i <= n; ++ i)
		tot[blk[i]] += a[i];
	for(int i = 1; i <= m; ++ i) {
		char opt; int l, r; i64 x;
		std :: cin >> opt; scanf("%d %d", &l, &r);
		if(opt == 'C') {
			scanf("%lld", &x);
			modify(l, r, x);
		} else printf("%lld\n", query(l, r));
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