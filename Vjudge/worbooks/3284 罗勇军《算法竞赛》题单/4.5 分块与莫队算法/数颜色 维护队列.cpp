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
int a[MaxN], block, blk[MaxN], n, m, now, Time, cnt[MaxN*5], cntq, cntm, ans[MaxN];
struct Node {
  int l, r, id, time;
  friend bool operator < (Node a, Node b) {
    return (blk[a.l] ^ blk[b.l]) ? blk[a.l] < blk[b.l] : (blk[a.r] != blk[b.r] ? blk[a.r] < blk[b.r] : a.time < b.time);
  }
}Q[MaxN];
struct Modify {
  int pos, color;
}M[MaxN];
void add(int x) {
  if(cnt[a[x]] == 0) now ++;
  cnt[a[x]] ++;
}
void del(int x) {
  cnt[a[x]] --;
  if(cnt[a[x]] == 0) now --;
}
int main() {
  n = read(); m = read(); block = pow(n, 2.0 / 3.0);
  for(int i = 1; i <= n; ++ i) a[i] = read();
  for(int i = 1; i <= n; ++ i) blk[i] = (i - 1) / block + 1;
  for(int i = 1; i <= m; ++ i) {
    char ch; std :: cin >> ch; int l = read(), r = read();
    if(ch == 'Q') Q[++cntq] = {l, r, cntq, cntm};
    else M[++cntm] = {l, r};
  }
  std :: sort(Q + 1, Q + 1 + cntq);
  int l = 1, r = 0;
  for(int i = 1; i <= cntq; ++ i) {
    while(l < Q[i].l) del(l ++);
    while(l > Q[i].l) add(-- l);
    while(r < Q[i].r) add(++ r);
    while(r > Q[i].r) del(r --);
    while(Time < Q[i].time) {
      ++ Time;
      if(M[Time].pos >= Q[i].l && M[Time].pos <= Q[i].r) {
        cnt[a[M[Time].pos]] --;
        if(cnt[a[M[Time].pos]] == 0) now --;
        if(cnt[M[Time].color] == 0) now ++;
        cnt[M[Time].color] ++;
      }
      std :: swap (a[M[Time].pos], M[Time].color);
    } while(Time > Q[i].time) {
      if(M[Time].pos >= Q[i].l && M[Time].pos <= Q[i].r) {
        cnt[a[M[Time].pos]] --;
        if(cnt[a[M[Time].pos]] == 0) now --;
        if(cnt[M[Time].color] == 0) now ++;
        cnt[M[Time].color] ++;
      }
      std :: swap (a[M[Time].pos], M[Time].color);
      Time --;
    }
    ans[Q[i].id] = now;
  }
  for(int i = 1; i <= cntq; ++ i)
    printf("%d\n", ans[i]);
  return 0;
}