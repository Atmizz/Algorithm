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
int t, n, f[MaxN];
int main() {
  for(int i = 2; i <= 1000; ++ i) {
    int k = i * i + i + 1;
    while(k <= 1e6) f[k] = 1, k = k * i + 1;
  }
  t = read();
  while(t --) {
    n = read();
    printf(f[n] == 1 ? "YES\n" : "NO\n");
  }
  return 0;
}