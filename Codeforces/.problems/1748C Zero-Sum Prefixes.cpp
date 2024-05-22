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
int t = 1;
void solve() {
  int n, res = 0;
  std :: cin >> n;
  std :: map <i64, int> m;
  std :: vector <int> a(n + 1), lst(n + 1), dp(n + 1);
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> a[i];
  }
  for(int i = 1; i <= n; ++ i) {
    lst[i] = lst[i-1];
    if(a[i] == 0) lst[i] = i;
  }
  i64 s = 0;
  int maxx = 0;
  for(int i = 1; i <= n; ++ i) {
    if(a[i] == 0) {
      dp[i] = ++ maxx;
      s = 0;
      m.clear();
      m[0] = i;
      continue;
    }
    s += a[i];

    if(s == 0 && lst[i] == 0) {
      if(m[s]) {
        dp[i] = dp[m[s]] + 1;
      } else {
        dp[i] = 1;
      }
      maxx = std :: max(maxx, dp[i]);
    }
    if(lst[i] != 0) {
      if(m[s]) {
        dp[i] = dp[m[s]] + 1;
        maxx = std :: max(maxx, dp[i]);
      } else {
        dp[i] = dp[lst[i]];
      }
    }
    m[s] = i;
  }
  
  // for(int i = 1; i <= n; ++ i) {
  //   std :: cout << i << ' ' << dp[i] << ' ' << lst[i] << '\n';
  // }

  std :: cout << maxx << '\n';
}
int main() {
  //freopen("1.in", "r", stdin);
  //freopen("1.out", "w", stdout);
  std :: ios :: sync_with_stdio(false);
  std :: cin.tie(0);
  std :: cout.tie(0);
  int T = 1;
  std :: cin >> T;
  for(; t <= T; ++ t) {
    solve();
  }
  return 0;
}