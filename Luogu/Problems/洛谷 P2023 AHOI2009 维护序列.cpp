#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 20;
int n, m;
i64 p, a[N];
namespace SegmentTree {
	struct Node {
		int l, r;
		i64 sum, lz1, lz2;
	}t[N<<2];
	void PushUp(int k) {
		t[k].sum = (t[ls].sum + t[rs].sum) % p;
	}
	void PushDown(int k) {
		t[ls].sum = ((t[ls].sum * t[k].lz1) % p + t[k].lz2 * (t[ls].r - t[ls].l + 1)) % p;
		t[rs].sum = ((t[rs].sum * t[k].lz1) % p + t[k].lz2 * (t[rs].r - t[rs].l + 1)) % p;

		t[ls].lz1 = t[ls].lz1 * t[k].lz1 % p;
		t[rs].lz1 = t[rs].lz1 * t[k].lz1 % p;
		t[ls].lz2 = ((t[ls].lz2 * t[k].lz1) % p + t[k].lz2) % p;
		t[rs].lz2 = ((t[rs].lz2 * t[k].lz1) % p + t[k].lz2) % p;

		t[k].lz1 = 1; t[k].lz2 = 0;
	}
	void Build(int l, int r, int k) {
		t[k].l = l; t[k].r = r; t[k].lz1 = 1;
		if(l == r) {
			t[k].sum = a[l];
			return ;
		} int mid = (l + r) >> 1;
		Build(l, mid, ls); Build(mid+1, r, rs);
		PushUp(k);
	}
	void ModifyAdd(int l, int r, int k, i64 x) {
		if(l <= t[k].l && t[k].r <= r) {
			t[k].sum = (t[k].sum + (x * (t[k].r - t[k].l + 1) % p)) % p;
			t[k].lz2 = (t[k].lz2 + x) % p;
			return ;
		}
		PushDown(k);
		int mid = (t[k].l + t[k].r) >> 1;
		if(l <= mid) ModifyAdd(l, r, ls, x);
		if(r > mid) ModifyAdd(l, r, rs, x);
		PushUp(k);
	}
	void ModifyMultiply(int l, int r, int k, i64 x) {
		if(l <= t[k].l && t[k].r <= r) {
			t[k].sum = t[k].sum * x % p;
			t[k].lz1 = t[k].lz1 * x % p;
			t[k].lz2 = t[k].lz2 * x % p;
			return ;
		}
		PushDown(k);
		int mid = (t[k].l + t[k].r) >> 1;
		if(l <= mid) ModifyMultiply(l, r, ls, x);
		if(r > mid) ModifyMultiply(l, r, rs, x);
		PushUp(k);
	}
	i64 QuerySum(int l, int r, int k) {
		if(l <= t[k].l && t[k].r <= r) return t[k].sum % p;
		PushDown(k);
		int mid = (t[k].l + t[k].r) >> 1; i64 sum = 0;
		if(l <= mid) sum = (sum + QuerySum(l, r, ls)) % p;
		if(r > mid) sum = (sum + QuerySum(l, r, rs)) % p;
		return sum;
	}
}
void solve() {
	std :: cin >> n >> p;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	SegmentTree :: Build(1, n, 1);
	std :: cin >> m;
	for(int i = 1; i <= m; ++ i) {
		int opt, l, r; i64 x;
		std :: cin >> opt >> l >> r;
		if(opt == 1) {
			std :: cin >> x;
			SegmentTree :: ModifyMultiply(l, r, 1, x);
		} else if(opt == 2) {
			std :: cin >> x;
			SegmentTree :: ModifyAdd(l, r, 1, x);
		} else std :: cout << SegmentTree :: QuerySum(l, r, 1) << endl;
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