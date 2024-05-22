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
int n, cnt, m;
ll X[MaxN<<1];
struct scanLine {
  ll l, r, h;
  int mark;
  friend bool operator < (scanLine a, scanLine b) {
    return a.h < b.h;
  }
}line[MaxN<<2];
struct scanTree {
  int l, r, sum;
  ll len;
}t[MaxN<<2];
void pushUp(int k) {
  if(t[k].sum) t[k].len = X[t[k].r+1] - X[t[k].l];
  else t[k].len = t[ls].len + t[rs].len;
}
void buildTree(int l, int r, int k) {
  t[k].l = l; t[k].r = r;
  t[k].len = t[k].sum = 0;
  if(l == r) return ;
  int mid = (l + r) >> 1;
  buildTree(l, mid, ls);
  buildTree(mid+1, r, rs);
}
void updateTree(ll l, ll r, int k, int mark) {
  // if(X[t[k].r+1] <= l || X[t[k].l] >= r) return ;
  if(X[t[k].l] >= l && X[t[k].r+1] <= r) {
    t[k].sum += mark;
    pushUp(k);
    return ;
  }
  if(l >= X[t[k].l]) {
    updateTree(l, r, ls, mark);
  }
  if(r <= X[t[k].r+1]) {
    updateTree(l, r, rs, mark);
  }
  pushUp(k);
}
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) {
    int x_1 = read(), y_1 = read(), x_2 = read(), y_2 = read();
    X[++m] = x_1; line[m] = {x_1, x_2, y_1, 1};
    X[++m] = x_2; line[m] = {x_1, x_2, y_2, -1};
  }
  std :: sort(line + 1, line + 1 + m);
  std :: sort(X + 1, X + 1 + m);
  m = std :: unique(X + 1, X + 1 + m) - X - 1;
  buildTree(1, m - 1, 1);
  ll ans = 0;
  for(int i = 1; i < n << 1; ++ i) {
    updateTree(line[i].l, line[i].r, 1, line[i].mark);
    ans += t[1].len * (line[i+1].h - line[i].h);
  }
  printf("%lld", ans);
  return 0;
}