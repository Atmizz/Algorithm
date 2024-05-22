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
const int MaxN = 1e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
ll T, n, k;
int a[MaxN];
void dfs(int l, int r) {
  if(l + 1 == r) {
    std :: swap(a[l], a[r]);
    return ;
  } dfs(l, r-1); dfs(l+1, r);
}
int main() {
  T = read();
  while(T --) {
    n = read();
    memset(a, 0, sizeof a);
    for(int i = 1; i <= n; ++ i) a[i] = i;
    dfs(1, n);
    for(int i = 1; i <= n; ++ i)
      printf("%d ", a[i]);
    puts("");
  }
  return 0;
}