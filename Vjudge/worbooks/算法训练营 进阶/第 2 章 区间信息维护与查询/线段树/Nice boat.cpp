#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 20;
struct Node {
	int l, r, maxx, lz;
}t[N<<2];
int n, q, a[N];
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
void pushUp(int k) {
	t[k].maxx = std :: max(t[ls].maxx, t[rs].maxx);
	t[k].lz = (t[ls].lz == t[rs].lz) ? t[ls].lz : 0;
}
void pushDown(int k) {
	t[ls].lz = t[ls].maxx = t[k].lz;
	t[rs].lz = t[rs].maxx = t[k].lz;
	t[k].lz = 0;
}
void build(int l, int r, int k) {
	t[k].l = l; t[k].r = r; t[k].lz = 0, t[k].maxx = 0;
	if(l == r) {
		t[k].maxx = t[k].lz = a[l];
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, ls); build(mid+1, r, rs);
	pushUp(k);
}
void change1(int l, int r, int k, int x) {
	if(t[k].l >= l && t[k].r <= r) {
		t[k].lz = t[k].maxx = x;
		return ;
	}
	if(t[k].lz != 0) pushDown(k);
	int mid = (t[k].l + t[k].r) >> 1;
	if(l <= mid) change1(l, r, ls, x);
	if(r > mid) change1(l, r, rs, x);
	pushUp(k);
}
void change2(int l, int r, int k, int x) {
	if(t[k].maxx <= x) return ;
	if(t[k].l >= l && t[k].r <= r && t[k].lz != 0) {
		t[k].lz = t[k].maxx = gcd(t[k].lz, x);
		return ;
	}
	if(t[k].lz != 0) pushDown(k);
	int mid = (t[k].l + t[k].r) >> 1;
	if(l <= mid) change2(l, r, ls, x);
	if(r > mid) change2(l, r, rs, x);
	pushUp(k);
}
void print(int l, int r, int k) {
	if(t[k].l == t[k].r) {
		std :: cout << t[k].maxx << ' ';
		return ;
	}
	if(t[k].lz != 0) pushDown(k);
	int mid = (t[k].l + t[k].r) >> 1;
	print(l, mid, ls); print(mid+1, r, rs);
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	build(1, n, 1);
	std :: cin >> q;
	while(q --) {
		int opt, l, r, x;
		std :: cin >> opt >> l >> r >> x;
		if(opt == 1) change1(l, r, 1, x);
		else if(opt == 2) change2(l, r, 1, x);
	}
	print(1, n, 1);
	std :: cout << endl;
}
int main() {
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
