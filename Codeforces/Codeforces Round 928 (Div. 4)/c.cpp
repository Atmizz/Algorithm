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
int n, ans[N];
void pre() {
  ans[1] = 1;
  for(int i = 2; i <= N - 20; ++ i) {
    int j = i;
    ans[i] = ans[i-1];
    while(j) {
      ans[i] += (j % 10);
      j /= 10;
    }
  }
}
void solve() {
  int x;
  std :: cin >> x;
  std :: cout << ans[x] << '\n';
}
int main() {
  //freopen("1.in", "r", stdin);
  //freopen("1.out", "w", stdout);
  std :: ios :: sync_with_stdio(false);
  std :: cin.tie(0);
  std :: cout.tie(0);
  int T = 1;
  pre();
  std :: cin >> T; 
  while(T --) solve();
  return 0;
}