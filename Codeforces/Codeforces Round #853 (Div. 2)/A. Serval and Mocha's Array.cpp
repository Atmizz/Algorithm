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
const int MaxN = 110;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, T, a[MaxN];
int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}
int main() {
  T = read();
  while(T --) {
    n = read();
    for(int i = 1; i <= n; ++ i) a[i] = read();
    bool ans = false;
    for(int i = 1; i <= n; ++ i)
      for(int j = i + 1; j <= n; ++ j)
        if(gcd(a[i], a[j]) <= 2) ans = true;
    printf(ans ? "Yes\n" : "No\n");
  }
  return 0;
}