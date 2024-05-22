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
const int MaxN = 2e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
ll n, m;
struct Node {
  ll a, b;
  friend bool operator < (Node a, Node b) {
    return a.a < b.a;
  }
}t[MaxN];
bool check(ll x) {
  ll cnt = m;
  for(int i = 1; i <= n; ++ i)
    if(t[i].a < x) {
      if(t[i].b + t[i].a < x) return false;
      cnt -= (x - t[i].a);
      if(cnt < 0) return false;
    } else break;
  return true;
}
int main() {
  n = read(); m = read();
  ll l, r, mid;
  for(int i = 1; i <= n; ++ i) t[i].a = read();
  for(int i = 1; i <= n; ++ i) t[i].b = read(), r = max(t[i].a + t[i].b, r);
  std :: sort(t + 1, t + 1 + n); l = 1;
  while(l < r) {
    mid = (l + r) >> 1;
    if(check(mid)) l = mid + 1;
    else r = mid;
  } printf("%lld", l - 1);
  return 0;
}