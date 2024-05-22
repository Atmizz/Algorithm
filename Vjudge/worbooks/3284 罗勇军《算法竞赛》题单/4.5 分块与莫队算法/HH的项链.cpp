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
const int MaxN = 1e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
inline int lowbit(int x) { return x & -x;}
int n, m, a[MaxN], pre[MaxN], tree[MaxN], ans[MaxN];
struct Node {
  int l, r, id;
  friend bool operator < (Node a, Node b) {
    return a.r == b.r ? a.l < b.l : a.r < b.r;
  }
}q[MaxN];
void add(int x, int k) {
  for(; x <= n; x += lowbit(x)) tree[x] += k;
}
int query(int x) {
  int sum = 0;
  for(; x; x -= lowbit(x)) sum += tree[x];
  return sum;
}
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) {
    int x; std :: cin >> x;
    pre[i] = a[x];
    a[x] = i;
  }
  m = read();
  for(int i = 1; i <= m; ++ i) {
    int l = read(), r = read();
    q[i] = {l, r, i};
  }
  std :: sort(q + 1, q + 1 + m);
  int r = 0;
  for(int i = 1; i <= m; ++ i) {
    while(r < q[i].r) {
      add(++r, 1);
      if(pre[r] != 0) add(pre[r], -1);
    }
    ans[q[i].id] = query(q[i].r) - query(q[i].l - 1);
  }
  for(int i = 1; i <= m; ++ i)
    printf("%d\n", ans[i]);
  return 0;
}