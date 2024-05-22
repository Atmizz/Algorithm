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
int n, m;
struct Node {
  int sum, lazy, l, r;
}t[MaxN << 2];
void pushUp(int k) {
  t[k].sum = t[ls].sum + t[rs].sum;
}
void pushDown(int k) {
  t[ls].lazy = t[rs].lazy = t[k].lazy;
  t[ls].sum = (t[ls].r - t[ls].l + 1) * t[k].lazy;
  t[rs].sum = (t[rs].r - t[rs].l + 1) * t[k].lazy;
  t[k].lazy = -1;
}
void build(int l, int r, int k) {
  t[k].l = l; t[k].r = r; t[k].lazy = -1;
  if(l == r) {
    t[k].sum = 1;
    return ;
  }
  int mid = (l + r) >> 1;
  build(l, mid, ls); build(mid+1, r, rs);
  pushUp(k);
}
void update0(int l, int r, int k, int cnt) {
  if(t[k].sum <= cnt) {
    t[k].sum = 0;
    t[k].lazy = 0;
    return ;
  } if(t[k].lazy != -1) pushDown(k);
  int mid = (t[k].l + t[k].r) >> 1, lssum = t[ls].sum;
  if(t[ls].sum < cnt) update0(l, mid, ls, t[ls].sum), update0(mid+1, r, rs, cnt - lssum);
  else update0(l, mid, ls, cnt);
  pushUp(k);
}
void update1(int l, int r, int k, int cnt) {
  int lenk = t[k].r - t[k].l + 1;
  if(lenk - t[k].sum <= cnt) {
    t[k].sum = lenk;
    t[k].lazy = 1;
    return ;
  } if(t[k].lazy != -1) pushDown(k);
  int mid = (t[k].l + t[k].r) >> 1;
  int lenls = t[ls].r - t[ls].l + 1;
  int lssum = t[ls].sum;
  if(lenls - t[ls].sum < cnt)
    update1(l, mid, ls, lenls - t[ls].sum), update1(mid+1, r, rs, cnt-(lenls-lssum));
  else update1(l, mid, ls, cnt);
  pushUp(k);
}
bool query(int x, int k) {
  if(t[k].l == x && t[k].r == x)
    return t[k].sum;
  if(t[k].lazy != -1) pushDown(k);
  int mid = (t[k].l + t[k].r) >> 1;
  if(x <= mid) return query(x, ls);
  else return query(x, rs);
}
int main() {
  n = read(); m = read();
  build(1, n, 1); int mid = 1;
  for(int i = 1; i <= m; ++ i) {
    int opt = read(), p = read();
    if(opt == 0) {
      if(p < mid) continue;
      update0(1, n, 1, p - mid + 1);
      mid = p + 1;
    } else {
      if(p >= mid) continue;
      update1(1, n, 1, mid - p);
      mid = p;
    }
  } std :: vector <int> ans0, ans1;
  for(int i = 1; i <= n; ++ i)
    if(query(i, 1)) ans1.push_back(i);
    else ans0.push_back(i);
  for(int i = ans0.size() - 1; i >= 0; -- i) printf("%d ", ans0[i]);
  for(auto x : ans1) printf("%d ", x);
  return 0;
}