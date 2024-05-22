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
#define ll long long
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
const int MaxN = 2e5+20;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, k, f[MaxN][22];
int query(int l, int r) {
  int o = 0;
  while((1<<(o+1)) <= r - l + 1) o ++;
  return max(f[l][o], f[r-(1<<o)+1][o]);
}
bool check(int x) {
  int sum = 0, K = n / x;
  for(int i = 0; i < x; ++ i)
    sum += query(i * K + 1, K * (i + 1));
  if(sum > k) return true;
  return false;
}
int main() {
  while(1) {
    n = read(); k = read();
    if(n == -1) break;
    memset(f, 0, sizeof f);
    int Sum = 0;
    for(int i = 1; i <= n; ++ i) f[i][0] = read(), Sum += f[i][0];
    if(Sum <= k) {printf("-1\n"); continue;}
    for(int j = 1; j <= 21; ++ j)
      for(int i = 1; i + (1 << j) - 1 <= n; ++ i)
        f[i][j] = max(f[i][j-1], f[i+(1<<(j-1))][j-1]);
    int l = 1, r = n, mid;
    while(l < r) {
      mid = (l + r) >> 1;
      if(check(mid)) r = mid;
      else l = mid + 1;
    }
    printf("%d\n", l);
  }
  return 0;
}