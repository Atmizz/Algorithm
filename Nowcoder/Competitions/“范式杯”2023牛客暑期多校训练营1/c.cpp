#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
inline int read() {
	int s = 0, f = 1; char ch = gc;
	for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
	for(; ch >= '0' && ch <= '9'; ch = gc)
		s = (s << 1) + (s << 3) + (ch ^ 48);
	return s * f;
}
inline int abs(int a) {return a < 0 ? -a : a;}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 1e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
struct Node {
	int l, r, num;
	double sum;
}t[MaxN << 2];
int n, m, ans;
double K;
void pushup(int k) {
	t[k].num = t[ls].num + t[rs].num;
}
void build(int l, int r, int k) {
	t[k].l = l; t[k].r = r;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	build(l, mid, ls); build(mid+1, r, rs);
}
void Modify(int l, int r, int k, double x) {
	if(t[k].l == t[k].r) {
		t[k].sum += x;
		if(t[k].sum / K >= 1.0) t[k].num = 1;
		return ;
	} int mid = (t[k].l + t[k].r) >> 1;
	if(l <= mid) Modify(l, r, ls, x);
	if(r > mid) Modify(l, r, rs, x);
	pushup(k);
}
int query(int l, int r, int k) {
	if(l <= t[k].l && t[k].r <= r) return t[k].num;
	int mid = (t[k].l + t[k].r) >> 1, num = 0;
	if(l <= mid) num += query(l, r, ls);
	if(r > mid) num += query(l, r, rs);
	return num;
}
void Update(int l, int r, int k) {
	if(t[k].l == t[k].r) {
		t[k].sum -= K;
		if(t[k].sum / K < 1.0) t[k].num = 0;
		return ;
	} int mid = (t[k].l + t[k].r) >> 1;
	if(l <= mid) Update(l, r, ls);	
	if(r > mid) Update(l, r, rs);
	pushup(k);
}
void solve() {
	n = read(); m = read(); scanf("%lf", &K);
	build(1, n, 1);
	for(int i = 1; i <= m; ++ i) {
		int opt = read(), l = read(), r = read();
		double x;
		if(opt == 1) scanf("%lf", &x), Modify(l, r, 1, x);
		else {
			ans += query(l, r, 1);

			std :: cout << "query : " << query(l, r, 1) << '\n';
			Update(l, r, 1);
		}
		for(int j = 1; j <= n; ++ j)
			std :: cout << j << ' ' << query(j, j, 1) << '\n';
	} std :: cout << ans;
}
int main() {
	solve();
	return 0;
}
