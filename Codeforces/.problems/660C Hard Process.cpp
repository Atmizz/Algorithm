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
const int N = 3e5 + 20;
int n, k, a[N], sum[N];
void solve() {
  std :: cin >> n >> k;
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> a[i];
    sum[i] = sum[i-1] + a[i];
  }
  int l = 0, r = n, ans;
  auto check = [=](int x) -> bool {
    for(int i = x; i <= n; ++ i) {
      if(x - (sum[i] - sum[i-x]) <= k) {
        return true;
      }
    }
    return false;
  };
  while(l <= r) {
    int mid = (l + r) >> 1;
    if(check(mid)) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  for(int i = ans; i <= n; ++ i) {
    if(ans - (sum[i] - sum[i-ans]) <= k) {
      std :: cout << ans << '\n';
      for(int j = 1; j <= n; ++ j) {
        if(j <= i - ans || j > i) {
          std :: cout << a[j] << ' ';
        } else {
          std :: cout << 1 << ' ';
        }
      }
      return ;
    }
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