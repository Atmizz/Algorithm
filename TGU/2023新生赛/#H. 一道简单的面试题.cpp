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
const int MaxN = 10;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, k, ans[MaxN], pos[MaxN];
struct Node {
  int x, pos;
  friend bool operator < (Node a, Node b) {
    return a.x == b.x ? a.pos < b.pos : a.x < b.x;
  }
}a[MaxN], b[MaxN];
int main() {
  n = read(); k = read();
  for(int i = 1; i <= n; ++ i) a[i].x = read(), a[i].pos = i;
  for(int i = 1; i <= k; ++ i) b[i].x = read(), b[i].pos = i;
  if(k == 1) {
    for(int i = 1; i <= n; ++ i)
      if(a[i].x >= b[1].x) {
        printf("%d", i);
        return 0;
      }
    printf("-1");
    return 0;
  } if(n < k) {
    printf("-1");
    return 0;
  }
  std :: sort(b + 1, b + 1 + k);
  std :: sort(a + 1, a + 1 + n);
  int Index = 1;
  for(int i = 1; i <= k; ++ i) {
    // printf("%d %d\n", b[i].x, b[i].pos);
    if(a[Index].x >= b[i].x) {
      ans[b[i].pos] = a[Index].pos;
      pos[i] = Index;
      Index ++;
    } else {
      while(a[Index].x < b[i].x && Index <= n) Index ++;
      if(Index > n) {
        printf("-1");
        return 0;
      } 
      ans[b[i].pos] = a[Index].pos;
      pos[i] = Index;
      Index ++;
    }
    if(Index > n && i != k) {
      printf("-1");
      return 0;
    }
  }
  while(1) {
    bool Ok = true;
    for(int i = k; i >= 1; -- i)
      for(int j = k; j >= 1; -- j)
        if(i != j)
          if(b[i].x <= a[pos[j]].x && b[j].x <= a[pos[i]].x) {
            if(b[j].pos < b[i].pos && a[pos[j]].pos > a[pos[i]].pos)
              Ok = false, std :: swap(ans[b[i].pos], ans[b[j].pos]), std :: swap(pos[i], pos[j]);
            if(b[j].pos > b[i].pos && a[pos[j]].pos < a[pos[i]].pos)
              Ok = false, std :: swap(ans[b[i].pos], ans[b[j].pos]), std :: swap(pos[i], pos[j]);
          }
    if(Ok) break;
  }
  for(int i = 1; i <= k; ++ i)
    printf("%d ", ans[i]);
  return 0;
}