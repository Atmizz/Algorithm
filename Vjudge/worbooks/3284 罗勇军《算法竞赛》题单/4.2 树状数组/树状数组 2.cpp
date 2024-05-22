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
const int MaxN = 5e5 + 300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, a[MaxN];
int lowbit(int x) {
  return x & (-x);
}
void Modify(int x, int k) {
  for(; x <= n; x += lowbit(x)) a[x] += k;
}
int query(int x) {
  int sum = 0;
  for(; x; x -= lowbit(x)) sum += a[x];
  return sum;
}
int main() {
  n = read(); m = read(); int last = 0;
  for(int i = 1; i <= n; ++ i) {
    int x = read(); Modify(i, x - last); last = x;
  }
  for(int i = 1; i <= m; ++ i) {
    int opt = read(), l = read(), r, k;
    if(opt == 1) r = read(), k = read(), Modify(l, k), Modify(r+1, -k);
    else printf("%d\n", query(l));
  }
  return 0;
}