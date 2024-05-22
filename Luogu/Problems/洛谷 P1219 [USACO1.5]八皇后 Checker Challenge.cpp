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
const int MaxN = 15;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, cnt;
bool map[MaxN][MaxN], vis[MaxN];
bool Check(int xx, int yy) {
  int x = xx, y = yy;
  while(x >= 1 && y >= 1) {
    if(map[x][y]) return true;
    x --; y --;
  } x = xx; y = yy;
  while(x >= 1 && y <= n) {
    if(map[x][y]) return true;
    x --, y ++;
  } return false;
}
void dfs(int step, int ans[]) {
  if(step == n) {
    if(cnt < 3) {
      for(int i = 1; i <= n; ++ i) printf("%d ", ans[i]);
      puts("");
    }
    cnt ++; return ;
  }
  for(int i = 1; i <= n; ++ i)
    if(vis[i] || Check(step + 1, i)) continue;
    else step ++, map[step][i] = 1, vis[i] = 1, ans[step] = i, dfs(step, ans), map[step][i] = 0, vis[i] = 0;
}
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) {
    int ans[MaxN]; ans[1] = i;
    map[1][i] = 1, vis[i] = 1, dfs(1, ans), map[1][i] = 0, vis[i] = 0;
  } printf("%d", cnt);
  return 0;
}