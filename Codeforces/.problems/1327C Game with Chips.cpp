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
const int MaxN = 201;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, k;
int main() {
  n = read(); m = read(); k = read();
  for(int i = 1; i <= (k<<1); ++ i) read(), read();
  printf("%d\n", n + m + n * m - 3);
  for(int i = 1; i < n; ++ i) std :: cout << 'U';
  for(int i = 1; i < m; ++ i) std :: cout << 'L';
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j < m; ++ j)
      std :: cout << ((i & 1) ? 'R' : 'L');
    if(i < n) std :: cout << 'D';
  }
  return 0;
}