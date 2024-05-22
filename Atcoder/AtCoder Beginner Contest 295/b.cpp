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
const int MaxN = 30;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m;
char g[MaxN][MaxN];
int main() {
  n = read(); m = read();
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= m; ++ j)
      std :: cin >> g[i][j];
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= m; ++ j)
      if(g[i][j] >= '1' && g[i][j] <= '9') {
        int x = g[i][j] - 48; g[i][j] = '.';
        for(int a = max(1, i - x); a <= min(n, i + x); ++ a)
          for(int b = max(1, j - x); b <= min(m, j + x); ++ b)
            if(abs(i - a) + abs(j - b) <= x && g[a][b] == '#') g[a][b] = '.';
      }
  for(int i = 1; i <= n; ++ i, puts(""))
    for(int j = 1; j <= m; ++ j)
      std :: cout << g[i][j];
  return 0;
}