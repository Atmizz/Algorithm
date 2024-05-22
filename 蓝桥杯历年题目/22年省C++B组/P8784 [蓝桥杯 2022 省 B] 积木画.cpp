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
ll d[4], p[4];
int n;
int main() {
  n = read();
  // 0 空 1 上空 2 下空 3 满
  d[3] = 1;
  for(int i = 1; i <= n; ++ i) {
    p[0] = d[3];
    p[1] = (d[0] + d[2]) % Mod;
    p[2] = (d[0] + d[1]) % Mod;
    p[3] = (d[0] + d[1] + d[2] + d[3]) % Mod;
    for(int j = 0; j <= 3; ++ j) d[j] = p[j];
  } printf("%lld", p[3]);
  return 0;
}