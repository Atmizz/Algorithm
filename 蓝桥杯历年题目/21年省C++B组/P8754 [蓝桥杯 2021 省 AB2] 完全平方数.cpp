#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
inline ll read() {
  ll s = 0, f = 1; char ch = gc;
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
ll n, ans = 1, cnt;
int main() {
  n = read();
  for(int i = 2; i <= sqrt(n); ++ i)
    if(n % i == 0) {
      cnt = 0;
      while(n % i == 0) cnt ++, n /= i;
      if(cnt % 2) ans *= i;
    }
  if(n) ans *= n;
  printf("%lld", ans);
  return 0;
}