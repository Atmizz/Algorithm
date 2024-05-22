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
const int MaxN = 1e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, a[MaxN], ans;
bool Is_Prime(int x) {
  for(int i = 2; i <= sqrt(x); ++ i)
    if(x % i == 0) return false;
  return true;
}
void dfs(int x, int step, int s) {
  if(step == m) {
    if(Is_Prime(s)) ans ++;
    return ;
  }
  for(int i = x + 1; i <= n; ++ i)
    dfs(i, step + 1, s + a[i]);
}
int main() {
  n = read(), m = read();
  for(int i = 1; i <= n; ++ i)
    a[i] = read();
  for(int i = 1; i <= n - m + 1; ++ i)
    dfs(i, 1, a[i]);
  printf("%d", ans);
  return 0;
}