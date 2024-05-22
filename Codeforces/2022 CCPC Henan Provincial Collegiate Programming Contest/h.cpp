#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define sz(x) (int)x.size()
#define mk std :: make_pair
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << '\n';
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
typedef unsigned long long ull;
template <class T>
T max(T a, T b) {
  return a > b ? a : b;
}
template <class T>
T min(T a, T b) {
  return a < b ? a : b;
}
template <class T>
T abs(T a) {
  return a < 0 ? -a : a;
}
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 5e5 + 20;
struct Node {
  int from; // 0 ио/ 1 об/ 2 вС/ 3 ср
  int x, y;
};
void solve() {
  int n = 4, m, sy, ey;
  std :: cin >> m >> sy >> ey;
  std :: string s[4];
  for(int i = 1; i <= m + 1; ++ i) {
    s[1] += 'I';
  }
  for(int i = 2; i <= 3; ++ i) {
    std :: cin >> s[i];
    s[i] = '0' + s[i];
  }
  std :: queue <Node> q;
  q.push({0, 1, sy});
  std :: map <std :: array <int, 3>, int> vis;
  vis[{0, 1, sy}] = 1;
  int xxI[4] = {1, -1, 0, 0};
  int yyI[4] = {0, 0, 1, -1};
  while(sz(q)) {
    auto [f, x, y] = q.front(); q.pop();
    // std :: cout << x << ' ' << y << '\n';
    if(x == 4) {
      if(y == ey) {
        std :: cout << "YES\n";
        return ;
      }
      continue ;
    }
    if(x == 1) {
      if(y != sy) {
        continue ;
      }
    }
    if(s[x][y] == 'I') {
      for(int i = 0; i < 4; ++ i) {
        int dx = x + xxI[i];
        int dy = y + yyI[i];
        if((f <= 1 && i >= 2) || (f >= 2 && i <= 1)) {
          continue ;
        }
        if(dx < 1 || dx > n || dy < 1 || dy > m || vis.count({i, dx, dy})) {
          continue ;
        }
        vis[{i, dx, dy}] = 1;
        q.push({i, dx, dy});
      }
    } else {
      for(int i = 0; i < 4; ++ i) {
        if(f <= 1 && i <= 1) {
          continue ;
        }
        if(f >= 2 && i >= 2) {
          continue ;
        }
        int dx = x + xxI[i];
        int dy = y + yyI[i];
        if(dx < 1 || dx > n || dy < 1 || dy > m || vis.count({i, dx, dy})) {
          continue ;
        }
        vis[{i, dx, dy}] = 1;
        q.push({i, dx, dy});
      }
    }
  }
  std :: cout << "NO\n";
}
int main() {
  //freopen("1.in", "r", stdin);
  //freopen("1.out", "w", stdout);
  std :: ios :: sync_with_stdio(false);
  std :: cin.tie(0);
  std :: cout.tie(0);
  int _ = 1;
  std :: cin >> _; 
  while(_ --) solve();
  return 0;
}