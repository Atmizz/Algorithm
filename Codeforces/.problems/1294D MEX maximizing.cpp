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
const int N = 4e5 + 20;
struct Node {
	int l, r, minn, id;
}t[N<<2];
int n, m;
void pushUp(int k) {
	if(t[ls].minn <= t[rs].minn) t[k].minn = t[ls].minn, t[k].id = t[ls].id;
	else t[k].minn = t[rs].minn, t[k].id = t[rs].id;
}
void build(int l, int r, int k) {
	t[k].l = l; t[k].r = r;
	if(l == r) {
		t[k].id = l;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, ls); build(mid + 1, r, rs);
	pushUp(k);
}
void modify(int k, int x) {
	if(t[k].l == t[k].r) {
		t[k].minn ++;
		return ;
	}
	int mid = (t[k].l + t[k].r) >> 1;
	if(x <= mid) modify(ls, x);
	else modify(rs, x);
	pushUp(k);
}
int query(int l, int r, int k) {
	if(l <= t[k].l && t[k].r <= r) return t[k].minn;
	int mid = (t[k].l + t[k].r) >> 1, minn = INF;
	if(l <= mid) minn = std :: min(minn, query(l, r, ls));
	if(r > mid) minn = std :: min(minn, query(l, r, rs));
	return minn;
}
int find(int l, int r, int k, int x) {
	if(t[k].l >= l && t[k].r <= r) {
		if(t[k].minn == x) return t[k].id;
		return INF;
	}
	int mid = (t[k].l + t[k].r) >> 1, id = INF;
	if(l <= mid) id = std :: min(id, find(l, r, ls, x));
	if(r > mid) id = std :: min(id, find(l, r, rs, x));
	return id;
}
void solve() {
	std :: cin >> n >> m;
	build(1, m, 1);
	for(int i = 0; i < n; ++ i) {
		int x, ans = i + 1; std :: cin >> x;
		modify(1, x % m + 1);
		
		int y = i % m + 1;
		int z = i / m;
		z ++;

		// deb(x % m + 1);
		// std :: cout << "i : " << i << " y : " << y << " z : " << z << '\n';

		int res = query(1, y, 1), r;
		// DEB
		// deb(res);
		if(res < z) {
			// deb(r)
			r = find(1, y, 1, res);
			ans = res * m + r - 1;
		}
		if(y != m) {
			z --;
			res = query(y + 1, m, 1);
			// DEB
			// deb(res);
			if(res < z) {
				// deb(query(3, 3, 1));
				r = find(y + 1, m, 1, res);
				// deb(r);
				ans = std :: min(ans, res * m + r - 1);
			}
		}
		std :: cout << ans << '\n';
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