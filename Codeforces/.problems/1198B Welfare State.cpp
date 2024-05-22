#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl '\n'
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e5 + 20;
int n, a[N], m, ans[N];
struct Node {
  int l, r, sum;
}t[N<<2];
void pushDown(int k) {
  if(t[ls].sum < t[k].sum) {
    t[ls].sum = t[k].sum;
  }
  if(t[rs].sum < t[k].sum) {
    t[rs].sum = t[k].sum;
  }
  t[k].sum = -1;
}
void build(int l, int r, int k) {
  t[k].l = l; t[k].r = r;
  t[k].sum = -1;
  if(l == r) {
    t[k].sum = a[l];
    return ;
  }
  int mid = (l + r) >> 1;
  build(l, mid, ls);
  build(mid + 1, r, rs);
}
void update(int l, int r, int k, int x) {
  if(t[k].l == l && t[k].r == r) {
    t[k].sum = x;
    return ;
  }
  if(t[k].sum != -1) {
    pushDown(k);
  }
  int mid = (t[k].l + t[k].r) >> 1;
  if(l <= mid) {
    update(l, r, ls, x);
  }
  if(r > mid) {
    update(l, r, rs, x);
  }
}
int query(int l, int r, int k) {
  if(t[k].l == l && t[k].r == r) {
    return t[k].sum;
  }
  if(t[k].sum != -1) {
    pushDown(k);
  }
  int mid = (t[k].l + t[k].r) >> 1;
  if(l <= mid) {
    return query(l, r, ls);
  }
  if(r > mid) {
    return query(l, r, rs);
  }
}
void solve() {
  std :: cin >> n;
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> a[i];
  }
  build(1, n, 1);
  std :: cin >> m;
  while(m --) {
    int opt, p, x;
    std :: cin >> opt >> p;
    if(opt == 1) {
      std :: cin >> x;
      update(p, p, 1, x);
    } else {
      if(t[1].sum < p) {
        t[1].sum = p;
      }
    }
  }
  for(int i = 1; i <= n; ++ i) {
    std :: cout << query(i, i, 1) << ' ';
  }
}
int main() {
  //freopen("1.in", "r", stdin);
  //freopen("1.out", "w", stdout);
  std :: ios :: sync_with_stdio(false);
  std :: cin.tie(0);
  std :: cout.tie(0);
  int T = 1;
  // std :: cin >> T; 
  while(T --) solve();
  return 0;
}