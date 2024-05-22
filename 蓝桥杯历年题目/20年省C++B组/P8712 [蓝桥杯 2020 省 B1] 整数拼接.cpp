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
const int MaxN = 1e5 + 10;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
ll MOD[MaxN][10];
ll a[MaxN][10], b[MaxN], n, k, ans;
int main() {
  n = read(); k = read();
  for(int i = 1; i <= n; ++ i) {
    a[i][0] = read();
    for(int j = 1; j <= 9; ++ j) {
      a[i][j] = a[i][j-1] * 10;
      MOD[a[i][j] % k][j] ++;
    }
  }
  for(int i = 1; i <= n; ++ i) {
    ll L = 1e9, len = 10;
    while(a[i][0] / L == 0) L /= 10, len --;
    ll mod = k - (a[i][0] % k);
    if(a[i][0] % k == 0) {
      ans += MOD[0][len];
      if(a[i][len] % k == 0) ans --;
    } else {
      ans += MOD[mod][len];
      if(a[i][len] % k == mod) ans --;
    }
  } printf("%lld", ans);
  return 0;
}