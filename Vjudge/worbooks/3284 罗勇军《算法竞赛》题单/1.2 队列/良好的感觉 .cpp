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
inline ll max(ll a, ll b) {return a > b ? a : b;}
const int MaxN = 1e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
ll n, a[MaxN], ans, sum[MaxN], L[MaxN], R[MaxN];
std :: stack <ll> sL, sR;
int main() {
  n = read(); sL.push(0); sR.push(n+1);
  for(int i = 1; i <= n; ++ i) a[i] = read(), sum[i] = sum[i-1] + a[i];
  for(int i = 1; i <= n; ++ i) {
    while(sL.size() && a[sL.top()] >= a[i]) sL.pop();
    L[i] = sL.top(); 
    sL.push(i);
  }
  for(int i = n; i >= 1; -- i) {
    while(sR.size() && a[sR.top()] >= a[i]) sR.pop();
    R[i] = sR.top() - 1;
    sR.push(i);
  }
  // for(int i = 1; i <= n; ++ i)
  //   std :: cout << i << " L " << L[i] << ' '<< " R " << R[i] << '\n';
  for(int i = 1; i <= n; ++ i) ans = max(ans, (sum[R[i]] - sum[L[i]]) * a[i]);
  printf("%lld", ans);
  return 0;
}