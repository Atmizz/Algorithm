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
int n, ans;
struct Node {
  int Exer, Finish;
  friend bool operator < (Node a, Node b) {
    return a.Finish < b.Finish;
  }
}a[MaxN];
bool check(int x) {
  for(int i = 1; i <= n; ++ i)
    if(x + a[i].Exer <= a[i].Finish) x += a[i].Exer;
    else return false;
  return true;
}
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i)
    a[i].Exer = read(), a[i].Finish = read();
  std :: sort(a + 1, a + 1 + n);
  int l = 1, r = 1e9 + 1, mid;
  while(l <= r) {
    mid = (l + r) >> 1;
    if(check(mid)) l = l + 1, ans = l - 1;
    else r = mid - 1;
  } if(!ans) printf("%d", -1);
  else printf("%d", ans);
  return 0;
}