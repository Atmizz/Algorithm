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
int n, k, a[N];
i64 sum[N];
void solve() {
  std :: cin >> n >> k;
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> a[i];
    sum[i] = sum[i-1] + a[i];
  }
  i64 ans = -LLINF;
  if(k <= n) {
    for(int i = 1; i <= n; ++ i) {
      if(i >= k) {
        ans = std :: max(ans, sum[i] - sum[i-k] + 1LL * (k - 1) * k / 2);
      }
    }
  } else {
    ans = sum[n] + 1LL * n * k - 1LL * n * (n + 1) / 2;
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