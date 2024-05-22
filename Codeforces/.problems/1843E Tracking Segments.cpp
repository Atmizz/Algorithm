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
int n, m, q, a[N], b[N], sum[N];
struct Segment {
  int l, r;
}line[N];
void solve() {
  std :: cin >> n >> m;
  for(int i = 1; i <= m; ++ i) {
    std :: cin >> line[i].l >> line[i].r;
  }
  std :: cin >> q;
  for(int i = 1; i <= q; ++ i) {
    std :: cin >> a[i];
  }

  auto check = [](int x) -> bool {
    for(int i = 1; i <= n; ++ i) {
      b[i] = 0;
    }
    for(int i = 1; i <= x; ++ i) {
      b[a[i]] = 1;
    }
    for(int i = 1; i <= n; ++ i) {
      sum[i] = sum[i-1] + b[i];
    }
    for(int i = 1; i <= m; ++ i) {
      if(sum[line[i].r] - sum[line[i].l-1] > (line[i].r - line[i].l + 1) / 2) {
        return true;
      }
    }
    return false;
  };

  if(!check(q)) {
    std :: cout << -1 << '\n';
    return ;
  }

  int l = 1, r = q, ans;
  while(l <= r) {
    int mid = (l + r) >> 1;
    if(check(mid)) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
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