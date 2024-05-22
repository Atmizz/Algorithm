#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
inline int read() {
  int s = 0, f = 1; char ch = gc;
  for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
  for(; ch >= '0' && ch <= '9'; ch = gc)
    s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * f;
}
inline int abs(int a) {return a < 0 ? -a : a;}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 120;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, cnt[MaxN], m, h[MaxN], last;
std :: vector <int> g[MaxN][11];
bool vis[MaxN];
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) cnt[i] = read(), m += cnt[i];
  int k = 0, o = n;
  while(1) {
    for(int i = 1; i <= n; ++ i) {
      bool flag = 1;
      for(int j = 1; j <= cnt[i]; ++ j)
        if(g[i][j].size() < 10) {
          flag = 0;
          g[i][j].push_back(++k); last = i;
          break;
        }
      if(flag && !vis[i]) o --, vis[i] = 1;
      if(o == 1) break;
    }
    if(o == 1) break;
  }
  for(int i = 1; i <= n; ++ i)
    if(!vis[i])
      for(int j = 1; j <= cnt[i]; ++ j)
        if(g[i][j].size() < 10) {
          if(last != i) g[i][j].push_back(++k), last = -1;
          while(g[i][j].size() < 10) g[i][j].push_back(k + 2), k += 2;
        }
  for(int i = 1; i <= n; ++ i) {
    std :: cout << "#" << i << '\n';
    for(int j = 1; j <= cnt[i]; ++ j, puts("")) {
      for(int u = 0; u < 9; ++ u) std :: cout << g[i][j][u] << ' ';
      std :: cout << g[i][j][9];
    }
  }
  return 0;
}