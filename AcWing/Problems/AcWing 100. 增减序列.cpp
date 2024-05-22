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
inline int min(int a, int b) {return a < b ? a : b;}
inline ll max(ll a, ll b) {return a > b ? a : b;}
const int MaxN = 1e5+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, a[MaxN], b[MaxN];
ll pos, neg;
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) a[i] = read(), b[i] = a[i] - a[i-1];
  for(int i = 2; i <= n; ++ i)
    if(b[i] > 0) pos += b[i];
    else neg -= b[i];
  printf("%lld\n%lld", max(pos, neg), std :: abs(pos - neg) + 1);
  return 0;
}