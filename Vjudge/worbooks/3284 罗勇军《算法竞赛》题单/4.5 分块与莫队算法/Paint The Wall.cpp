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
int n, m, a[MaxN], b[MaxN], block, blk[MaxN];
std :: map<int, int> cnt[MaxN];
void pd(int x) {
  if(b[blk[x]] == -1) return ;
  cnt[blk[x]].clear();
  for(int i = (blk[x] - 1) * block + 1; i <= blk[x] * block; ++ i)
    a[i] = b[blk[x]];
  cnt[blk[x]][b[blk[x]]] = block;
  b[blk[x]] = -1;
}
void Modify(int l, int r, int x) {
  pd(l);
  for(int i = l; i <= min(blk[l] * block, r); ++ i)
    cnt[blk[l]][a[i]] --, cnt[blk[l]][x] ++, a[i] = x;
  if(blk[l] != blk[r]) {
    pd(r);
    for(int i = (blk[r] - 1) * block + 1; i <= r; ++ i)
      cnt[blk[r]][a[i]] --, cnt[blk[r]][x] ++, a[i] = x;
  }
  for(int i = blk[l] + 1; i <= blk[r] - 1; ++ i)
    b[i] = x;
}
int query(int l, int r, int x) {
  int sum = 0;
  pd(l);
  for(int i = l; i <= min(blk[l] * block, r); ++ i)
    if(a[i] == x) sum ++;
  if(blk[l] != blk[r]) {
    pd(r);
    for(int i = (blk[r] - 1) * block + 1; i <= r; ++ i)
      if(a[i] == x) sum ++;
  }
  for(int i = blk[l] + 1; i <= blk[r] - 1; ++ i)
    if(b[i] == x) sum += block;
    else if(b[i] == -1 && cnt[i].find(x) != cnt[i].end()) sum += cnt[i][x];
  return sum;
}
int main() {
  while(~scanf("%d %d", &n, &m)) {
    block = sqrt(n);
    for(int i = 1; i <= n; ++ i) a[i] = read(), blk[i] = (i - 1) / block + 1;
    for(int i = 1; i <= blk[n]; ++ i) b[i] = -1, cnt[i].clear();
    for(int i = 1; i <= n; ++ i) cnt[blk[i]][a[i]] ++;
    for(int i = 1; i <= m; ++ i) {
      int opt = read(), l = read(), r = read(), z = read();
      l ++, r ++;
      if(opt == 1) Modify(l, r, z);
      else printf("%d\n", query(l, r, z));
    }
  }
  return 0;
}