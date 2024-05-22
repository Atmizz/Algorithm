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
int l, r, x, y, s;
int ans;
int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}
int main() {
  l = read(); r = read(); x = read(); y = read(); s = x * y;
  for(int i = max(l, x); i <= min(r, sqrt(s)); ++ i)
    if(s % i == 0 && gcd(i, s / i) == x && (s / i) >= l && (s / i) <= r) {
      ans += 2; //, printf("%d %d \n", i, s / i);
      if(i == s / i) ans -= 2;
    }
  if(x == y && x == 1 && l <= x && r >= x) ans = 1;
  printf("%d", ans);
  return 0;
}