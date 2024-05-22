#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
inline ll read() {
  ll s = 0, f = 1; char ch = gc;
  for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
  for(; ch >= '0' && ch <= '9'; ch = gc)
    s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * f;
}
inline int abs(int a) {return a < 0 ? -a : a;}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 2e5 + 20;
const int Mod = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, cnt, ans[MaxN];
ll L;
struct SegmentTree {
  int l, r;
  ll min;
}t[MaxN << 2];
struct Node {
  int id, pos;
  ll x , y, z;
  friend bool operator < (Node a, Node b) {
    if(a.pos != b.pos) return a.pos < b.pos;
    if(a.x * b.y - a.y * b.x == 0)
      return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y;
    return a.x * b.y - a.y * b.x < 0;
  }
}a[MaxN];
int calc(Node a) {
  if(a.x >= 0 && a.y > 0) return 1;
  if(a.x > 0 && a.y <= 0) return 2;
  if(a.x <= 0 && a.y < 0) return 3;
  return 4;
}
void pushUp(int k) {
  t[k].min = min(t[ls].min, t[rs].min);
}
void build(int l, int r, int k) {
  t[k].l = l; t[k].r = r;
  if(l == r) {
    t[k].min = (int)(sqrt)(1.0 * a[l].x * a[l].x + a[l].y * a[l].y);
    if(t[k].min * t[k].min != a[l].x * a[l].x + a[l].y * a[l].y) t[k].min ++;
    return ;
  } int mid = (l + r) >> 1;
  build(l, mid, ls); build(mid+1, r, rs);
  pushUp(k);
}
void query(int l, int r, int k, ll L, int &pos) {
  if(pos) return ;
  if(t[k].l == t[k].r) {
    pos = t[k].l;
    return ;
  }
  int mid = (t[k].l + t[k].r) >> 1;
  if(l <= mid && t[ls].min <= L) query(l, r, ls, L, pos);
  if(pos) return ;
  if(r > mid && t[rs].min <= L) query(l, r, rs, L, pos); 
}
void update(int l, int r, int k) {
  if(t[k].l == l && t[k].r == r) {
    t[k].min = INF;
    return ;
  } int mid = (t[k].l + t[k].r) >> 1;
  if(l <= mid) update(l, r, ls);
  if(r > mid) update(l, r, rs);
  pushUp(k);
}
int main() {
  n = read(); L = read();
  for(int i = 1; i <= n; ++ i) ans[i] = -1;
  for(int i = 1; i <= n; ++ i) {
    a[i].x = read(); a[i].y = read();
    a[i].z = read(); a[i].id = i;
    if(a[i].x == 0 && a[i].y == 0)
      L += a[i].z, a[i].x = a[i].y = INF;
    a[i].pos = calc(a[i]);
  }
  std :: sort(a + 1, a + 1 + n);
  build(1, n, 1); int now = 0, rank = 1;
  Node last;
  while(1) {
    int pos = 0;
    if(now != n) {
      query(now+1, n, 1, L, pos);
      if(pos) {
        L += a[pos].z;
        if(rank == 1 && cnt == 0)
          cnt ++, ans[a[pos].id] = rank;
        else
          if(calc(last) == calc(a[pos]) && last.x * a[pos].y - last.y * a[pos].x == 0)
            cnt ++, ans[a[pos].id] = rank;
          else rank += cnt, ans[a[pos].id] = rank, cnt = 1;
        last = a[pos]; now = pos; update(pos, pos, 1);
        continue;
      }
    }
    if(now != 1 && now) {
      query(1, now-1, 1, L, pos);
      if(pos) {
        L += a[pos].z;
        if(rank == 1 && cnt == 0)
          cnt ++, ans[a[pos].id] = rank;
        else
          if(calc(last) == calc(a[pos]) && last.x * a[pos].y - last.y * a[pos].x == 0)
            cnt ++, ans[a[pos].id] = rank;
          else rank += cnt, ans[a[pos].id] = rank, cnt = 1;
        last = a[pos]; now = pos; update(pos, pos, 1);
        continue;
      }
    }
    break;
  }
  for(int i = 1; i <= n; ++ i)
    printf("%d ", ans[i]);
  return 0;
}