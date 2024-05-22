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
const int MaxN = 130;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int Map[MaxN][MaxN], n, m, cnt, ans[MaxN];
int main() {
  n = read(); m = read();
  for(int i = 1; i <= m; ++ i) {
    int x = read();
    Map[x][x+1] = 1;
  } cnt = 0;
  for(int i = 1; i <= n; ++ i) {
    ans[++cnt] = i;
    if(Map[i][i+1] == 0) {
      for(int i = cnt; i >= 1; -- i)
        printf("%d ", ans[i]);
      cnt = 0;
    }
  }
  return 0;
}