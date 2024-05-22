#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
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
const int MaxN = 2e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int a[MaxN>>1], n, m, p, c;
struct Segment_Tree {
  struct Node {
    int l, r, sum, lazy;
  }t[MaxN];
  void Push_Up(int k) { t[k].sum = (t[ls].sum + t[rs].sum) % p;}
  void Push_Down(int k) {
    t[ls].lazy = (t[ls].lazy + t[k].lazy) % p; t[rs].lazy = (t[rs].lazy + t[k].lazy) % p;
    t[ls].sum = (t[ls].sum + t[k].lazy * (t[ls].r - t[ls].l + 1)) % p;
    t[rs].sum = (t[rs].sum + t[k].lazy * (t[rs].r - t[rs].l + 1)) % p;
    t[k].lazy = 0;
  }
  void Build_A_Nice_Segment_Tree(int l, int r, int k) {
    t[k].l = l; t[k].r = r;
    if(l == r) {
      t[k].sum = a[l]; return ;
    }
    int mid = (l + r) >> 1;
    Build_A_Nice_Segment_Tree(l, mid, ls);
    Build_A_Nice_Segment_Tree(mid+1, r, rs);
    Push_Up(k);
  }
  void Modify(int l, int r, int k, int z, int x) {
    if(t[k].l >= l && t[k].r <= r) {
      t[k].lazy = (t[k].lazy - x + p) % p;
      t[k].lazy = (t[k].lazy + z) % p;
      t[k].sum = (t[k].sum - x * (t[k].r - t[k].l + 1) + p) % p;
      t[k].sum = (t[k].sum + z * (t[k].r - t[k].l + 1)) % p;
      if(t[k].l == t[k].r) a[l] = z;
      return ;
    }
    if(t[k].lazy) Push_Down(k);
    int mid = (t[k].l + t[k].r) >> 1;
    if(l <= mid) Modify(l, r, ls, z, x);
    if(r > mid) Modify(l, r, rs, z, x);
    Push_Up(k);
  }
  int Query(int l, int r, int k) {
    if(t[k].l >= l && t[k].r <= r) return t[k].sum % p;
    if(t[k].lazy) Push_Down(k);
    int mid = (t[k].l + t[k].r) >> 1, Sum = 0;
    if(l <= mid) Sum = (Sum + Query(l, r, ls)) % p;
    if(r > mid) Sum = (Sum + Query(l, r, rs)) % p;
    return Sum % p;
  }
}T;
int Pow(int a, int b) {
  int sum = 1;
  while(b) {
    if(b & 1) sum = (sum * a) % p;
    a = (a * a) % p; b >>= 1;
  } return sum % p;
}
int Phi(int x) {
  int phi = x;
  for(int i = 2; i * i <= x; ++ i)
    if(!(x % i)) {
      phi = phi - phi / i;
      while(!(x % i)) x /= i;
    }
  if(x > 1) phi = phi - phi / x;
  return phi;
}
int main() {
  n = read(), m = read(), p = read(), c = read();
  int phi = Phi(p);
  for(int i = 1; i <= n; ++ i) a[i] = read();
  T.Build_A_Nice_Segment_Tree(1, n, 1);
  for(int i = 1; i <= m; ++ i) {
    int opt = read(), l = read(), r = read();
    if(!opt)
      for(int j = l; j <= r; ++ j)
        if(a[j] < phi) T.Modify(j, j, 1, Pow(c, a[j])%p, a[j]);
        else T.Modify(j, j, 1, Pow(c, a[j]%phi + phi)%p, a[j]);
    else printf("%d\n", T.Query(l, r, 1) % p);
  }
  return 0;
}
/*
4 4 7 2
1 2 3 4
0 1 4
1 2 4
0 1 4
1 1 3


1  1 2 3 4 
2  2 4 8 16
2  2 4 1 2
3  4 16 2 4
3  4 2 2 4
3  4 16 256 256
276 % 7 = 3

2  2 4 1 2

3  4 16 2 4
3  4 2 2 4



*/