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
const int MaxN = 1e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int T, a[MaxN], n;
int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}
int main() {
  T = read();
  while(T --) {
    n = read(); bool flag = 1;
    for(int i = 1; i <= n; ++ i) a[i] = read();
    for(int i = 1; i <= n; ++ i)
      if(a[i] != a[n-i+1]) {
        flag = 0; break;
      }
    if(flag) {
      printf("0\n");
      continue;
    }
    int ans = max(a[1], a[n]) - min(a[1], a[n]);
    for(int i = 2; i <= n >> 1; ++ i) {
      int x = max(a[i], a[n-i+1]) - min(a[i], a[n-i+1]);
      ans = gcd(ans, x);
    } printf("%d\n", ans);
  }
  return 0;
}