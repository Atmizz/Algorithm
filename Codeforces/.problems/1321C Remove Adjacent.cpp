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
const int N = 110;
int n, ans, lst[N], nxt[N], vis[N];
std :: string str;
void solve() {
  std :: cin >> n >> str;
  str = "0" + str + "0";
  for(int i = 1; i <= n; ++ i) {
    lst[i] = i - 1;
    nxt[i] = i + 1;
  }
  for(int i = 26; i >= 1; -- i) {
    while(1) {
      bool flag = 0;
      for(int j = 1; j <= n; ++ j) {
        if(str[j] == i + 'a' - 1 && !vis[j]) {
          if(str[j] - str[lst[j]] == 1 || str[j] - str[nxt[j]] == 1) {
            ans ++;
            flag = 1;
            vis[j] = 1;
            lst[nxt[j]] = lst[j];
            nxt[lst[j]] = nxt[j];
          }
        }
      }
      if(!flag) {
        break;
      }
    }
  }
  std :: cout << ans;
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