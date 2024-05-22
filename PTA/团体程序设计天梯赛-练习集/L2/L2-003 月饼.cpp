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
const int MaxN = 1e3 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, d;
double ans;
struct Node {
  double rest, bonus, price;
  friend bool operator < (Node a, Node b) {
    return a.price > b.price;
  }
}a[MaxN];
int main() {
  n = read(); d = read();
  for(int i = 1; i <= n; ++ i) scanf("%lf", &a[i].rest);
  for(int i = 1; i <= n; ++ i) scanf("%lf", &a[i].bonus), a[i].price = a[i].bonus / a[i].rest;
  std :: sort(a + 1, a + 1 + n);
  for(int i = 1; i <= n; ++ i)
    if(a[i].rest <= d) d -= a[i].rest, ans += a[i].bonus;
    else {
      ans += a[i].bonus * d / a[i].rest;
      break;
    }
  printf("%.2lf", ans);
  return 0;
}