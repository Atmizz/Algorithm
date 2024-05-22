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
int n, dp[N];
// dp_i表示从第i个位置向左开始启动时关闭的装置个数。
struct Chain {
  int x, y;
  friend bool operator < (Chain a, Chain b) {
    return a.x < b.x ;
  }
}a[N];
void solve() {
  std :: cin >> n;
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> a[i].x >> a[i].y;
  }
  std :: sort(a + 1, a + 1 + n);
  for(int i = 2; i <= n; ++ i) {
    Chain res = {a[i].x-a[i].y, 0};
    int pos = std :: lower_bound(a + 1, a + 1 + i, res) - a;
    // deb(i); deb(pos);
    dp[i] = dp[pos-1] + i - pos;
  }
  // for(int i = 1; i <= n; ++ i) {
  //   std :: cout << i << ' ' << dp[i] << '\n';
  // }
  int ans = INF;
  for(int i = 1; i <= n; ++ i) {
    ans = std :: min(ans, dp[i-1] + n - i + 1);
    // deb(i);
    // deb(dp[i-1] + n - i + 1);
  }
  std :: cout << std :: min(ans, dp[n]);
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