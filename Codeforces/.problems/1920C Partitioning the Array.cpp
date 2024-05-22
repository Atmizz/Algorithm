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
int n, a[N];
i64 sum[N];
i64 gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}
void solve() {
  std :: cin >> n;
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> a[i];
    sum[i] = sum[i-1] + a[i];
  }
  std :: vector <int> v;
  for(int i = 1; i <= n; ++ i) {
    if(n % i == 0) {
      v.emplace_back(i);
    }
  }
  int ans = 0;

  for(auto sz : v) {
    if(sz == n) {
      ans ++;
      break;
    }
    int res = 0;
    for(int i = 1; i <= sz; ++ i) {
      int g = std :: abs(a[i+sz] - a[i]);
      for(int j = sz + i; j <= n; j += sz) {
        g = gcd(g, std :: abs(a[j] - a[j-sz]));
      }
      res = gcd(g, res);
    }
    // std :: cout << sz << ' ' << res << '\n';
    if(res != 1) {
        ans ++;
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