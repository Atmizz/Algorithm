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
const int N = 550;
int a[N][N], n, m;
void solve() {
  std :: cin >> n >> m;
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j <= m; ++ j) {
      std :: cin >> a[i][j];
    }
  }

  for(int k = 0; k < 10; ++ k) {
    int res0 = 0, res1 = 0;
    for(int i = 1; i <= n; ++ i) {
      int maxx = 1 << k, fg1 = 0, fg0 = 0;
      for(int j = 1; j <= m; ++ j) {
        if(a[i][j] & maxx) fg1 = 1;
        else fg0 = 1;
      }
      res0 += (fg1 == 0); res1 += (fg0 == 0);
    }
    if(res0 + res1 < n || (res0 + res1 == n && res1 & 1)) {
      // deb(k);
      // deb(res0);
      std :: cout << "TAK\n";
      for(int i = 1; i <= n; ++ i) {
        int maxx = 1 << k, fg1 = 0, fg0 = 0;

        for(int j = 1; j <= m; ++ j) {
          if(a[i][j] & maxx) fg1 = 1;
          else fg0 = 1;
        }

        if(fg0 == 0 || fg1 == 0) {
          std :: cout << 1 << ' ';
        } 
        else {
          for(int j = 1; j <= m; ++ j) {
            if((maxx & a[i][j]) && !(res1 & 1)) {
              std :: cout << j << ' ';
              res1 ++;
              break;
            } else if(!(maxx & a[i][j]) && (res1 & 1)){
              std :: cout << j << ' ';
              break;
            }
          }
        }
      }
      return ;
    }
  }
  std :: cout << "NIE";
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