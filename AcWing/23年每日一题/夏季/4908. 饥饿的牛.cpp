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
inline ll min(ll a, ll b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 1e5 + 20;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
ll n, t, ans, x[MaxN], y[MaxN];
int main() {
  scanf("%lld %lld", &n, &t);
  ll last = 1, lastNum = 0;
  for(int i = 1; i <= n; ++ i) {
    scanf("%lld %lld", &x[i], &y[i]);
    if(lastNum < x[i] - last) ans += lastNum, lastNum = 0;
    else ans += x[i] - last, lastNum -= (x[i] - last);
    last = x[i], lastNum += y[i];
  }
  if(x[n] == t && lastNum > 0) ans ++;
  if(x[n] < t && lastNum > 0) ans += min(t - x[n] + 1, lastNum);
  printf("%lld", ans);
  return 0;
}