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
const int MaxN = 2e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, a[MaxN];
int lowbit(int x) {
  return x & (-x);
}
void Modify(int x, int k) {
  for(; x <= n; x += lowbit(x))
    a[x] += k;
}
int query(int x) {
  int sum = 0;
  for(; x; x -= lowbit(x))
    sum += a[x];
  return sum;
}
int main() {
  n = read(); m = read();
  for(int i = 1; i <= n; ++ i) {
    int x = read(); Modify(i, x);
  }
  for(int i = 1; i <= m; ++ i) {
    int opt = read(), u = read(), v = read();
    if(opt == 1) Modify(u, v);
    else printf("%d\n", query(v) - query(u-1));
  }
  return 0;
}