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
const int N = 3e5 + 20;
const int M = 1e9;
struct Node {
	int l, r, cnt, lz;
}t[N<<5];
int rt, idx;
void pushUp(int k) {
	t[k].cnt = t[t[k].l].cnt + t[t[k].r].cnt;
}
void pushDown(int k, int l, int r) {
	if(t[k].lz == -1) return ;
	if(!t[k].l) t[k].l = ++ idx;
	if(!t[k].r) t[k].r = ++ idx;
	t[t[k].l].lz = t[t[k].r].lz = t[k].lz;
	int mid = (l + r) >> 1;
	t[t[k].l].cnt = (mid - l + 1) * t[k].lz;
	t[t[k].r].cnt = (r - mid) * t[k].lz;
	t[k].lz = -1;
}
void update(int &k, int l, int r, int ul, int ur, int x) {
	if(!k) k = ++ idx;
	if(l >= ul && r <= ur) {
		t[k].lz = x;
		t[k].cnt = (r - l + 1) * x;
		return ;
	}
	pushDown(k, l, r);
	int mid = (l + r) >> 1;
	if(ul <= mid) update(t[k].l, l, mid, ul, ur, x);
	if(ur > mid) update(t[k].r, mid+1, r, ul, ur, x);
	pushUp(k);
}
int query(int k, int l, int r, int ql, int qr) {
	if(!k) return 0;
	if(l >= ql && r <= qr) return t[k].cnt;
	pushDown(k, l, r);
	int mid = (l + r) >> 1, cnt = 0;
	if(ql <= mid) cnt += query(t[k].l, l, mid, ql, qr);
	if(qr > mid) cnt += query(t[k].r, mid+1, r, ql, qr);
	return cnt;
}
void solve() {
	int n, q;
	std :: cin >> n >> q;
	while(q --) {
		int l, r, opt;
		std :: cin >> l >> r >> opt;
		if(opt == 1) update(rt, 1, M, l, r, 1);
		else update(rt, 1, M, l, r, 0);
		std :: cout << n - query(rt, 1, M, 1, n) << endl;
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