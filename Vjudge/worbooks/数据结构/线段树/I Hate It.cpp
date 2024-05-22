#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls x << 1
#define rs x << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 4e5 + 10;
struct LIVE {
	int l, r, max;
}t[N << 1];
int m, n, pts[N >> 1];
void up(int x) {t[x].max = std :: max(t[ls].max, t[rs].max);}
void build(int l, int r, int x) {
	t[x].l = l; t[x].r = r;
	if(l == r) {
		t[x].max = pts[l];
		return ;
	}
	int mid = l + r >> 1;
	build(l, mid, ls); build(mid+1, r, rs);
	up(x);
}
void data(int f, int x, int k) {
	if(t[x].l == f && t[x].r == f) {
		t[x].max = k;
		return ;
	}
	int mid = t[x].l + t[x].r >> 1;
	if(f <= mid) data(f,ls,k);
	if(f > mid) data(f,rs,k);
	up(x);
}
int Ask(int l, int r, int x) {
	if(t[x].l >= l && t[x].r <= r)
		return t[x].max;
	int mid = t[x].l + t[x].r >> 1;
	int ans = - 9999999;
	if(l <= mid) ans = std :: max(ans, Ask(l,r,ls));
	if(r > mid) ans = std :: max(ans, Ask(l,r,rs));
	return ans;
}
int main() {
	while(~scanf("%d%d",&n,&m)) {
		for(int i = 1; i <= n; ++ i) scanf("%d", &pts[i]);
		build(1, n, 1); int l, r; char opt;
		for(int i = 1; i <= m; ++ i) {
			std :: cin >> opt;
			scanf("%d %d",&l,&r);
			if(opt == 'U') data(l,1,r);
			else printf("%d\n",Ask(l,r,1));
		}
	}
	return 0;
}