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
  i64 n, k, sum = 0;
  std :: cin >> n >> k;
  for(i64 i = 1; i <= n; i *= 2) {
    i64 maxx = ((n / i) >> 1) + ((n / i) & 1);
    i64 res = maxx + sum;

    if(k <= res) {
      std :: cout << i * ((k - sum) * 2 - 1)<< '\n';
      return ;
    }
    sum = res;
  }
}
int main() {
  //freopen("1.in", "r", stdin);
  //freopen("1.out", "w", stdout);
  std :: ios :: sync_with_stdio(false);
  std :: cin.tie(0);
  std :: cout.tie(0);
  int i = 4;
  int T = 1;
  std :: cin >> T; 
  while(T --) solve();
  return 0;
}