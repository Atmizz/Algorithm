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
  int l, r;
  i64 sum, lz;
}t[N<<2];
int n, m;
i64 a[N];
void pushUp(int k) {
  t[k].sum = t[ls].sum + t[rs].sum;
}
void pushDown(int k) {
  t[ls].lz += t[k].lz;
  t[rs].lz += t[k].lz;
  t[ls].sum += t[k].lz * (t[ls].r - t[ls].l + 1);
  t[rs].sum += t[k].lz * (t[rs].r - t[rs].l + 1);
  t[k].lz = 0;
}
void build(int l, int r, int k) {
  t[k].l = l; t[k].r = r;
  if(l == r) return ;
  int mid = (t[k].l + t[k].r) >> 1;
  build(l, mid, ls); build(mid+1, r, rs);
}
void modify(int l, int r, int k, i64 x) {
  if(t[k].l >= l && t[k].r <= r) {
    t[k].lz += x;
    t[k].sum += x * (t[k].r - t[k].l + 1);
    return ;
  }
  if(t[k].lz) pushDown(k);
  int mid = (t[k].l + t[k].r) >> 1;
  if(l <= mid) modify(l, r, ls, x);
  if(r > mid) modify(l, r, rs, x);
  pushUp(k);
}
i64 query(int l, int r, int k) {
  if(t[k].l >= l && t[k].r <= r) return t[k].sum;
  if(t[k].lz) pushDown(k);
  int mid = (t[k].l + t[k].r) >> 1; i64 sum = 0;
  if(l <= mid) sum += query(l, r, ls);
  if(r > mid) sum += query(l, r, rs);
  return sum;
}
void solve() {
  std :: cin >> n >> m; build(1, n, 1);
  for(int i = 1; i <= n; ++ i)
    std :: cin >> a[i];
  for(int i = 1; i <= m; ++ i) {
    int opt, l, r; i64 k, d;
    std :: cin >> opt >> l;
    if(opt == 1) {
      std :: cin >> r >> k >> d;
      modify(l, l, 1, k);
      if(r - l > 0) modify(l+1, r, 1, d);
      if(r < n) modify(r+1, r+1, 1, (k + d * (r - l)) * (-1));
    } else std :: cout << a[l] + query(1, l, 1) << endl;
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