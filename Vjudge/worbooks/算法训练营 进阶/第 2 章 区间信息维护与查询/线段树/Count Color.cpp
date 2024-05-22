#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <stack>
#include <cmath>
#include <bitset>
#include <complex>
#include <cstdlib>
#include <set>
#include <cstring>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
typedef long long i64;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 20;
int L, T, O;
struct Node {
	int l, r, lz, col;
}t[N<<2];
void pushUp(int k) {
	t[k].col = t[ls].col | t[rs].col;
}
void pushDown(int k) {
	t[ls].col = t[rs].col = t[k].lz;
	t[ls].lz = t[rs].lz = t[k].lz;
	t[k].lz = 0;
}
void build(int l, int r, int k) {
	t[k].l = l; t[k].r = r;
	if(l == r) {
		t[k].col = 2;
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, ls); build(mid+1, r, rs);
	pushUp(k);
}
void modify(int l, int r, int k, int x) {
	if(t[k].l >= l && t[k].r <= r) {
		t[k].col = t[k].lz = 1 << x;
		return ;
	}
	if(t[k].lz != 0) pushDown(k);
	int mid = (t[k].l + t[k].r) >> 1;
	if(l <= mid) modify(l, r, ls, x);
	if(r > mid) modify(l, r, rs, x);
	pushUp(k);
}
int query(int l, int r, int k) {
	if(t[k].l >= l && t[k].r <= r) return t[k].col;
	if(t[k].lz != 0) pushDown(k);
	int mid = (t[k].l + t[k].r) >> 1, sum = 0;
	if(l <= mid) sum |= query(l, r, ls);
	if(r > mid) sum |= query(l, r, rs);
	return sum;
}
int cal(int x) {
	int sum = 0;
	while(x) {
		if(x & 1) sum ++;
		x >>= 1;
	} return sum;
}
void solve() {
	scanf("%d %d %d", &L, &T, &O);
	build(1, L, 1);
	while(O --) {
		char ch[2]; int l, r, x;
		scanf("%s", ch);
		scanf("%d %d", &l, &r);
		if(l > r) std :: swap(l, r);
		// deb(ch[0]);
		if(ch[0] == 'C') {
			scanf("%d", &x);
			// deb(x);
			modify(l, r, 1, x);
		} else printf("%d\n", cal(query(l, r, 1)));
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
  solve();
	return 0;
}