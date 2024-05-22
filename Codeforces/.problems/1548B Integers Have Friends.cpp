#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
#define int long long
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e6 + 20;
int n;
i64 gcd(i64 a, i64 b) {
	return !b ? a : gcd(b, a % b);
}
struct segmentTree {
	int l, r;
	i64 Gcd;
}t[N<<2];
i64 a[N], b[N];
void build(int l, int r, int k) {
	t[k].l = l; t[k].r = r;
	if(l == r) {
		t[k].Gcd = b[l];
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, ls);
	build(mid+1, r, rs);
	t[k].Gcd = gcd(t[ls].Gcd, t[rs].Gcd);
}
i64 query(int l, int r, int k) {
	if(t[k].l >= l && t[k].r <= r) {
		return t[k].Gcd;
	}
	i64 Gcd = -1;
	int mid = (t[k].l + t[k].r) >> 1;
	if(l <= mid) {
		Gcd = query(l, r, ls);
	}
	if(r > mid) {
		if(Gcd == -1) {
			Gcd = query(l, r, rs);
		} else {
			Gcd = gcd(query(l, r, rs), Gcd);
		}
	}
	return Gcd;
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	for(int i = 1; i <= n; ++ i) {
		b[i] = std :: abs(a[i] - a[i-1]);
	}
	if(n == 1) {
		std :: cout << 1 << '\n';
		return ;
	}
	build(1, n, 1);
	int l = 2, r = 2, ans = 2;
	if(b[2] == 1) {
		ans = 1;
	}
	while(r < n) {
		r ++;
		if(query(l, r, 1) == 1) {
			l ++;
		}
		if(query(l, r, 1) == 1) {
			ans = std :: max(ans, r - l + 1);
		} else {
			ans = std :: max(ans, r - l + 2);
		}
	}
	std :: cout << ans << '\n';
}
signed main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}