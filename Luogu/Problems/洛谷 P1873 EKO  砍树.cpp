#include <bits/stdc++.h>
#define gc getchar()
typedef long long ll;
inline ll read() {
  ll s = 0, f = 1; char ch = gc;
  for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
  for(; ch >= '0' && ch <= '9'; ch = gc)
    s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * f;
}
inline int max(int a, int b) {return a > b ? a : b;}
inline int min(int a, int b) {return a < b ? a : b;}
inline int abs(int a) {return a < 0 ? -a : a;}
const int MaxN = 1e6 + 200;
const int INF = 0x7fffffff;
const int Mod = 1e9 + 7;
ll n, m, hight[MaxN], sum[MaxN];
bool check(ll x) {
  int s = std :: lower_bound(hight + 1, hight + 1 + n, x) - hight;
  if(sum[n] - sum[s-1]  - x * (n - s + 1) >= m) return true;
  return false;
}
int main() {
  n = read(); m = read();
  for(int i = 1; i <= n; ++ i) hight[i] = read();
  std :: sort(hight + 1, hight + 1 + n);
  for(int i = 1; i <= n; ++ i) sum[i] = sum[i-1] + hight[i];
  ll l = 1, r = 1e9, mid;
  while(l <= r) {
    mid = (l + r) >> 1;
    if(check(mid)) l = mid + 1;
    else r = mid - 1;
  } printf("%lld", l - 1);
}