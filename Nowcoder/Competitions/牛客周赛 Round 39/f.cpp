#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 20;
std :: string sa, sb;
struct Node {
	int l, r, a[2], sum, lz[2];
}t[N<<2];
void pushUp(int k) {
	for(int i = 0; i < 2; ++ i) {
		t[k].a[i] = t[ls].a[i] + t[rs].a[i];
	}
	t[k].sum = t[ls].sum + t[rs].sum;
}
void pushDown(int k) {
	for(int i = 0; i < 2; ++ i) {
		if(t[k].lz[i]) {
			t[ls].lz[i] = t[rs].lz[i] = t[k].lz[i];
			t[ls].a[i] = t[ls].r - t[ls].l + 1;
			t[rs].a[i] = t[rs].r - t[rs].l + 1;
			t[ls].sum = std :: min(t[ls].a[0], t[ls].a[1]);
			t[rs].sum = std :: min(t[rs].a[0], t[rs].a[1]);
			t[k].lz[i] = 0;
		}
	}
}
void build(int l, int r, int k) {
	t[k].l = l; t[k].r = r;
	if(l == r) {
		t[k].a[0] = sa[l] == '1';
		t[k].a[1] = sb[l] == '1';
		t[k].sum = (t[k].a[0] == t[k].a[1] && t[k].a[0] == 1);
		return ;
	}
	int mid = l + r >> 1;
	build(l, mid, ls);
	build(mid+1, r, rs);
	pushUp(k);
}
void modify(int l, int r, int k, int type) {
	if(l <= t[k].l && t[k].r <= r) {
		t[k].a[type] = t[k].r - t[k].l + 1;
		t[k].lz[type] = 1;
		t[k].sum = std :: min(t[k].a[0], t[k].a[1]);
		// std :: cout << 
		return ;
	}
	int mid = (t[k].l + t[k].r) >> 1;
	pushDown(k);
	if(l <= mid) {
		modify(l, r, ls, type);
	} 
	if(r > mid) {
		modify(l, r, rs, type);
	}
	pushUp(k);
}
int query(int k) {
	// std :: cout << t[k].a[0] << ' ' << t[k].a[1] << '\n';
	return t[k].sum;
}
void solve() {
	int n, q;
	std :: cin >> n;
	std :: cin >> sa >> sb;
	sa = ')' + sa;
	sb = ')' + sb;
	build(1, n, 1);
	std :: cin >> q;
	while(q --) {
		char ch;
		int l, r;
		std :: cin >> ch >> l >> r;
		modify(l, r, 1, ch != 'A');
		std :: cout << query(1) << '\n';
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