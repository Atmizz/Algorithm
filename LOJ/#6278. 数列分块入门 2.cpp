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
const int Mod = 1e9 + 7;
const int INF = 2147483647;
const int MaxN = 5e4 + 200;
ll n, a[MaxN], b[MaxN], block, blk[MaxN];
std :: vector <ll> g[MaxN];
void Sort(int x) {
  g[x].clear();
  for(int i = (x - 1) * block + 1; i <= x * block; ++ i)
    g[x].push_back(a[i]);
  std :: sort(g[x].begin(), g[x].end());
}
void add(int l, int r, int c) {
  for(int i = l; i <= min(r, blk[l] * block); ++ i) a[i] += c;
  Sort(blk[l]);
  if(blk[l] != blk[r]) {
    for(int i = (blk[r] - 1) * block + 1; i <= r; ++ i)
      a[i] += c;
    Sort(blk[r]);
  }
  for(int i = blk[l] + 1; i <= blk[r] - 1; ++ i)
    b[i] += c;
}
int query(int l , int r, int c) {
  int sum = 0;
  for(int i = l; i <= min(r, blk[l] * block); ++ i)
    if(a[i] + b[blk[l]] < c) sum ++;
  if(blk[l] != blk[r])
    for(int i = (blk[r] - 1) * block + 1; i <= r; ++ i)
      if(a[i] + b[blk[r]] < c) sum ++;
  for(int i = blk[l] + 1; i <= blk[r] - 1; ++ i)
    sum += std :: lower_bound(g[i].begin(), g[i].end(), c - b[i]) - g[i].begin();
  return sum;
}
int main() {
  n = read(); block = sqrt(n);
  for(int i = 1; i <= n; ++ i)
    blk[i] = (i - 1) / block + 1, a[i] = read(), g[blk[i]].push_back(a[i]);
  for(int i = 1; i <= blk[n]; ++ i)
    std :: sort(g[i].begin(), g[i].end());
  for(int i = 1; i <= n; ++ i) {
    ll opt = read(), l = read(), r = read(), c = read();
    if(opt == 0) add(l, r, c);
    else printf("%d\n", query(l, r, c * c));
  }
  return 0;
}