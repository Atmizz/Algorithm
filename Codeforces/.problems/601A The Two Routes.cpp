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
const int N = 410;
int n, m;
int road[N][N], rail[N][N];
void solve() {
  std :: cin >> n >> m;
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j <= n; ++ j) {
      road[i][j] = (i == j ? INF : 1);
      rail[i][j] = INF;
    }
  }
  for(int i = 1; i <= m; ++ i) {
    int u, v;
    std :: cin >> u >> v;
    rail[u][v] = rail[v][u] = 1;
    road[u][v] = road[v][u] = INF;
  }
  if(road[1][n] == 1) {
    for(int k = 1; k <= n; ++ k) {
      for(int i = 1; i <= n; ++ i) {
        if(i == k) continue;
        for(int j = 1; j <= n; ++ j) {
          if(j == k || i == j) continue;
          rail[i][j] = std :: min(rail[i][j], rail[i][k] + rail[k][j]);
        }
      }
    }
    std :: cout << (rail[1][n] == INF ? -1 : rail[1][n]);
  } else {
    for(int k = 1; k <= n; ++ k) {
      for(int i = 1; i <= n; ++ i) {
        if(i == k) continue;
        for(int j = 1; j <= n; ++ j) {
          if(j == k || i == j) continue;
          road[i][j] = std :: min(road[i][j], road[i][k] + road[k][j]);
        }
      }
    }
    std :: cout << (road[1][n] == INF ? -1 : road[1][n]);
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