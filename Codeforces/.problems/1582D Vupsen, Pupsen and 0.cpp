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
int n, a[N];
void solve() {
  std :: cin >> n;
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> a[i];
  }
  bool odd = 0;
  if(n & 1) {
    a[n-1] += a[n];
    n --; odd = 1;
  }
  for(int i = 1; i <= n; i += 2) {
    int x = a[i], y = a[i+1];
    if(y != 0) {
      y = -y;
    } else {
      a[n] -= a[n+1];
      if(a[i] + a[n+1] != 0) {
        std :: cout << -a[n] << ' ' << (a[i] + a[n+1]) << ' ' << -a[n] << '\n';
      } else {
        std :: cout << -a[n+1] << ' ' << -a[n+1] << ' ' << (a[i] + a[n]) << '\n';
      }
      return ;
    }
    std :: cout << y << ' ' << x << ' ';
    if(i == n - 1 && odd) {
      std :: cout << x;
    }
  }
  std :: cout << '\n';
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