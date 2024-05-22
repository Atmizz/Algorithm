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
const int N = 1e5 + 20;
int n, m, c[N];
std :: vector <int> lst[N], g;
std :: map <int, int> col;
std :: vector <int> adj[N];
void solve() {
  std :: cin >> n >> m;
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> c[i];
    if(!col[c[i]]) {
      col[c[i]] = 1;
      g.push_back(c[i]);
    }
    lst[c[i]].push_back(i);
  }
  for(int i = 1; i <= m; ++ i) {
    int x, y;
    std :: cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int ans, num = 0;
  for(auto x : g) {
    std :: map<int, int> res;
    int tp = 0;
    for(auto z : lst[x]) {
      for(auto s : adj[z]) {
        if(!res[c[s]] && c[s] != x) {
          tp ++;
          res[c[s]] = 1;
        }
      }
    }
    // deb(x); deb(tp);
    if(num < tp) {
      ans = x;
      num = tp;
    } else if(num == tp) {
      if(ans > x) {
        ans = x;
      }
    }
  }
  std :: cout << ans ;
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