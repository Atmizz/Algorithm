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
const int MaxN = 0;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int main() {
  int n, a[5], sum, cnt, product;
  n = 3457;
  cnt = 0;
  sum = 0;
  product = 1;
  while(n) {
    a[++cnt] = n % 10;
    n /= 10;
  }
  for(int i = 1; i <= 4; ++ i) sum += a[i];
  for(int i = 1; i <= 4; ++ i) product *= a[i];
  printf("%d %d", sum, product);
  return 0;
}