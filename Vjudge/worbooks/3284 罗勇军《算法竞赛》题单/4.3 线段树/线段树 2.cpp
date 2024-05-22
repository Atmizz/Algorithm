#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;

inline int read() {
	int s = 0, f = 1; char ch = gc;
	for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = - 1;
	for(; ch >= '0' && ch <= '9'; ch = gc)
		s = (s << 1) + (s << 3) + (ch ^ 48);
	return s * f;
}
inline int min(int a, int b) { return a < b ? a : b;}
inline int max(int a, int b) { return a > b ? a : b;}
inline int abs(int a) { return a < 0 ? -a : a;}
const int MaxN = 1e6 + 20;
const int INF = 2147483647;
int Mod = 571373;
struct Node {
	int l, r;
	ll sum, lzM, lzP;
}t[MaxN << 1];
void pushUp(int k) {
	t[k].sum = (t[ls].sum + t[rs].sum) % Mod;
}
void pushDown(int k) {
	t[ls].lzM = (t[ls].lzM * t[k].lzM) % Mod;
	t[ls].lzP = (t[ls].lzP * t[k].lzM + t[k].lzP) % Mod;
	t[rs].lzM = (t[rs].lzM * t[k].lzM) % Mod;
	t[rs].lzP = (t[rs].lzP * t[k].lzM + t[k].lzP) % Mod;
	t[ls].sum = (t[ls].sum * t[k].lzM) % Mod;
	t[ls].sum = (t[ls].sum + t[k].lzP * (t[ls].r - t[ls].l + 1)) % Mod;
	t[rs].sum = (t[rs].sum * t[k].lzM) % Mod;
	t[rs].sum = (t[rs].sum + t[k].lzP * (t[rs].r - t[rs].l + 1)) % Mod;
	t[k].lzM = 1; t[k].lzP = 0;
}
ll a[MaxN];
int n, m, p;
void build(int l, int r, int k) {
	t[k].l = l; t[k].r = r; t[k].lzM = 1; t[k].lzP = 0;
	if(l == r) {
		t[k].sum = a[l] % Mod;
		return ;
	} int mid = (l + r) >> 1;
	build(l, mid, ls); build(mid+1, r, rs);
	pushUp(k);
}
void Mt(int l, int r, int k, int x) {
	if(t[k].l >= l && t[k].r <= r) {
		t[k].lzP = (t[k].lzP * x) % Mod;
		t[k].lzM = (t[k].lzM * x) % Mod;
		t[k].sum = (t[k].sum * x) % Mod;
		return ;
	} pushDown(k);
	int mid = (t[k].l + t[k].r) >> 1;
	if(l <= mid) Mt(l, r, ls, x);
	if(r > mid) Mt(l, r, rs, x);
	pushUp(k);
}
void Ps(int l, int r, int k, int x) {
	if(t[k].l >= l && t[k].r <= r) {
		t[k].lzP = (t[k].lzP + x) % Mod;
		t[k].sum = (t[k].sum + x * (t[k].r - t[k].l + 1)) % Mod;
		return ;
	} if(t[k].lzM != 1 || t[k].lzP) pushDown(k);
	int mid = (t[k].l + t[k].r) >> 1;
	if(l <= mid) Ps(l, r, ls, x);
	if(r > mid) Ps(l, r, rs, x);
	pushUp(k);
}
ll Query(int l, int r, int k) {
	if(t[k].l >= l && t[k].r <= r) return t[k].sum % Mod;
	pushDown(k);
	int mid = (t[k].l + t[k].r) >> 1; ll sum = 0;
	if(l <= mid) sum = (sum + Query(l, r, ls)) % Mod;
	if(r > mid) sum = (sum + Query(l, r, rs)) % Mod;
	return sum % Mod;
}
int main() {
	n = read(), m = read(), Mod = read();
	for(int i = 1; i <= n; ++ i) scanf("%lld", &a[i]);
	build(1, n, 1);
	for(int i = 1; i <= m; ++ i) {
		int opt = read(), l = read(), r = read(), x;
		if(opt == 3) printf("%lld\n", Query(l, r, 1) % Mod);
		else {
			x = read();
			if(opt == 1) Mt(l, r, 1, x);
			else Ps(l, r, 1, x);
		}
	}
	return 0;
}
