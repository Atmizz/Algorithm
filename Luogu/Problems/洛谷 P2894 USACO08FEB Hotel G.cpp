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
const int N = 5e4 + 20;
struct Node {
	int l, r, cnt, lcnt, rcnt, lrm, rrm, lz;
}t[N<<2];
int n, m;
void pushUp(int k) {
	t[k].cnt = std :: max(t[ls].cnt, t[rs].cnt);
	t[k].lrm = t[ls].lrm; t[k].rrm = t[rs].rrm;
	t[k].lcnt = t[ls].lcnt; t[k].rcnt = t[rs].rcnt;
	if(t[ls].rrm == 0 && t[rs].lrm == 0) {
		t[k].cnt = std :: max(t[k].cnt, t[ls].rcnt + t[rs].lcnt);
		if(t[ls].lcnt == t[ls].r - t[ls].l + 1) t[k].lcnt += t[rs].lcnt;
		if(t[rs].rcnt == t[rs].r - t[rs].l + 1) t[k].rcnt += t[ls].rcnt;
	}
	t[k].cnt = std :: max(t[k].cnt, t[k].lcnt);
	t[k].cnt = std :: max(t[k].cnt, t[k].rcnt);
}
void pushDown(int k) {
	if(t[k].lz == 0) {
		t[ls].cnt = t[ls].lcnt = t[ls].rcnt = t[ls].r - t[ls].l + 1;
		t[rs].cnt = t[rs].lcnt = t[rs].rcnt = t[rs].r - t[rs].l + 1;
	} else {
		t[ls].cnt = t[ls].lcnt = t[ls].rcnt = 0;
		t[rs].cnt = t[rs].lcnt = t[rs].rcnt = 0;
	}
	t[ls].lrm = t[ls].rrm = t[rs].lrm = t[rs].rrm = t[k].lz;
	t[ls].lz = t[rs].lz = t[k].lz;
	t[k].lz = -1;
}
void build(int l, int r, int k) {
	t[k].l = l; t[k].r = r; t[k].lz = -1;
	if(l == r) {
		t[k].lcnt = t[k].rcnt = t[k].cnt = 1;
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, ls); build(mid+1, r, rs);
	pushUp(k);
}
void modify(int l, int r, int k, int x) {
	if(t[k].l >= l && t[k].r <= r) {
		t[k].lz = x;
		if(x == 0) t[k].cnt = t[k].lcnt = t[k].rcnt = t[k].r - t[k].l + 1;
		else t[k].cnt = t[k].lcnt = t[k].rcnt = 0;
		t[k].lrm = t[k].rrm = x;
		return ;
	}
	if(t[k].lz != -1) pushDown(k);
	int mid = (t[k].l + t[k].r) >> 1;
	if(l <= mid) modify(l, r, ls, x);
	if(r > mid) modify(l, r, rs, x);
	pushUp(k);
}
int query(int l, int r, int k, int x) {
	if(t[k].lz != -1) pushDown(k);
	int mid = (l + r) >> 1;
	if(t[k].l == t[k].r) return t[k].l;
	if(t[ls].cnt >= x) return query(l, mid, ls, x);
	else if(t[ls].rcnt + t[rs].lcnt >= x) return mid - t[ls].rcnt + 1;
	else return query(mid+1, r, rs, x);
}
void solve() {
	std :: cin >> n >> m;
	build(1, n, 1);
	while(m --) {
		int opt, x, y;
		std :: cin >> opt >> x;
		if(opt == 1) {
			if(t[1].cnt < x) {
				std :: cout << 0 << endl;
				continue;
			}
			int cnt = query(1, n, 1, x);
			std :: cout << cnt << endl;
			modify(cnt, cnt + x - 1, 1, 1);
		} else std :: cin >> y, modify(x, x + y - 1, 1, 0);
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