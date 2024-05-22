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
const int N = 6e4 + 20;
int n;
double x[N],v[N];
void solve() {
  std :: cin >> n;
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> x[i];
  }
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> v[i];
  }
  auto check = [=](double t) -> bool {
    double L = -Range, R = Range;
    for(int i = 1; i <= n; ++ i) {
      L = std :: max(L, x[i] - v[i] * t);
      R = std :: min(R, x[i] + v[i] * t);
    }
    return L <= R;
  };
  double l = 0, r = Range, ans = 0;
  while(r - l >= eps) {
    double mid = (r + l) / 2;
    if(check(mid)) {
      ans = mid;
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%.10lf", ans);
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