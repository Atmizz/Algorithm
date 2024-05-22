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
const int N = 1010;
int a[N], b[N], n, k, ans;
void solve() {
  std :: cin >> n >> k;
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> a[i];
  }
  
  auto check = [=](int x) -> bool {
    for(int i = 1; i <= n; ++ i) {
      for(int j = 1; j <= n; ++ j) {
        b[j] = a[j];
      }
      if(a[i] >= x) return true;
      if(k - (x - a[i]) < 0) continue;
      int res = k - (x - a[i]), y = x; y --;
      for(int j = i + 1; j <= n; ++ j) {
        if(b[j] >= y) return true;
        res -= (y - b[j]); y --;
        if(res < 0) break;
      }
    }
    return false;
  };

  int l = 1, r = 2e8, ans;
  while(l <= r) {
    int mid = (l + r) >> 1;
    if(check(mid)) {
      l = mid + 1;
      ans = mid;
    } else {
      r = mid - 1;
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