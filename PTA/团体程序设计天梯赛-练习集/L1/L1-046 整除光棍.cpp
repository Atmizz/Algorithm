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
const int MaxN = 0;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
ll x, ans1, ans2;
int main() {
  ans1 = 1; ans2 = 1; x = read();
  while(ans1 < x) ans1 = ans1 * 10 + 1, ans2 ++;
  while(1) {
    std :: cout << ans1 / x;
    if(ans1 % x == 0) break;
    ans1 = (ans1 % x) * 10 + 1;
    ans2 ++;
  } printf(" %lld", ans2);
  return 0;
}