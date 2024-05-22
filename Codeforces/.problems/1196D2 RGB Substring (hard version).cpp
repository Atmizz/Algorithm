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
const int N = 2e5 + 20;
std :: string org, str;
int n, k;
void prepare() {
  for(int i = 1; i <= (N - 20) / 3; ++ i) {
    org += "RGB";
  }
}
int sum[N];
void solve() {
  int ans = INF;
  std :: cin >> n >> k >> str;
  str = "0" + str;
  for(int t = 0; t < 3; ++ t) {
    for(int i = 1; i <= n; ++ i) {
      if(str[i] != org[i+t]) {
        sum[i] = 1;
      } else {
        sum[i] = 0;
      }
    }
    for(int i = 1; i <= n; ++ i) {
      sum[i] += sum[i-1];
    }
    for(int i = k; i <= n; ++ i) {
      // deb(sum[i] - sum[i-k]);
      ans = std :: min(ans, sum[i] - sum[i-k]);
    }
  }
  std :: cout << ans << '\n';
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