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
const int MaxN = 1e4 + 20;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, k, du[MaxN], d[MaxN];
std :: vector <int> g[MaxN];
int main() {
  n = read(); m = read();
  for(int i = 1; i <= m; ++ i) {
    int u = read(), v = read();
    g[u].push_back(v);
    g[v].push_back(u);
    d[u] ++, d[v] ++;
  } k = read();
  while(k --) {
    int h = read();
    for(int i = 1; i <= n; ++ i) du[i] = d[i];
    for(int i = 1; i <= h; ++ i) {
      int u = read(); du[u] = -1;
      for(auto v : g[u]) du[v] --;
    }
    int cnt = 0;
    for(int i = 1; i <= n; ++ i)
      if(du[i] > 0) {
        cnt ++; break;
      }
    printf(cnt ? "NO\n" : "YES\n");
  }
  return 0;
}