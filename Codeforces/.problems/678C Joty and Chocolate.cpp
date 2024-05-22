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
i64 n, a, b, p, q;
i64 gcd(i64 x, i64 y) {
  return y ? gcd(y, x % y) : x;
}
void solve() {
  std :: cin >> n >> a >> b >> p >> q;
  i64 lcm = a * b / gcd(a, b);
  std :: cout << (n / a - n / lcm) * p + (n / b - n / lcm) * q + (n / lcm) * std :: max(p, q);
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