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
const int N = 4;
char g[N][N];
int n = 3;
void solve() {
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j <= n; ++ j) {
      std :: cin >> g[i][j];
    }
  }
  for(int i = 1; i <= 3; ++ i) {
    for(int j = 1; j <= 3; ++ j) {
      if(g[i][j] == '?') {
        bool flag[3] = {0};
        for(int k = 1; k <= 3; ++ k) {
          if(g[i][k] != '?') {
            flag[g[i][k]-'A'] = 1;
          }
        }
        for(int i = 0; i < 3; ++ i) {
          if(!flag[i]) {
            std :: cout << char(i + 'A') << '\n';
            return ;
          }
        }
      }
    }
  }
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