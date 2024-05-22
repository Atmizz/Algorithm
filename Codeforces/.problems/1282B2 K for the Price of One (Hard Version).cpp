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
int n, p, k, a[N], res[N], dp[N], ans;
void solve() {
  std :: cin >> n >> p >> k;
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> a[i];
    res[i] = 0; dp[i] = 0;
  }
  res[0] = p; ans = 0;
  std :: sort(a + 1, a + 1 + n);
  for(int i = 1; i <= n; ++ i) {
    if(i < k) {
      if(res[i-1] >= a[i]) {
        dp[i] = dp[i-1] + 1;
        res[i] = res[i-1] - a[i];
      }
    } else {
      if(res[i-k] >= a[i]) {
        dp[i] = dp[i-k] + k;
        res[i] = res[i-k] - a[i];
      }
    }
    ans = std :: max(ans, dp[i]);
    // deb(i); deb(a[i]); deb(dp[i]);
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