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
// const int N = ;
void solve() {
  i64 n, x, ans = 0, maxx = 0;
  std :: cin >> n >> x;
  int cnt = 0, flag = 0;
  for(int i = 0; i < 64; ++ i) {
    // std :: cout << ans + maxx << '\n';
    int a = (n >> i) & 1;
    int b = (x >> i) & 1;
    if(a == 0 && b == 1) {
      std :: cout << "-1\n";
      return ;
    } else if(a == 1 && b == 1) {
      flag = 1;
      if(cnt) {
        std :: cout << "-1\n";
        return ;
      }
      ans = ans + (1LL << i);
    } else if(a == 0 && b == 0) {
      if(cnt) {
        cnt = 0;
        maxx = std :: max(maxx, (1LL << i));
      }
    } else {
      cnt ++;
    }
    if(flag && cnt > 0) {
      std :: cout << -1 << '\n';
      return ;
    }
  }
  std :: cout << ans + maxx << '\n';
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