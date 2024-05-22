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
const int MaxN = 1e6 + 20;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, q, a[MaxN];
int main() {
  n = read(); q = read();
  for(int i = 1; i <= n; ++ i) a[i] = read();
  while(q --) {
    int x = read();
    int pos1 = std :: lower_bound(a + 1, a + 1 + n, x) - a;
    if(a[pos1] != x) {
      printf("-1 -1\n");
      continue;
    }
    int pos2 = std :: upper_bound(a + 1, a + 1 + n, x) - a;
    printf("%d %d\n", pos1 - 1, pos2 - 2);
  }
  return 0;
}