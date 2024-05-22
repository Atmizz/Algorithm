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
const int MaxN = 4;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
char g[MaxN][MaxN];
int n;
int main() {
  n = read();
  while(n --) {
    for(int i = 1; i <= 3; ++ i)
      for(int j = 1; j <= 3; ++ j)
        std :: cin >> g[i][j];
    std :: string ans = "DRAW";
    for(int i = 1; i <= 3; ++ i) {
      if(g[i][1] == g[i][2] && g[i][2] == g[i][3] && g[i][3] != '.') ans = g[i][3];
      if(g[1][i] == g[2][i] && g[2][i] == g[3][i] && g[3][i] != '.') ans = g[3][i];
    }
    if(g[1][1] == g[2][2] && g[2][2] == g[3][3] && g[3][3] != '.') ans = g[3][3];
    if(g[1][3] == g[2][2] && g[2][2] == g[3][1] && g[3][1] != '.') ans = g[3][1];
    std :: cout << ans << '\n';
  }
  return 0;
}