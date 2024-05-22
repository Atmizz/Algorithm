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
const int MaxN = 5e4 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, k, blk[MaxN], block, a[MaxN], cnt[MaxN], now, ans[MaxN];
struct Node {
  int l, r, id;
  friend bool operator < (Node a, Node b) {
    return (blk[a.l] ^ blk[b.l]) ? blk[a.l] < blk[b.l] : ((blk[a.l] & 1) ? a.r < b.r : a.r > b.r);
  }
}q[MaxN];
void add(int x) {
  now -= cnt[a[x]] * cnt[a[x]];
  cnt[a[x]] ++;
  now += cnt[a[x]] * cnt[a[x]];
}
void del(int x) {
  now -= cnt[a[x]] * cnt[a[x]];
  cnt[a[x]] --;
  now += cnt[a[x]] * cnt[a[x]];
}
int main() {
  n = read(); m = read(); k = read(); block = sqrt(n);
  for(int i = 1; i <= n; ++ i) a[i] = read(), blk[i] = (i - 1) / block + 1;
  for(int i = 1; i <= m; ++ i) q[i].l = read(), q[i].r = read(), q[i].id = i;
  std :: sort(q + 1, q + 1 + m);
  int l = 1, r = 0;
  for(int i = 1; i <= m; ++ i) {
    while(l < q[i].l) del(l ++);
    while(l > q[i].l) add(-- l);
    while(r < q[i].r) add(++ r);
    while(r > q[i].r) del(r --);
    ans[q[i].id] = now;
  }
  for(int i = 1; i <= m; ++ i) printf("%d\n", ans[i]);
  return 0;
}