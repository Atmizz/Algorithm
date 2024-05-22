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
  int n, q;
  std :: cin >> n;
  std :: map <int, int> cnt;
  for(int i = 1; i <= n; ++ i) {
    int x; std :: cin >> x;
    cnt[x] ++;
  }
  std :: cin >> q;
  while(q --) {
    i64 x, y, delta, res;
    std :: cin >> x >> y;
    delta = x * x - 4 * y;
    res = sqrt(delta);
    if(res * res != delta || (res * res == delta && (cnt[(x-res)/2] == 0 || cnt[(x+res)/2] == 0))) {
      std :: cout << 0 << ' ';
      continue;
    } else {
      i64 ans;
      if(res) {
        ans = 1LL * cnt[(x-res)/2] * cnt[(x+res)/2];
      } else {
        ans = 1LL * cnt[x/2] * (cnt[x/2] - 1) / 2;
      }
      std :: cout << ans << ' ';
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