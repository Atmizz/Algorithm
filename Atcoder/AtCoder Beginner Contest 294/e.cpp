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
inline double max(double a, double b) {return a > b ? a : b;}
const int MaxN = 5e4 + 220;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, k;
struct Node {
  double sugar, water, val;
  friend bool operator < (Node a, Node b) {
    return a.val > b.val;
  }
}a[MaxN], b[MaxN];
int main() {
  n = read(); m = read(); k = read();
  for(int i = 1; i <= n; ++ i)
    scanf("%lf %lf", &a[i].sugar, &a[i].water), a[i].val = 100.00 * a[i].sugar / (a[i].water + a[i].sugar);
  for(int i = 1; i <= m; ++ i)
    scanf("%lf %lf", &b[i].sugar, &b[i].water), b[i].val = 100.00 * b[i].sugar / (b[i].water + b[i].sugar);
  std :: sort(a + 1, a + 1 + n);
  std :: sort(b + 1, b + 1 + m);
  return 0;
}

/*
1~m 
*/