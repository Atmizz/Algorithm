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
const int MaxN = 13;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, Set[MaxN], ans, sum;
void dfs(int x, int id) {
  if(x > sum) return ;
//  printf("x : %d x & sum %d\n", x, x & sum);
  if((x & sum) == sum) ans ++;
  for(int i = id + 1; i <= m; ++ i)
    dfs(x | Set[i], i);
}
int main() {
  n = read(); m = read();
  sum = (1 << n) - 1;
//  printf("sum %d\n", sum);
  for(int i = 1; i <= m; ++ i) {
    int x = read(), y;
    for(int j = 1; j <= x; ++ j)
      y = read(), Set[i] = Set[i] + (1 << y - 1);
//    printf("id %d Set %d\n", i, Set[i]);
  }
  for(int i = 1; i <= m; ++ i)
    dfs(Set[i], i);
  printf("%d", ans);
  return 0;
}