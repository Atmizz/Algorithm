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
int n, T, k, ans[MaxN], b[MaxN];
struct Node {
  int val, id;
  friend bool operator < (Node a, Node b) {
    return a.val == b.val ? a.id < b.id : a.val < b.val;
  }
}a[MaxN];
int main() {
  T = read();
  while(T --) {
    n = read(); k = read();
    for(int i = 1; i <= n; ++ i) a[i].val = read(), a[i].id = i;
    std :: sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; ++ i) b[i] = read();
    std :: sort(b + 1, b + 1 + n);
    for(int i = 1; i <= n; ++ i) ans[a[i].id] = b[i];
    for(int i = 1; i <= n; ++ i) printf("%d ", ans[i]);
    puts("");
  }
  return 0;
}