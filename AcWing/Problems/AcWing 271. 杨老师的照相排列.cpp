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
const int MaxN = 31;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int k;
ll f[MaxN][MaxN][MaxN][MaxN][MaxN];
int main() {
  while(k = read(), k) {
    memset(f, 0, sizeof f);
    int s[6] = {0}; f[0][0][0][0][0] = 1;
    for(int i = 1; i <= k; ++ i) s[i] = read();
    for(int a = 0; a <= s[1]; ++ a)
      for(int b = 0; b <= min(a, s[2]); ++ b)
        for(int c = 0; c <= min(b, s[3]); ++ c)
          for(int d = 0; d <= min(c, s[4]); ++ d)
            for(int e = 0; e <= min(d, s[5]); ++ e) {
              ll &v = f[a][b][c][d][e];
              if(a && a - 1 >= b) v += f[a-1][b][c][d][e];
              if(b && b - 1 >= c) v += f[a][b-1][c][d][e];
              if(c && c - 1 >= d) v += f[a][b][c-1][d][e];
              if(d && d - 1 >= e) v += f[a][b][c][d-1][e];
              if(e) v += f[a][b][c][d][e-1];
            }
    printf("%lld\n", f[s[1]][s[2]][s[3]][s[4]][s[5]]);
  }
  return 0;
}