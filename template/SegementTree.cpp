#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define sz(x) (int)x.size()
#define mk std :: make_pair
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << '\n';
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
typedef unsigned long long ull;
template <class T>
T max(T a, T b) {
	return a > b ? a : b;
}
template <class T>
T min(T a, T b) {
	return a < b ? a : b;
}
template <class T>
T abs(T a) {
	return a < 0 ? -a : a;
}
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e6 + 2;
struct Segment {
  i64 sum, lz;
  int l, r;
}t[N<<2];
int n, m;
i64 a[N];
inline void pushUp(int k) {
  t[k].sum = t[ls].sum + t[rs].sum;
}
inline void pushDown(int k) {
  t[ls].lz += t[k].lz;
  t[ls].sum += t[k].lz * (t[ls].r - t[ls].l + 1);
  t[rs].lz += t[k].lz;
  t[rs].sum += t[k].lz * (t[rs].r - t[rs].l + 1);
  t[k].lz = 0;
}
void build(int l, int r, int k) {
  t[k].l = l; t[k].r = r;
  if(l == r) {
    t[k].sum = a[l];
    return ;
  }
  int mid = (l + r) >> 1;
  build(l, mid, ls);
  build(mid+1, r, rs);
  pushUp(k);
}
void modify(int l, int r, int k, i64 x) {
  if(l <= t[k].l && r >= t[k].r) {
    t[k].sum += x * (t[k].r - t[k].l + 1);
    t[k].lz += x;
    return ;
  }
  int mid = (t[k].l + t[k].r) >> 1;
  if(t[k].lz) pushDown(k);
  if(l <= mid) modify(l, r, ls, x);
  if(r > mid) modify(l, r, rs, x);
  pushUp(k);
}
i64 query(int l, int r, int k) {
  if(t[k].l >= l && t[k].r <= r) {
  	return t[k].sum;
  }
  int mid = (t[k].l + t[k].r) >> 1;
  i64 sum = 0;
  if(t[k].lz) pushDown(k);
  if(l <= mid) sum += query(l, r, ls);
  if(r > mid) sum += query(l, r, rs);
  return sum;
}
void solve() {
	std :: cin >> n >> m;
  for(int i = 1; i <= n; ++ i) {
  	std :: cin >> a[i];
  }
  build(1, n, 1);
  for(int i = 1; i <= m; ++ i) {
    int opt, l, r;
    i64 x;
    std :: cin >> opt >> l >> r;
    if(opt == 1) {
      std :: cin >> x;
      modify(l, r, 1, x);
    } else {
    	std :: cout << query(l, r, 1) << nl;
    }
  }
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	//std :: cin >> _; 
	while(_ --) solve();
	return 0;
}