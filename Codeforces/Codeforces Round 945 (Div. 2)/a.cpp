#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define sz(x) (int)x.size()
#define mk std :: make_pair
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << '\n';
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
typedef unsigned long long ull;
template <class T>
T max(T a, T b) {
  return a > b ? a : b;
}
template <class T>
T min(T a, T b) {
  return a < b ? a : b;
}
template <class T>
T abs(T a) {
  return a < 0 ? -a : a;
}
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
void solve() {
  int a[3], n = 3;
  for(int i = 0; i < 3; ++ i) {
    std :: cin >> a[i];
  }
  std :: sort(a, a + 3);
  if(a[0] + a[1] + a[2] & 1) {
    std :: cout << "-1\n";
    return ;
  }
  int ans = 0;
  for(int j = 0; j <= 30; ++ j) {
    if(j > a[0] || j > a[1]) {
      break;
    }
    ans = max(ans, j + min(a[0] + a[1] - j * 2, a[2]));
  }
  std :: cout << ans << nl;
}
int main() {
  //freopen("1.in", "r", stdin);
  //freopen("1.out", "w", stdout);
  std :: ios :: sync_with_stdio(false);
  std :: cin.tie(0);
  std :: cout.tie(0);
  int _ = 1;
  std :: cin >> _; 
  while(_ --) solve();
  return 0;
}