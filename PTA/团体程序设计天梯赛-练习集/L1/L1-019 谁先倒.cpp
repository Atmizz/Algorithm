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
const int MaxN = 0;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, x, y, cnt1, cnt2;
int main() {
  x = read(); y = read(); n = read();
  for(int i = 1; i <= n; ++ i) {
    int a = read(), b = read(), c = read(), d = read();
    if(a + c == b && b == d) continue;
    if(a + c == b) cnt1 ++;
    if(a + c == d) cnt2 ++;
    if(cnt1 == x + 1) {
      printf("A\n%d", cnt2);
      break;
    } if(cnt2 == y + 1) {
      printf("B\n%d", cnt1);
      break;
    }
  }
  return 0;
}