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
const int MaxN = 1e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, ma, mb;
int a[MaxN], b[MaxN], ans[MaxN], s[MaxN], fina, C;
void calc(int c) {
  int x = 0;
  for(int i = ma; i >= 1; -- i) {
    int u = x + a[i] - b[i]; x = 0;
    while(u < 0) x --, u += c;
    while(u / c > 0) x += (u / c), u %= c;
    s[i] = u;
  }
  for(int i = 1; i <= ma; ++ i)
    if(s[i] > ans[i]) {
      for(int j = 1; j <= ma; ++ j) ans[j] = s[j];
      C = c;
      break;
    }
}
int main() {
  n = read();
  ma = read();
  for(int i = 1; i <= ma; ++ i)
    a[i] = read();
  mb = read();
  for(int i = ma - mb + 1; i <= mb; ++ i)
    b[i] = read();
  for(int i = 2; i <= n; ++ i) calc(i);
  int i = 1;
  while(ans[i] == 0) i ++;
  for(; i <= ma; ++ i)
    fina = fina * C + ans[i];
  printf("%d", fina);
  return 0;
}