#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
inline ll read() {
  ll s = 0, f = 1LL; char ch = gc;
  for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
  for(; ch >= '0' && ch <= '9'; ch = gc)
  s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * f;
}
inline int abs(int a) {return a < 0 ? -a : a;}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 110;
const ll Mod = 1e9 + 7;
const int INF = 2147483647;
ll n, k;
struct Mat {
  ll g[MaxN][MaxN];
  Mat() {memset(g, 0, sizeof g);}
  void Build() {
    for(int i = 1; i <= n; ++ i) g[i][i] = 1LL;
  }
};
Mat operator * (Mat &a, Mat &b) {
  Mat c;
  for(ll k = 1; k <= n; ++ k)
    for(ll i = 1; i <= n; ++ i)
      for(ll j = 1; j <= n; ++ j)
        c.g[i][j] = (c.g[i][j] + a.g[i][k] * b.g[k][j] % Mod) % Mod;
  return c;
}
Mat Pow(Mat a, ll b) {
  Mat sum; sum.Build();
  while(b) {
    if(b & 1LL) sum = sum * a;
    b >>= 1LL; a = a * a;
  } return sum;
}
int main() {
  n = read(); k = read(); Mat a, ans;
  for(ll i = 1; i <= n; ++ i)
    for(ll j = 1; j <= n; ++ j)
      a.g[i][j] = read();
  ans = Pow(a, k);
  for(ll i = 1; i <= n; ++ i, puts(""))
    for(ll j = 1; j <= n; ++ j)
      printf("%lld ", ans.g[i][j]);
  return 0;
}