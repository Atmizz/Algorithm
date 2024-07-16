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
// const int N = ; 
int cnt[4][4];
void solve() {
  int n = 3;
  char g[4][4];
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j <= n; ++ j) {
      std :: cin >> g[i][j];
    }
  }
  int step1 = 0, step2 = 0;
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j <= n; ++ j) {
      step1 += (g[i][j] == 'X');
      step2 += (g[i][j] == '0');
    }
  }
  if(step1 < step2 || step1 - step2 > 1) {
    std :: cout << "illegal";
    return ;
  }
  int win = -1;
  for(int i = 1; i <= 3; ++ i) {
    bool ok = true;
    for(int j = 1; j <= 3; ++ j) {
      if(g[i][j] != g[i][1] || g[i][j] == '.') {
        ok = false;
      }
    }
    if(ok) {
      if(win != -1 && win != (g[i][1] == '0')) {
        std :: cout << "illegal";
        return ;
      }
      win = (g[i][1] == '0');
      for(int j = 1; j <= 3; ++ j) {
        cnt[i][j] ++;
      }
    }

    ok = true;
    for(int j = 1; j <= 3; ++ j) {
      if(g[j][i] != g[1][i] || g[j][i] == '.') {
        ok = false;
      }
    }
    if(ok) {
      if(win != -1 && win != (g[1][i] == '0')) {
        std :: cout << "illegal";
        return ;
      }
      win = (g[1][i] == '0');
      for(int j = 1; j <= 3; ++ j) {
        cnt[j][i] ++;
      }
    }
  }
  bool ok = true;
  for(int j = 1; j <= 3; ++ j) {
    if(g[j][j] != g[1][1] || g[j][j] == '.') {
      ok = false;
    }
  }
  if(ok) {
    if(win != -1 && win != (g[1][1] == '0')) {
      std :: cout << "illegal";
      return ;
    }
    win = (g[1][1] == '0');
    for(int j = 1; j <= 3; ++ j) {
      cnt[j][j] ++;
    }
  }
  ok = true;
  for(int j = 1; j <= 3; ++ j) {
    if(g[j][4-j] != g[3][1] || g[j][4-j] == '.') {
      ok = false;
    }
  }
  if(ok) {
    if(win != -1 && win != (g[3][1] == '0')) {
      std :: cout << "illegal";
      return ;
    }
    win = (g[3][1] == '0');
    for(int j = 1; j <= 3; ++ j) {
      cnt[j][4-j] ++;
    }
  }
  if((win == 1 && step1 > step2) || (win == 0 && step1 == step2)) {
    std :: cout << "illegal";
    return ;
  }
  int sum = 0;
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j <= n; ++ j) {
      sum += cnt[i][j];
    }
  }
  sum /= 3;
  if(sum > 0) {
    for(int i = 1; i <= n; ++ i) {
      for(int j = 1; j <= n; ++ j) {
        if(sum == cnt[i][j]) {
          std :: cout << (win == 0 ? "the first player won" : "the second player won");
          return ;
        }
      }
    }
    std :: cout << "illegal";
    return ;
  }
  if(step1 + step2 == 9) {
    std :: cout << "draw";
  } else {
    std :: cout << (step1 > step2 ? "second" : "first");
  }
}
int main() {
  //freopen("1.in", "r", stdin);
  //freopen("1.out", "w", stdout);
  std :: ios :: sync_with_stdio(false);
  std :: cin.tie(0);
  std :: cout.tie(0);
  int _ = 1;
  //std :: cin >> _; 
  while(_ --) solve();
  return 0;
}