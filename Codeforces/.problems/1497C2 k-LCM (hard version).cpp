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
const int MaxN = 1e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int T, n, k;
int main() {
  T = read();
  while(T --) {
    n = read(); k = read();
    for(int i = 1; i <= k - 3; ++ i) printf("%d ", 1);
    n -= (k - 3);
    if(n & 1) printf("%d %d %d", 1, n >> 1, n >> 1);
    else if(n % 4 == 0) printf("%d %d %d", n >> 2, n >> 2, n >> 1);
    else printf("%d %d %d", 2, (n - 2) >> 1, (n - 2) >> 1);
    puts("");
  }
  return 0;
}