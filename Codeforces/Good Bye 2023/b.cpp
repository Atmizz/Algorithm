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
i64 gcd(i64 a, i64 b) {
  return b ? gcd(b, a % b) : a;
}
void solve() {
  i64 a, b;
  std :: cin >> a >> b;
  i64 g = gcd(a, b);
  i64 maxx = std :: max(a, b);
  i64 minn = std :: min(a, b);
  if(maxx % minn == 0) {
    std :: cout << maxx / minn * maxx << '\n';
    return ;
  }
  std :: cout << minn / g * maxx << '\n';
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