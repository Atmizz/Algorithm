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
int n, Q, a[MaxN], block, blk[MaxN], ans[MaxN], cnt[MaxN], now;
struct Query {
  int l, r, id;
  friend bool operator < (Query a, Query b) {
    return (blk[a.l] ^ blk[b.l]) ? blk[a.l] < blk[b.l] : ((blk[a.l] & 1) ? a.r < b.r : a.r > b.r);
  }
}q[MaxN];
void add(int x) {
  if(cnt[a[x]] == 0) now ++;
  cnt[a[x]] ++;
}
void del(int x) {
  cnt[a[x]] --;
  if(cnt[a[x]] == 0) now --;
}
int main() {
  n = read(); block = sqrt(n);
  for(int i = 1; i <= n; ++ i) a[i] = read(), blk[i] = (i - 1) / block + 1;
  Q = read();
  for(int i = 1; i <= Q; ++ i) q[i].l = read(), q[i].r = read(), q[i].id = i;
  std :: sort(q + 1, q + 1 + Q);
  int l = 1, r = 0;
  for(int i = 1; i <= Q; ++ i) {
    int ql = q[i].l, qr = q[i].r;
    while(l < ql) del(l ++);
    while(l > ql) add(-- l);
    while(r > qr) del(r --);
    while(r < qr) add(++ r);
    ans[q[i].id] = now;
  }
  for(int i = 1; i <= Q; ++ i) printf("%d\n", ans[i]);
  return 0;
}