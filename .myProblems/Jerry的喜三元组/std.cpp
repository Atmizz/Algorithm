#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e6 + 20;
struct SegmentTree {
	int l, r, sum;
}t[N<<2];
int n, a[N], b[N], c[N], d[N];
void build(int l, int r, int k) {
	t[k].l = l; t[k].r = r;
	t[k].sum = 0;
	if(l == r) {
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, ls);
	build(mid+1, r, rs);
}
void modify(int p, int k) {
	t[k].sum ++;
	if(t[k].l == t[k].r) {
		return ;
	}
	int mid = (t[k].l + t[k].r) >> 1;
	if(p <= mid) {
		modify(p, ls);
	} else {
		modify(p, rs);
	}
}
int query(int l, int r, int k) {
	if(t[k].l >= l && t[k].r <= r) {
		return t[k].sum;
	}
	int mid = (t[k].l + t[k].r) >> 1;
	int sum = 0;
	if(l <= mid) {
		sum += query(l, r, ls);
	}
	if(r > mid) {
		sum += query(l, r, rs);
	}
	return sum;
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		b[i] = a[i];
	}
	std :: sort(b + 1, b + 1 + n);
	for(int i = 1; i <= n; ++ i) {
		a[i] = std :: lower_bound(b + 1, b + 1 + n, a[i]) - b;
	}
	build(1, n, 1);
	for(int i = 1; i <= n; ++ i) {
		modify(a[i], 1);
		c[i] = (a[i] + 1 > n) ? 0 : query(a[i]+1, n, 1);
	}
	build(1, n, 1);
	for(int i = n; i >= 1; -- i) {
		modify(a[i], 1);
		d[i] = (a[i] - 1 < 1) ? 0 : query(1, a[i]-1, 1);
	}
	i64 ans = 0;
	for(int i = 1; i <= n; ++ i) {
		// deb(c[i]);
		// deb(d[i])
		ans += 1LL * c[i] * d[i];
	}
	std :: cout << ans ;
}
int main() {
	// freopen("5.in", "r", stdin);
	// freopen("5.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}