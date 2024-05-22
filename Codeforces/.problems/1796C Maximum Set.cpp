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
const int Mod = 998244353;
const int N = 1e6 + 20;
int pow2[30];
void prepare() {
  pow2[0] = 1;
  for(int i = 1; i <= 20; ++ i) {
    pow2[i] = pow2[i-1] * 2;
  }
}
void solve() {
  int l, r;
  std :: cin >> l >> r;
  int ans = std :: log2(r / l);
  int a = r / pow2[ans] - l + 1;
  if(ans > 0 && r / pow2[ans-1] / 3 >= l) {
    a = (a + (r / pow2[ans-1] / 3 - l + 1) * ans % Mod) % Mod;
  }

  std :: cout << ans + 1 << " " << a << '\n';
}
int main() {
  //freopen("1.in", "r", stdin);
  //freopen("1.out", "w", stdout);
  std :: ios :: sync_with_stdio(false);
  std :: cin.tie(0);
  std :: cout.tie(0);
  prepare();
  int T = 1;
  std :: cin >> T; 
  while(T --) solve();
  return 0;
}