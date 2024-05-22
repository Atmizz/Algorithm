#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e5 + 20;
struct Node {
	int l, r;
	double sinx, cosx;
	double lz;
}t[N<<2];
int n, m;
double a[N];
void pushUp(int k) {
	t[k].sinx = t[ls].sinx + t[rs].sinx;
	t[k].cosx = t[ls].cosx + t[rs].cosx;
}
void update(int k, double x) {
	double sinx = t[k].sinx, cosx = t[k].cosx;
	t[k].sinx = sinx * std :: cos(x) + cosx * std :: sin(x);
	t[k].cosx = cosx * std :: cos(x) - sinx * std :: sin(x);
}
void pushDown(int k) {
	update(ls, t[k].lz);
	update(rs, t[k].lz);
	t[ls].lz += t[k].lz, t[rs].lz += t[k].lz;
	t[k].lz = 0;
}
void build(int l, int r, int k) {
	t[k].l = l; t[k].r = r; 
	if(l == r) {
		t[k].sinx = std :: sin(a[l]);
		t[k].cosx = std :: cos(a[l]);
		// deb(t[k].sinx); deb(t[k].cosx);
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, ls); build(mid+1, r, rs);
	pushUp(k);
}
void modify(int l, int r, int k, double x) {
	if(t[k].l >= l && t[k].r <= r) {
		t[k].lz += x;
		update(k, x);
		return ;
	} int mid = (t[k].l + t[k].r) >> 1;
	if(t[k].lz != 0) pushDown(k);
	if(l <= mid) modify(l, r, ls, x);
	if(r > mid) modify(l, r, rs, x);
	pushUp(k);
}
double query(int l, int r, int k) {
	if(t[k].l >= l && t[k].r <= r) return t[k].sinx;
	int mid = (t[k].l + t[k].r) >> 1;
	if(t[k].lz != 0) pushDown(k);
	double sum = 0; 
	if(l <= mid) sum += query(l, r, ls);
	if(r > mid) sum += query(l, r, rs);
	return sum;
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	build(1, n, 1);
	std :: cin >> m;
	for(int i = 1; i <= m; ++ i) {
		int opt, l, r; double x;
		std :: cin >> opt >> l >> r;
		 if(opt == 1) {
		 	std :: cin >> x;
		 	modify(l, r, 1, x);
		 } 
		else printf("%.1lf\n", query(l, r, 1));
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