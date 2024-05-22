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
int n, k, h[MaxN], w[MaxN], ans;
bool check(int x) {
  int sum = 0;
  for(int i = 1; i <= n; ++ i)
    sum += ((h[i] / x) * (w[i] / x));
  if(sum >= k) return true;
  return false;
}
int main() {
  n = read(), k = read();
  for(int i = 1; i <= n; ++ i)
    h[i] = read(), w[i] = read();
  int l = 1, r = 1e5, mid;
  while(l <= r) {
    mid = (l + r) >> 1;
    if(check(mid)) l = mid + 1, ans = l - 1;
    else r = mid - 1;
  } printf("%d", ans);
  return 0;
}