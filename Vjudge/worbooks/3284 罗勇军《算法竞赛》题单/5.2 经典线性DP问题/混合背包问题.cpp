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
const int MaxN = 1010;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int f[MaxN], n, V;
int main() {
  n = read(); V = read();
  for(int i = 1; i <= n; ++ i) {
    int v = read(), w = read(), s = read();
    if(s == -1)
      for(int j = V; j >= v; -- j)
        f[j] = max(f[j-v] + w, f[j]);
    else if(s == 0)
      for(int j = v; j <= V; ++ j)
        f[j] = max(f[j-v] + w, f[j]);
    else {
      int num = min(s, V / v);
      for(int k = 1; num > 0; k <<= 1) {
        if(k > num) k = num;
        num -= k;
        for(int j = V; j >= k * v; -- j)
          f[j] = max(f[j], f[j-k*v] + k * w);
      }
    }
  } printf("%d", f[V]);
  return 0;
}