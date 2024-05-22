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
  char g[11][11];
  int n, cnt[11] = {0};
  std :: cin >> n;
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j <= n; ++ j) {
      std :: cin >> g[i][j];
      if(g[i][j] == '1') cnt[i] ++;
    }
  }
  for(int i = 2; i <= n; ++ i) {
    if(cnt[i] == cnt[i-1] && cnt[i] != 0) {
      std :: cout << "SQUARE\n";
      return ;
    }
  }
  std :: cout << "TRIANGLE\n";
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