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
const int MaxN = 1020;
const int Mod = 1e9 + 7;
const int INF = (2<<63) - 1;
ll t, n, cnt[MaxN], ans[MaxN];
int main() {
  t = read();
  while(t --) {
    n = read(); ll x = n;
    if(n == 1) {
      std :: cout << 0 << '\n';
      continue;
    } if(n == 2 || n == 3) {
      std :: cout << "1\n";
      continue;
    } if(n >= 4 && n <= 9) {
      std :: cout << "2\n";
      continue;
    }
    ll cnt = 16, ans = 4; n -= 25;
    while(n > 0) {
      n -= cnt;
      if(n <= 0) break;
      ans += 2; cnt += 8;
      // std :: cout << ans << " " << n << '\n';
    }
    if(x % 2 == 0) ans ++;
    printf("%lld\n", ans);
  }
  return 0;
}