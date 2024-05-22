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
const int N = 1e5 + 20;
struct Node {
	int l, r, lz[20], biry[20];
}t[N<<2];
int n, a[N], m;
void pushUp(int k, int pos) {
	t[k].biry[pos] = t[ls].biry[pos] + t[rs].biry[pos];
}
void pushDown(int k, int pos) {
	if(t[k].lz[pos] == 1) {
		t[ls].biry[pos] = t[ls].r - t[ls].l + 1 - t[ls].biry[pos];
		t[rs].biry[pos] = t[rs].r - t[rs].l + 1 - t[rs].biry[pos];
	}
	t[ls].lz[pos] ^= t[k].lz[pos];
	t[rs].lz[pos] ^= t[k].lz[pos];
	t[k].lz[pos] = 0;
}
void build(int l, int r, int k) {
	t[k].l = l; t[k].r = r;
	if(l == r) {
		for(int i = 0; i < 20; ++ i)
			t[k].biry[i] = (a[l] >> i) & 1;
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, ls); build(mid+1, r, rs);
	for(int i = 0; i < 20; ++ i)
		pushUp(k, i);
}
void modifyXor(int l, int r, int k, int pos) {
	if(t[k].l >= l && t[k].r <= r) {
		t[k].biry[pos] = t[k].r - t[k].l + 1 - t[k].biry[pos];
		t[k].lz[pos] ^= 1;
		return ;
	}
	pushDown(k, pos);
	int mid = (t[k].l + t[k].r) >> 1;
	if(l <= mid) modifyXor(l, r, ls, pos);
	if(r > mid) modifyXor(l, r, rs, pos);
	pushUp(k, pos);
}
i64 query(int l, int r, int k, int pos) {
	if(l <= t[k].l && t[k].r <= r)
		return (i64)t[k].biry[pos] * (1 << pos);
	pushDown(k, pos);
	int mid = (t[k].l + t[k].r) >> 1;
	i64 sum = 0;
	if(l <= mid) sum += query(l, r, ls, pos);
	if(r > mid) sum += query(l, r, rs, pos);
	return sum;
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	build(1, n, 1);
	std :: cin >> m;
	while(m --) {
		int opt, l, r, x;
		std :: cin >> opt >> l >> r;
		if(opt == 1) {
			i64 ans = 0;
			for(int i = 0; i < 20; ++ i)
				ans += query(l, r, 1, i);
			std :: cout << ans << endl;
		}
		else {
			std :: cin >> x;
			for(int i = 0; i < 20; ++ i)
				if((x >> i) & 1) modifyXor(l, r, 1, i);
		}
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