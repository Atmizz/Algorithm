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
ll n, cnt;
ll C(ll a, ll b) {
  ll sum = 1;
  for(int i = 1, j = a; i <= b; ++ i, -- j) {
    sum = sum * j / i;
    if(sum > n) return sum;
  }
  return sum;
}
int main() {
  n = read();
  if(n == 1) {
    printf("1");
    return 0;
  }
  for(ll i = 16; i >= 1; -- i) {
    ll l = i * 2, mid, r = INF, x;
    while(l <= r) {
      mid = (l + r) >> 1;
      x = C(mid, i);
      if(x == n) {
        printf("%lld", (mid + 1) * mid / 2 + i + 1);
        return 0;
      } else if(x < n) l = mid + 1;
      else r = mid - 1;
    }
  }
  return 0;
}