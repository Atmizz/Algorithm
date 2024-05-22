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
const int N = 3e5 + 20;
int n, m, pos[N];
std :: queue <int> q[N];
void solve() {
  std :: cin >> n >> m;
  int cnt = 0, lst = 0, ans = 0;
  for(int i = 1; i <= m; ++ i) {
    int opt, x;
    std :: cin >> opt >> x;
    if(opt == 1) {
      pos[++cnt] = x;
      q[x].push(cnt);
      ans ++;
    }
    else if(opt == 2) {
      while(q[x].size()) {
        ans --;
        q[x].pop();
      }
    }
    else {
      while(lst < x) {
        lst ++;
        if(q[pos[lst]].size()) {
          if(q[pos[lst]].front() <= lst) {
            q[pos[lst]].pop();
            ans --;
          }
        }
      }
    }
    std :: cout << ans << '\n';
  }
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