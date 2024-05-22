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
const int MaxN = 2e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int T, n, a[MaxN];
int main() {
  T = read();
  while(T --) {
    n = read(); int minn = INF, ou = 0, ji = 0;
    for(int i = 1; i <= n; ++ i) {
      a[i] = read(), minn = min(minn, a[i]);
      if(a[i] & 1) ji ++;
      else ou ++;
    }
    int flag = 1;
    if(minn & 1) {
      int minn2 = INF;
      for(int i = 1; i <= n; ++ i)
        if(a[i] & 1 == 0) minn2 = min(minn2, a[i]);
      if(minn2 == INF) flag = 1;
      else 
        if(minn2 > minn) flag = 1;
        else flag = 0;
    } else
      if(ji > 0) flag = 0;
    printf(flag ? "YES\n" : "NO\n");
  }
  return 0;
}