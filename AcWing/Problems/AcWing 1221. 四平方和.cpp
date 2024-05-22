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
const int MaxN = 5e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, cnt;
struct Node {
  int a, b, s;
  friend bool operator < (Node a, Node b) {
    if(a.s != b.s) return a.s < b.s;
    if(a.a != b.a) return a.a < b.a;
    return a.b < b.b;
  }
}t[MaxN];
int main() {
  n = read();
  for(int i = 0; i * i <= n; ++ i)
    for(int j = i; j * j + i * i <= n; ++ j)
      t[++cnt] = {i, j, i * i + j * j};
  std :: sort(t + 1, t + 1 + cnt);
  for(int i = 0; i * i <= n; ++ i)
    for(int j = i; j * j + i * i <= n; ++ j) {
      int l = 1, r = cnt, mid, x = n - i * i - j * j;
      while(l < r) {
        mid = (l + r) >> 1;
        if(t[mid].s >= x) r = mid;
        else l = mid + 1;
      } if(t[l].s == x) {
        printf("%d %d %d %d", i, j, t[l].a, t[l].b);
        return 0;
      }
    }
  return 0;
}