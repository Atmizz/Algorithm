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
const int N = 1e5 + 20;
int n;
i64 k, a[N];
struct Node {
  int l, r;
  i64 sum[31];
}t[N<<2];
void build(int l, int r, int k) {
  t[k].l = l; t[k].r = r;
  if(l == r) {
    t[k].sum[0] = a[l];
    for(int i = 1; i <= 30; ++ i) {
      t[k].sum[i] = t[k].sum[i-1] / 2;
    }
    return ;
  }
  int mid = (l + r) >> 1;
  build(l, mid, ls); build(mid + 1, r, rs);
  for(int i = 0; i <= 30; ++ i) {
    t[k].sum[i] = t[ls].sum[i] + t[rs].sum[i];
  }
}
i64 query(int l, int r, int k, int x) {
  if(l > r) return 0;
  if(t[k].l >= l && t[k].r <= r) {
    return t[k].sum[x];
  }
  int mid = (t[k].l + t[k].r) >> 1;
  i64 s = 0;
  if(l <= mid) s += query(l, r, ls, x);
  if(r > mid) s += query(l, r, rs, x);
  return s;
}
void solve() {
  std :: cin >> n >> k;
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> a[i];
  }
  build(1, n, 1);
  i64 ans = 0;
  for(int i = 0; i <= n; ++ i) {
    i64 sum = query(1, i, 1, 0) - 1LL * i * k;
    int res = 1;
    for(int j = i + 1; j <= std :: min(i + 29, n); ++ j) {
      sum += query(j, j, 1, res);
      res ++;
    }
    ans = std :: max(ans, sum);
  }
  std :: cout << ans << '\n';
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