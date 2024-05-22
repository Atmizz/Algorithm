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
	int l, r, lcnt, rcnt, cnt;
	char lch, rch;
}t[N<<2];
int n, m;
void pushUp(int k) {
	t[k].lch = t[ls].lch; t[k].rch = t[rs].rch;
	t[k].lcnt = t[ls].lcnt; t[k].rcnt = t[rs].rcnt;
	t[k].cnt = std :: max(t[ls].cnt, t[rs].cnt);
	if(t[ls].rch != t[rs].lch) {
		t[k].cnt = std :: max(t[ls].rcnt + t[rs].lcnt, t[k].cnt);
		if(t[ls].lcnt == t[ls].r - t[ls].l + 1) t[k].lcnt += t[rs].lcnt;
		if(t[rs].rcnt == t[rs].r - t[rs].l + 1) t[k].rcnt += t[ls].rcnt;
		t[k].cnt = std :: max(t[k].cnt, std :: max(t[k].lcnt, t[k].rcnt));
	} 
}
void build(int l, int r, int k) {
	t[k].l = l; t[k].r = r;
	if(l == r) {
		t[k].lch = t[k].rch = 'L';
		t[k].lcnt = t[k].rcnt = 1;
		return ;
	} int mid = (l + r) >> 1;
	build(l, mid, ls); build(mid+1, r, rs);
	pushUp(k);
}
void modify(int l, int r, int k) {
	if(t[k].l >= l && t[k].r <= r) {
		if(t[k].lch == 'L') t[k].lch = t[k].rch = 'R';
		else t[k].lch = t[k].rch = 'L';
		return ;
	} int mid = (t[k].l + t[k].r) >> 1;
	if(l <= mid) modify(l, r, ls);
	if(r > mid) modify(l, r, rs);
	pushUp(k);
}
void solve() {
	std :: cin >> n >> m;
	build(1, n, 1);
	for(int i = 1; i <= m; ++ i) {
		int x; std :: cin >> x;
		modify(x, x, 1);
		std :: cout << t[1].cnt << endl;
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